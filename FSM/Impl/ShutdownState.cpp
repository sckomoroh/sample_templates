#include "ShutdownState.h"

EStateId ShutdownState::process(EEventID eventId, bool isActive)
{
    printf("[ShutdownState::process] Process. Event ID: %d, Is active = %s\n", eventId,
           isActive ? "true" : "false");

    auto nextState = getStateId();

    do {
        if (!isActive) {
            printf("[ShutdownState::process] Already shutdown\n");
            break;
        }

        if (eventId != EEventID::Initializing) {
            printf("[ShutdownState::process] Event not supported %d", eventId);
            break;
        }

        if (!initialize()) {
            printf("[ShutdownState::process] Initialization failed\n");
            break;
        }

        nextState = EStateId::Initialization;
    } while (false);

    return nextState;
}

EStateId ShutdownState::getStateId() const { return EStateId::ShutDown; }

bool ShutdownState::initialize()
{
    printf("[ShutdownState::initialize] Initialize\n");
    return mDevice.initialize();
}
