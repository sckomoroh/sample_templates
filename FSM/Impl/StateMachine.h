//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_STATEMACHINE_H
#define CODETEMPLATES_STATEMACHINE_H

#include <functional>
#include <map>
#include <memory>

#include "IActionListener.h"
#include "IStateListener.h"

#include "IState.h"
#include "IStateFactory.h"

class StateMachine
        : public IStateListener
        , public IActionListener {
private:
    IStateFactory& mStateFactory;
    std::shared_ptr<IState> mCurrentState;
    std::map<EStateId, std::function<EStateId(int)>> mTransitions;

public:
    StateMachine(IStateFactory& stateFactory, EStateId initState, int initValue);

    void onAction() override;

    void onStateChanged(int value) override;

private:
    void initializeTransitions();

    static EStateId state1Transition(int value);

    static EStateId state2Transition(int value);

    static EStateId state3Transition(int value);
};


#endif //CODETEMPLATES_STATEMACHINE_H
