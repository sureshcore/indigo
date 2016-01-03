#ifndef INDIGO_SOURCECODE_H
#define INDIGO_SOURCECODE_H

#include <string>
#include <cstdint>
#include <cstddef>

namespace Indigo
{

    class SourceCode
    {
    private:
        std::string  fileName_;

        bool         isOpen_;
        std::string  errorString_;

#ifndef _WIN32
        uint8_t     *data_;
        size_t       length_;
        int          srcFileFd_;

#else // _WIN32
        std::string  source_;
#endif

    public:
        SourceCode(const std::string &fileName);
        ~SourceCode();

        bool         isOpen() const { return isOpen_; }
        std::string  error()  const { return errorString_; }

#ifdef _WIN32
        uint8_t     *data()   const { return source_.data(); }
        std::size_t  length() const { return source_.length(); }

#else // _WIN32
        uint8_t     *data()   const { return data_; }
        std::size_t  length() const { return length_; }
#endif

    private:
        void         load(const std::string &fileName);
        void         unload();

        void         setError(const std::string &err) { errorString_ = err; }
    };

}

#endif // INDIGO_SOURCECODE_H
