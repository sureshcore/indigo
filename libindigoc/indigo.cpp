#include <thread>
#include <iostream>
#include <vector>

#include "indigo.h"
#include "loadpackage.h"


namespace Indigo
{

    Indigo::Indigo()
    {
    }

    Indigo::~Indigo()
    {
    }

    void Indigo::startThreads()
    {
        scheduler_.startThreads();
    }

    void Indigo::stopThreads()
    {
        scheduler_.stopThreads();
    }

    void Indigo::waitComplete()
    {
        scheduler_.waitComplete();
    }

    void Indigo::loadPackage(const std::string &packageName)
    {
        scheduler_.addPass(std::make_shared<LoadPackage>(packageName));
    }
}
