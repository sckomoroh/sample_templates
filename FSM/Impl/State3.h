//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_STATE3_H
#define CODETEMPLATES_STATE3_H

#include "IState.h"

class State3 : public IState {
public:
    void complete() override;

    int getValue() const override;

    void update(int value) const override;

    EStateId getStateId() const override;
};


#endif //CODETEMPLATES_STATE3_H
