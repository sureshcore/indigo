#ifndef INDIGO_INDIGO_H
#define INDIGO_INDIGO_H

#include <thread>
#include <vector>

#include "scheduler.h"

namespace Indigo
{
    class Indigo
    {
        Scheduler scheduler_;

    public:
        Indigo();
        ~Indigo();

        void startThreads();
        void stopThreads();
        void waitComplete();

        void loadPackage(const std::string &packageName);
    };
}

#endif // INDIGO_INDIGO_H
