#include <iostream>
#include <thread>
#include <vector>
#include <boost/filesystem.hpp>

#include "loadpackage.h"
#include "packagedb.h"

namespace fs = boost::filesystem;

namespace Indigo
{

    LoadPackage::LoadPackage(std::string packageName) :
        packageName_(packageName),
        pdb_(packageName, packageName + ".pdb")
    {
    }

    LoadPackage::~LoadPackage()
    {
    }

    bool LoadPackage::loadFromDir(const std::string &packagePath)
    {
        if (!fs::exists(packagePath) || !fs::is_directory(packagePath))
        {
            setError(std::string("can't open package at ") + packagePath);
            return false;
        }

        boost::filesystem::path someDir(packagePath);
        boost::filesystem::directory_iterator endIter;
        std::vector<fs::path> packageSources;

        for (boost::filesystem::directory_iterator dirIter(someDir) ; dirIter != endIter ; ++dirIter)
        {
            if (boost::filesystem::is_regular_file(dirIter->status()))
            {
                boost::filesystem::path path = dirIter->path();
                std::time_t updateTime = boost::filesystem::last_write_time(path);

                if (updateTime)
                packageSources.push_back(*dirIter);
                //result_set.insert(result_set_t::value_type(fs::last_write_time(dir_iter->path()), *dir_iter));
            }
        }

        return true;
    }

    bool LoadPackage::loadFromDb()
    {
        // Can we open an existing package database?
        if (pdb_.open())
        {
            return true;
        }

        return false;
    }

    void LoadPackage::run()
    {
        std::cout << "running load module: " << packageName_ << std::endl;

        if (!loadFromDb())
            loadFromDir(packageName_);

        std::cout << "package " << packageName_ << " loaded\n";
    }
}
