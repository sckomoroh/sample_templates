//
// Created by yzvihunov on 8/27/19.
//

#include "OpenedState.h"

OpenedState::OpenedState(IDevice& device)
    : StateBase{device}
{
}

EStateId OpenedState::process(EEventID eventId, bool isActive)
{
    printf("[OpenedState::process] Process. Event ID: %d, Is active = %s\n", eventId,
           isActive ? "true" : "false");

    EStateId nextStateId = getStateId();

    if (isActive) {
        do {
            if (eventId != EEventID::Close) {
                printf("[OpenedState::process] Transition to %d not supported\n", eventId);
                break;
            }
            if (!close()) {
                printf("[OpenedState::process] Close failed\n");
                break;
            }

            nextStateId = EStateId::Closed;
        } while (false);
    }
    else {
        if (shutdown()) {
            nextStateId = EStateId::ShutDown;
        }
        else {
            printf("[OpenedState::process] Shutdown failed\n");
        }
    }

    return nextStateId;
}

EStateId OpenedState::getStateId() const { return EStateId::Opened; }

bool OpenedState::close()
{
    printf("[OpenedState::close] Close\n");

    return mDevice.close();
}

bool OpenedState::shutdown()
{
    printf("[OpenedState::shutdown] Shutdown\n");

    return mDevice.shutdown();
}
