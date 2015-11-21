#ifndef INDIGO_LOADMODULE_H
#define INDIGO_LOADMODULE_H

#include <string>

#include "pass.h"


namespace Indigo
{

    class LoadPackage : public Pass
    {
        std::string packageName_;

    public:
        LoadPackage(std::string packageName);
        ~LoadPackage();

        void run();
    };

}

#endif // INDIGO_LOADMODULE_H
