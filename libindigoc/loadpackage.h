#ifndef INDIGO_LOADMODULE_H
#define INDIGO_LOADMODULE_H

#include <string>

#include "pass.h"
#include "packagedb.h"


namespace Indigo
{
    class LoadPackage : public Pass
    {
        std::string packageName_;
        PackageDb   pdb_;
        std::string errorString_;

    private:
        bool loadFromDir(const std::string &packagePath);
        bool loadFromDb();
        void setError(std::string errorMessage) { errorString_ = errorMessage; }

    public:
        LoadPackage(std::string packageName);
        ~LoadPackage();

        void run();
    };

}

#endif // INDIGO_LOADMODULE_H
