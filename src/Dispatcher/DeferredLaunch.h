#ifndef com_DeferredLaunch_H_
#define com_DeferredLaunch_H_

#include <chrono>
#include <functional>
#include <thread>
#include <tuple>

namespace com {
namespace dispatcher {

template <class... TArgs>
class DeferredLaunch {
public:
    virtual ~DeferredLaunch() = default;

public:
    template <class Rep, class Period>
    void launch(const std::chrono::duration<Rep, Period>& duration,
                std::function<void(TArgs...)> func,
                TArgs... args)
    {
        auto inputTime = std::chrono::system_clock::now().time_since_epoch();
        std::thread thread = std::thread([inputTime, duration, func, args...] {
            auto runTime = std::chrono::system_clock::now().time_since_epoch();
            auto waitDuration = duration - (runTime - inputTime);
            std::this_thread::sleep_for(waitDuration);
            func(args...);
        });
        thread.detach();
    }
};

}  // namespace dispatcher
}  // namespace com

#endif  // com_DeferredLaunch_H_
