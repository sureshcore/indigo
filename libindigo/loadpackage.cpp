#include <iostream>
#include <thread>
#include <boost/filesystem.hpp>

#include "loadpackage.h"


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
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "package " << packageName_ << " loaded\n";
    }
}
