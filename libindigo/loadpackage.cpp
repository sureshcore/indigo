#include <iostream>
#include <thread>
#include <boost/filesystem.hpp>

#include "loadpackage.h"
#include "packagedb.h"

namespace Indigo
{

    LoadPackage::LoadPackage(std::string packageName) :
        packageName_(packageName)
    {
    }

    LoadPackage::~LoadPackage()
    {
    }

    void LoadPackage::run()
    {
        std::cout << "running load module: " << packageName_ << std::endl;
        PackageDb pdb(packageName_, packageName_ + ".idb");
        std::cout << "package " << packageName_ << " loaded\n";
    }
}
