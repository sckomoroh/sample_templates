//
// Created by yzvihunov on 8/27/19.
//

#include "StateMachine.h"

StateMachine::StateMachine(IStateFactory &stateFactory, EStateId initState, int initValue)
    : mStateFactory(stateFactory) {

    mCurrentState = mStateFactory.createState(initState);
    if (mCurrentState) {
        mCurrentState->update(initValue);
    }

    initializeTransitions();
}

void StateMachine::onAction() {
    do {
        if (!mCurrentState) {
            break;
        }

        auto iter = mTransitions.find(mCurrentState->getStateId());
        if (iter == mTransitions.end()) {
            break;
        }

        auto nextStateId = iter->second(mCurrentState->getValue());
        if (nextStateId == EStateId::Undefined) {
            break;
        }

        auto nextState = mStateFactory.createState(nextStateId);
        if (!nextState) {
            break;
        }

        nextState->update(mCurrentState->getValue());

        mCurrentState = nextState;
    } while (false);
}

void StateMachine::onStateChanged(int value) {
    if (mCurrentState) {
        mCurrentState->update(value);
    }
}

void StateMachine::initializeTransitions() {
    mTransitions = {
            {EStateId::State1, &StateMachine::state1Transition },
            {EStateId::State2, &StateMachine::state2Transition },
            {EStateId::State3, &StateMachine::state3Transition },
    };
}

EStateId StateMachine::state1Transition(int value) {
    return value > 0 ? EStateId::State2 : EStateId::State3;
}

EStateId StateMachine::state2Transition(int value) {
    return value > 0 ? EStateId::State3 : EStateId::State1;
}

EStateId StateMachine::state3Transition(int value) {
    return value > 0 ? EStateId::State1 : EStateId::State2;
}
