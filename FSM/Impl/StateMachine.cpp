//
// Created by yzvihunov on 8/27/19.
//

#include "StateMachine.h"

StateMachine::StateMachine(IStateFactory<EStateId, EEventID, bool>& stateFactory)
    : mStateFactory{stateFactory}
    , mCurrentState{mStateFactory.createState(EStateId::Initial)}
{
}

void StateMachine::onAction(bool isActive)
{
    std::lock_guard<std::mutex> lock{mIncomingValuesMutex};

    mIsActive.setValue(isActive);
    processIncomingValues();
}

void StateMachine::onEvent(EEventID eventId)
{
    std::lock_guard<std::mutex> lock{mIncomingValuesMutex};

    mEventId.setValue(eventId);
    processIncomingValues();
}

void StateMachine::processIncomingValues()
{
    EEventID eventId;
    bool isActive;

    if (mEventId.getValue(eventId) && mIsActive.getValue(isActive)) {
        if (mCurrentState) {
            auto nextStateId = mCurrentState->process(eventId, isActive);
            if (nextStateId != mCurrentState->getStateId() && nextStateId != EStateId::Undefined) {
                auto nextState = mStateFactory.createState(nextStateId);
                if (nextState) {
                    mCurrentState = nextState;
                    notifyListener(nextStateId);
                }
            }
        }
    }
}