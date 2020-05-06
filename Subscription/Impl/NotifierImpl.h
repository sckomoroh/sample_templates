//
// Created by yzvihunov on 8/23/19.
//

#ifndef CODETEMPLATES_NOTIFIERIMPL_H
#define CODETEMPLATES_NOTIFIERIMPL_H

#define DECLARE_NOTIFIER(name, method) using name = NotifierImpl<decltype(&method), &method>;

#include <functional>

#include "INotifier.h"
#include "SubscriberImpl.h"

template <class TFunc, TFunc func>
class NotifierImpl;

template <class TClass, class... TArgs, void (TClass::*func)(TArgs...)>
class NotifierImpl<void (TClass::*)(TArgs...), func>
    : public INotifier<TArgs...>
    , public SubscriberImpl<TClass> {
public:
    void notifyListener(TArgs... args) override
    {
        SubscriberImpl<TClass>::foreachListener(
            [&args...](TClass& item) { (item.*func)(args...); });
    }
};

#endif  // CODETEMPLATES_NOTIFIERIMPL_H
