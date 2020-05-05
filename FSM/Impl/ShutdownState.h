#ifndef _ShutdownState_H_
#define _ShutdownState_H_

#include "StateBase.h"

class ShutdownState : public StateBase {
public:  // ctor
    ShutdownState(IDevice& device)
        : StateBase{device}
    {
    }

public:
    EStateId process(EEventID eventId, bool isActive) override;

    EStateId getStateId() const override;

private:
    bool initialize();
};

#endif  // _ShutdownState_H_
