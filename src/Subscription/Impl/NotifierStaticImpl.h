//
// Created by yzvihunov on 8/28/19.
//

#ifndef CODETEMPLATES_NOTIFIERSTATICIMPL_H
#define CODETEMPLATES_NOTIFIERSTATICIMPL_H

#include "INotifier.h"
#include "SubscriberImpl.h"

template<class TFunc, TFunc func>
class NotifierStatisImpl;

template<class TClass, class ...TArgs, void(&func)(TClass&, TArgs...)>
class NotifierStatisImpl<void(&)(TClass&, TArgs...), func>
    : public INotifier<TArgs...>
    , public SubscriberImpl<TClass> {
public:
    void notifyListener(TArgs... args) override {
        SubscriberImpl<TClass>::foreachListener([&args...](TClass& item) {
            func(item, args...);
        });
    }
};

#endif //CODETEMPLATES_NOTIFIERSTATICIMPL_H
