//
// Created by yzvihunov on 8/27/19.
//

#include "InitializationState.h"

InitializationState::InitializationState(IDevice& device)
    : StateBase{device}
{
}

EStateId InitializationState::process(EEventID eventId, bool isActive)
{
    printf("[InitializationState::process] Process. Event ID: %d, Is active = %s\n", (int)eventId,
           (isActive ? "true" : "false"));

    EStateId nextStateId = getStateId();

    if (isActive) {
        do {
            if (eventId != EEventID::Open) {
                printf("[InitializationState::process] Transition to %d not supported\n",
                       (int)eventId);
                break;
            }

            if (!open()) {
                printf("[InitializationState::process] Open failed\n");
                break;
            }

            nextStateId = EStateId::Opened;
        } while (false);
    }
    else {
        if (shutdown()) {
            nextStateId = EStateId::ShutDown;
        }
        else {
            printf("[InitializationState::process] Shutdown failed\n");
        }
    }

    return nextStateId;
}

EStateId InitializationState::getStateId() const { return EStateId::Initialization; }

bool InitializationState::open()
{
    printf("[InitializationState::open] Open device\n");
    return mDevice.open();
}

bool InitializationState::shutdown()
{
    printf("[InitializationState::shutdown] Open device\n");
    return mDevice.shutdown();
}
