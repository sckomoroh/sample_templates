#include "InitialState.h"

InitialState::InitialState(const std::shared_ptr<IDevice>& device)
    : StateBase{device}
{
}

EStateId InitialState::process(EEventID eventId, bool isActive)
{
    printf("[InitialState::process] Process. Event ID: %d, Is active = %s\n", (int)eventId,
           isActive ? "true" : "false");

    auto nextState = getStateId();

    if (isActive && eventId == EEventID::Initializing) {
        if (initialize()) {
            nextState = EStateId::Initialization;
        }
        else {
            printf("[InitialState::process] Initialization failed\n");
        }
    }
    else {
        printf("[InitialState::process] Invalid transition\n");
    }

    return nextState;
}

EStateId InitialState::getStateId() const { return EStateId::Initial; }

bool InitialState::initialize()
{
    printf("[InitialState::initialize] Initialize\n");
    return mDevice->initialize();
}
