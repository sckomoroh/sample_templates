//
// Created by yzvihunov on 8/28/19.
//

#ifndef CODETEMPLATES_NOTIFIERSTATICIMPL_H
#define CODETEMPLATES_NOTIFIERSTATICIMPL_H

#include "INotifier.h"
#include "SubscriberImpl.h"

template<class TThis, class TFunc, TFunc func, class ...TArgs>
class NotifierStaticImpl
    : public SubscriberImpl<TThis>
    , public INotifier<TArgs...> {

protected:
    using Notifier_t =  INotifier<TArgs...>;

public:
    void notifyListener(TArgs... args) const override {
        for (const auto& item : SubscriberImpl<TThis>::mListeners) {
            TThis* pThis = &(item.get());
            func(pThis, args...);
        }
    }
};

#endif //CODETEMPLATES_NOTIFIERSTATICIMPL_H
