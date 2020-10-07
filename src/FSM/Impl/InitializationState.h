//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_STATE1_H
#define CODETEMPLATES_STATE1_H

#include "StateBase.h"

class InitializationState : public StateBase {
public:  // ctor
    InitializationState(const std::shared_ptr<IDevice>& device);

public:
    EStateId process(EEventID eventId, bool isActive) override;

    EStateId getStateId() const override;

private:
    bool open();
    bool shutdown();
};

#endif  // CODETEMPLATES_STATE1_H
