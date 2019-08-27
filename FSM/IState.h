//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_ISTATE_H
#define CODETEMPLATES_ISTATE_H

#include "EStateId.h"

class IState {
public:
    virtual void complete() = 0;

    virtual int getValue() const = 0;

    virtual void update(int value) const = 0;

    virtual EStateId getStateId() const = 0;
};


#endif //CODETEMPLATES_ISTATE_H
