//
// Created by yzvihunov on 8/27/19.
//

#include "StateMachine.h"

StateMachine::StateMachine(IStateFactory<EStateId, EEventID, bool>& stateFactory,
                           EEventID eventId,
                           bool isActive)
    : mStateFactory{stateFactory}
    , mCurrentState{nullptr}
{
}

void StateMachine::onAction(bool isActive)
{
    std::lock_guard<std::mutex> lock{mIncomingValuesMutex};

    mIsActive = isActive;
    processIncomingValues();
}

void StateMachine::onEvent(EEventID eventId)
{
    std::lock_guard<std::mutex> lock{mIncomingValuesMutex};

    mEventId = eventId;
    processIncomingValues();
}

void StateMachine::processIncomingValues()
{
    if (mCurrentState) {
        auto nextStateId = mCurrentState->process(mEventId, mIsActive);
        if (nextStateId != mCurrentState->getStateId() && nextStateId != EStateId::Undefined) {
            auto nextState = mStateFactory.createState(nextStateId);
            if (nextState) {
                mCurrentState = nextState;
                notifyListener(nextStateId);
            }
        }
    }
    else if (mIsActive && mEventId == EEventID::Initializing) {
        mCurrentState = mStateFactory.createState(EStateId::Initialization);
        notifyListener(EStateId::Initialization);
    }
}