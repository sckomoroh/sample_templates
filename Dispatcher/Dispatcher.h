#ifndef com_Dispatcher_H_
#define com_Dispatcher_H_

#include <future>

#include "Common/IRunnable.h"
#include "Common/Startable.h"
#include "IDispatcherListener.h"
#include "Queue/IMessageQueue.h"
#include "Queue/MessageQueueBase.h"
#include "Subscription/ISubscriber.h"
#include "Subscription/Notifier.h"

using com::common::IRunnable;
using com::common::IStartable;
using com::common::Startable;
using com::queue::IMessageQueue;
using com::subscription::ISubscriber;
using com::subscription::Notifier;

namespace com {
namespace dispatcher {

template <class TMessage>
class Dispatcher
    : private IRunnable<Startable<>&>
    , public IStartable<>
    , public ISubscriber<IDispatcherListener<TMessage>> {
private:
    DECLARE_NOTIFIER(DispatcherNotifier, IDispatcherListener<TMessage>::onMessageAvailable);

private:
    Startable<> _startable;
    IMessageQueue<TMessage>& _queue;
    DispatcherNotifier _notifier;

public:
    Dispatcher(IMessageQueue<TMessage>& queue)
        : _startable{*this}
        , _queue{queue}
    {
    }

    virtual ~Dispatcher() = default;

public:  // IStartable
    void start() override { _startable.start(); }

    void stop() override { _startable.stop(); }

    bool isStarted() const override { return _startable.isStarted(); }

public:  // ISubscriber
    void subscribe(std::reference_wrapper<IDispatcherListener<TMessage>> listener) override
    {
        _notifier.subscribe(listener);
    }

    void unsubscribe(std::reference_wrapper<IDispatcherListener<TMessage>> listener) override
    {
        _notifier.unsubscribe(listener);
    }

private:  // IRunnable
    void run(Startable<>&) override
    {
        while (!_startable.isNeedStop()) {
            TMessage message;
            if (_queue.popMessage(message)) {
                _notifier.notifyListener(message);
            }
            else {
                break;
            }
        }
    }
};

}  // namespace dispatcher
}  // namespace com

#endif  // com_Dispatcher_H_
