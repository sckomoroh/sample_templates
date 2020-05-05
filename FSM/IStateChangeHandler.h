//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_ISTATELISTENER_H
#define CODETEMPLATES_ISTATELISTENER_H

template <class TStateId>
class IStateChangeHandler {
public:
    virtual void onStateChanged(TStateId stateId) = 0;
};

#endif  // CODETEMPLATES_ISTATELISTENER_H
