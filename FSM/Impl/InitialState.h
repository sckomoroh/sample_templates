#ifndef _InitialState_H_
#define _InitialState_H_

#include "IDevice.h"
#include "StateBase.h"

class InitialState : public StateBase {
public:  // ctor
    InitialState(IDevice& device);

public:
    EStateId process(EEventID eventId, bool isActive) override;

    EStateId getStateId() const override;

private:
    bool initialize();
};

#endif  // _InitialState_H_
