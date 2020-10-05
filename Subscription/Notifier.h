//
// Created by yzvihunov on 8/23/19.
//

#ifndef CODETEMPLATES_NOTIFIERIMPL_H
#define CODETEMPLATES_NOTIFIERIMPL_H

#define DECLARE_NOTIFIER(name, method) using name = Notifier<decltype(&method), &method>;

#include <functional>

#include "Subscriber.h"
#include "Subscription/INotifier.h"

namespace com {
namespace subscription {

template <class TFunc, TFunc func>
class Notifier;

template <class TClass, class... TArgs, void (TClass::*func)(TArgs...)>
class Notifier<void (TClass::*)(TArgs...), func>
    : public INotifier<TArgs...>
    , public Subscriber<TClass> {
public:
    void notifyListener(TArgs... args) override
    {
        Subscriber<TClass>::foreachListener([&args...](TClass& item) { (item.*func)(args...); });
    }
};

}  // namespace subscription
}  // namespace com

#endif  // CODETEMPLATES_NOTIFIERIMPL_H
