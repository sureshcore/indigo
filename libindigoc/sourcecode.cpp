#ifdef _WIN32
# include <iostream>
# include <fstream>
#else
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
#endif

#include "sourcecode.h"


namespace Indigo
{

    SourceCode::SourceCode(const std::string &fileName) :
        fileName_(fileName),
        isOpen_(false),
        data_(NULL),
        length_(0),
        srcFileFd_(-1)
    {
        load(fileName);
    }

    SourceCode::~SourceCode()
    {
        unload();
    }

#ifdef _WIN32
    // Use a conservative approach for windows - just read the file using fstream.
    void SourceCode::load(const std::string &fileName)
    {
        std::ifstream inFile{ fileName };
        isOpen_ = inFile.is_open();
        if (!isOpen_)
            return;

        using istritr = std::istream_iterator< std::string >;
        source_ { istritr { inFile }, istritr {} };
    }

    void SourceCode::unload()
    {
        isOpen_ = false;
        source_ = "";
    }
#else
    void SourceCode::load(const std::string &fileName)
    {
        // Close it just in case it's open already.
        unload();

        // Open the file.
        srcFileFd_ = open(fileName.c_str(), O_RDONLY);
        if (srcFileFd_ < 0)
        {
            setError(std::string{"can't open "} + fileName + ": " + strerror(errno));
            return;
        }

        // Get the length.
        struct stat srcInfo;
        if (fstat(srcFileFd_, &srcInfo) < 0)
        {
            setError(std::string{"can't get "} + fileName + " info: " + strerror(errno));
            return;
        }

        length_ = srcInfo.st_size;

        // Map the file in to memory.
        data_ = reinterpret_cast<uint8_t *>(mmap(NULL, length_, PROT_READ, MAP_PRIVATE, srcFileFd_, 0));
        if (data_ == MAP_FAILED)
        {
            setError(std::string{"can't mmap "} + fileName + ": " + strerror(errno));
            return;
        }

        // Success.
        isOpen_ = true;
    }

    void SourceCode::unload()
    {
        if (data_ != NULL)
        {
            munmap(data_, length_);
            data_ = NULL;
        }

        if (srcFileFd_ >= 0)
        {
            close(srcFileFd_);
            srcFileFd_ = -1;
        }

        isOpen_ = false;
    }
#endif

}
