//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_STATEFACTORY_H
#define CODETEMPLATES_STATEFACTORY_H

#include "ClosedState.h"
#include "EStateId.h"
#include "FSM/IStateFactory.h"
#include "FSM/external/IDevice.h"
#include "InitialState.h"
#include "InitializationState.h"
#include "OpenedState.h"
#include "ShutdownState.h"

using com::fsm::IStateFactory;

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
            return StateBase::create<InitializationState, IDevice&>(mDevice);
        case EStateId::Opened:
            return StateBase::create<OpenedState, IDevice&>(mDevice);
        case EStateId::Closed:
            return StateBase::create<ClosedState, IDevice&>(mDevice);
        case EStateId::ShutDown:
            return StateBase::create<ShutdownState, IDevice&>(mDevice);
        case EStateId::Initial:
            return StateBase::create<InitialState, IDevice&>(mDevice);
        }

        return nullptr;
    }
};

#endif  // CODETEMPLATES_STATEFACTORY_H
