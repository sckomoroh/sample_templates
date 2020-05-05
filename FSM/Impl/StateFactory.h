//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_STATEFACTORY_H
#define CODETEMPLATES_STATEFACTORY_H

#include "ClosedState.h"
#include "EStateId.h"
#include "IDevice.h"
#include "IStateFactory.h"
#include "InitializationState.h"
#include "OpenedState.h"

class StateFactory : public IStateFactory<EStateId, EEventID, bool> {
private:
    IDevice& mDevice;

public:
    StateFactory(IDevice& device)
        : mDevice{device}
    {
    }

    std::shared_ptr<IState<EStateId, EEventID, bool>> createState(EStateId stateId) const override
    {
        switch (stateId) {
        case EStateId::Initialization:
            return InitializationState::create<InitializationState>(mDevice);
        case EStateId::Opened:
            return OpenedState::create<OpenedState>(mDevice);
        case EStateId::Closed:
            return ClosedState::create<ClosedState>(mDevice);
        }

        return nullptr;
    }
};

#endif  // CODETEMPLATES_STATEFACTORY_H
