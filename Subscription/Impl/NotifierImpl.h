//
// Created by yzvihunov on 8/23/19.
//

#ifndef CODETEMPLATES_NOTIFIERIMPL_H
#define CODETEMPLATES_NOTIFIERIMPL_H

#include <functional>

#include "INotifier.h"
#include "SubscriberImpl.h"

template<class TThis, class TFunc, TFunc func, class ...TArgs>
class NotifierImpl
        : public SubscriberImpl<TThis>
        , public INotifier<TThis, TFunc, func, TArgs...> {
protected:
    using Notifier_t =  INotifier<TThis, TFunc, func, TArgs...>;

public:
    void notifyListener(TArgs... args) const override {
        for (const auto& item : SubscriberImpl<TThis>::mListeners) {
            TThis* pThis = &(item.get());
            (pThis->*func)(args...);
        }
    }
};


#endif //CODETEMPLATES_NOTIFIERIMPL_H
