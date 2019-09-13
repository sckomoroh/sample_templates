//
// Created by yzvihunov on 8/23/19.
//

#ifndef CODETEMPLATES_SUBSCRIBERIMPL_H
#define CODETEMPLATES_SUBSCRIBERIMPL_H

#include <algorithm>
#include <functional>
#include <list>

#include "ISubscriber.h"

template<class TListener>
class SubscriberImpl : public ISubscriber<TListener> {
private:
    std::list<std::reference_wrapper<TListener>> mListeners;

public:
    void subscribe(std::reference_wrapper<TListener> listener) override {
        auto iter = std::find_if(
                mListeners.begin(),
                mListeners.end(),
                [&listener](std::reference_wrapper<TListener> item) {
                    return &item == &listener;
                });
        if (iter == mListeners.end()) {
            mListeners.push_back( { listener } );
        }
    }

    void unsubscribe(std::reference_wrapper<TListener> listener) override {
        auto iter = std::find_if(
                mListeners.begin(),
                mListeners.end(),
                [&listener](std::reference_wrapper<TListener> item) {
                    return &listener == &item;
                });
        if (iter != mListeners.end()) {
            mListeners.erase(iter);
        }
    }

protected:
    void foreachListener(std::function<void(TListener&)> itemFunc) {
        for (const auto& item : mListeners) {
            itemFunc(item.get());
        }
    }
};


#endif //CODETEMPLATES_SUBSCRIBERIMPL_H
