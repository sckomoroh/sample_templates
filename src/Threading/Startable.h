#ifndef com_Startable_H_
#define com_Startable_H_

#include <atomic>
#include <mutex>
#include <thread>

#include "IRunnable.h"
#include "IStartable.h"

namespace com {
namespace threading {

template <class... TArgs>
class Startable : public IStartable<TArgs...> {
private:
    IRunnable<Startable&, TArgs...>& _runnable;

    std::atomic_bool _running;
    std::atomic_bool _needStop;
    std::thread _thread;
    std::mutex _runMutex;

public:
    Startable(IRunnable<Startable&, TArgs...>& runnable)
        : _runnable{runnable}
    {
    }

    virtual ~Startable() { stop(); }

public:  //  IStartable
    void start(TArgs... args) override
    {
        std::lock_guard<std::mutex> lock{_runMutex};

        if (!_running) {
            _running = true;
            _needStop = false;
            _thread = std::thread([this, args...] { _runnable.run(*this, args...); });
        }
    }

    void stop() override
    {
        std::lock_guard<std::mutex> lock{_runMutex};

        if (_running) {
            _needStop = true;

            if (_thread.joinable()) {
                _thread.join();
            }

            _running = false;
        }
    }

    bool isStarted() const override { return _thread.joinable(); }

public:
    bool isNeedStop() { return _needStop; }
};

}  // namespace threading
}  // namespace com

#endif  // com_Startable_H_
