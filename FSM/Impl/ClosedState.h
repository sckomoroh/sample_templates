//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_STATE3_H
#define CODETEMPLATES_STATE3_H

#include "StateBase.h"

class ClosedState : public StateBase {
public:  // ctor
    ClosedState(IDevice& device)
        : StateBase{device}
    {
    }

public:
    EStateId process(EEventID eventId, bool isActive) override;

    EStateId getStateId() const override;

private:
    bool shutdown();
    bool open();
};

#endif  // CODETEMPLATES_STATE3_H
