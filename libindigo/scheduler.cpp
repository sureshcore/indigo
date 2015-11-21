#include <iostream>
#include <thread>

#include "scheduler.h"
#include "pass.h"


namespace Indigo
{

    Scheduler::Scheduler() :
        threadsBusy_(0),
        threadsRunning_(0),
        terminate_(false)
    {

    }


    Scheduler::~Scheduler()
    {
    }


    void Scheduler::startThreads()
    {
        unsigned int cores = std::thread::hardware_concurrency();
        unsigned int numThreads = cores * 3 / 2;

        std::cout << "cores=" << cores << ", numThreads=" << numThreads << std::endl;

        std::lock_guard<std::mutex> guard(queueLock_);
        terminate_ = false;
        threads_.reserve(numThreads);
        running_.reserve(numThreads);

        for (unsigned int i = 0; i < numThreads; i++)
        {
            threads_.emplace_back(&Scheduler::runner, this, i);
        }

        threadsRunning_ = numThreads;
        threadsBusy_ = 0;
    }


    void Scheduler::stopThreads()
    {
        // Tell everything to stop.
        std::lock_guard<std::mutex> guard(queueLock_);
        terminate_ = true;
        readyToRun_.notify_all();
    }


    void Scheduler::waitComplete()
    {
        std::unique_lock<std::mutex> uqLock(queueLock_);

        // Any threads left?
        while (threadsRunning_ > 0)
        {
            // Wait for the threads to terminate.
            complete_.wait(uqLock);
        }

        // Join all the threads.
        for (std::thread &th: threads_)
        {
            th.join();
        }
    }


    void Scheduler::addPass(std::shared_ptr<Pass> pass)
    {
        std::lock_guard<std::mutex> guard(queueLock_);
        ready_.push(pass);
        readyToRun_.notify_one();
    }


#if 0
    void Scheduler::makePassReady(std::shared_ptr<Pass> pass)
    {
        waiting_.pop_back(XXX);
        ready_.push_front(XXX);
        readyToRun.notify_one();
    }
#endif


    void Scheduler::runner(int threadId)
    {
        std::cout << "this is a batch runner for thread " << threadId << std::endl;

        bool terminate = false;
        while (!terminate)
        {
            std::shared_ptr<Pass> nextPass;

            // Get the next pass from the ready queue. Wait if we have to.
            {
                std::unique_lock<std::mutex> uqLock(queueLock_);

                // Any work waiting?
                while (ready_.empty() && !terminate_)
                {
                    // There's nothing ready to go - wait for something.
                    std::cout << "thread " << threadId << " waiting\n";
                    readyToRun_.wait(uqLock);
                }

                // Are we done?
                if (terminate_)
                {
                    terminate = true;
                }
                else
                {
                    // Get the next pass.
                    nextPass = ready_.top();
                    ready_.pop();
                }
            }

            // Now the queue lock is unlocked. If we got a pass, run it.
            if (nextPass && !terminate)
            {
                std::cout << "thread " << threadId << "running job\n";
                // Keep a count of the number of busy threads.
                {
                    std::lock_guard<std::mutex> guard(queueLock_);
                    threadsBusy_++;
                }

                // Run a pass.
                nextPass->run();

                // If we're the last pass shut down the scheduler.
                {
                    std::lock_guard<std::mutex> guard(queueLock_);
                    threadsBusy_--;
                    if (threadsBusy_ == 0 && ready_.empty())
                    {
                        // We've finished everything we can.
                        terminate_ = true;
                        readyToRun_.notify_all();
                        if (!waiting_.empty())
                        {
                            std::cout << "warning: terminating with " << waiting_.size() << " passes incomplete\n";
                        }
                    }
                }
            }
        }

        std::cout << "batch runner for thread " << threadId << " done\n";
        {
            std::unique_lock<std::mutex> uqLock(queueLock_);
            threadsRunning_--;
            if (threadsRunning_ == 0)
                complete_.notify_all();
        }
    }

}
