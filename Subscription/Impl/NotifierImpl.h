//
// Created by yzvihunov on 8/23/19.
//

#ifndef CODETEMPLATES_NOTIFIERIMPL_H
#define CODETEMPLATES_NOTIFIERIMPL_H

#include "INotifier.h"
#include "SubscriberImpl.h"

template<class TListener, class ...TArgs>
class NotifierImpl
        : SubscriberImpl<TListener>
        , public INotifier<TArgs...> {
public:
    void notify(TArgs... args) const override {
        for (const auto& item : SubscriberImpl<TListener>::mListeners) {
            item.get().onNotify(args...);
        }
    }
};


#endif //CODETEMPLATES_NOTIFIERIMPL_H
