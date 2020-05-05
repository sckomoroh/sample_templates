//
// Created by yzvihunov on 8/27/19.
//

#include "ClosedState.h"

EStateId ClosedState::process(EEventID eventId, bool isActive)
{
    printf("[ClosedState::process] Process. Event ID: %d, Is active = %s\n", eventId,
           isActive ? "true" : "false");

    EStateId nextStateId = getStateId();

    if (isActive) {
        do {
            if (eventId != EEventID::Open) {
                printf("[ClosedState::process] Transition to %d not supported\n", eventId);
                break;
            }

            if (!open()) {
                printf("[ClosedState::process] Open failed\n");
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
            printf("[ClosedState::process] Shutdown failed\n");
        }
    }

    return nextStateId;
}

EStateId ClosedState::getStateId() const { return EStateId::Closed; }

bool ClosedState::shutdown()
{
    printf("[ClosedState::shutdown] Shutdown\n");
    return mDevice.shutdown();
}

bool ClosedState::open()
{
    printf("[ClosedState::open] Open\n");
    return mDevice.open();
}
