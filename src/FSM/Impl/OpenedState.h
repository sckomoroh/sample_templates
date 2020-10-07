//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_STATE2_H
#define CODETEMPLATES_STATE2_H

#include "StateBase.h"

class OpenedState : public StateBase {
public:  // ctor
    OpenedState(const std::shared_ptr<IDevice>& device);

public:
    EStateId process(EEventID eventId, bool isActive) override;

    EStateId getStateId() const override;

private:
    bool close();
    bool shutdown();
};

#endif  // CODETEMPLATES_STATE2_H
