#ifndef INDIGO_SCHEDULER_H
#define INDIGO_SCHEDULER_H

#include <thread>
#include <vector>
#include <stack>
#include <memory>
#include <mutex>
#include <condition_variable>


namespace Indigo
{

    class Pass;

    class Scheduler
    {
    private:
        // The threads and their currently running passes.
        std::vector<std::thread>             threads_;
        std::vector< std::shared_ptr<Pass> > running_;
        int                                  threadsBusy_;
        int                                  threadsRunning_;

        // A queue of passes which are ready to run and ones which are waiting
        // for some condition to be fulfilled before running.
        std::stack< std::shared_ptr<Pass> >  ready_;
        std::vector< std::shared_ptr<Pass> > waiting_;

        // These control multi-threaded access to the class.
        volatile bool                        terminate_;
        std::mutex                           queueLock_;
        std::condition_variable              readyToRun_;
        std::condition_variable              complete_;

    private:
        // Each thread runs this until it's finished.
        void runner(int threadId);

    public:
        Scheduler();
        ~Scheduler();

        void startThreads();
        void stopThreads();
        void waitComplete();

        void addPass(std::shared_ptr<Pass> newPass);
    };

}

#endif // INDIGO_SCHEDULER_H
