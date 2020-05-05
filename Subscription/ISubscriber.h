//
// Created by yzvihunov on 8/23/19.
//

#ifndef CODETEMPLATES_ISUBSCRIBER_H
#define CODETEMPLATES_ISUBSCRIBER_H

#include <functional>

template <class TListener>
class ISubscriber {
public:
    virtual void subscribe(std::reference_wrapper<TListener> listener) = 0;

    virtual void unsubscribe(std::reference_wrapper<TListener> listener) = 0;
};

#endif  // CODETEMPLATES_ISUBSCRIBER_H
