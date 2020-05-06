//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_STATEMACHINE_H
#define CODETEMPLATES_STATEMACHINE_H

#include <functional>
#include <memory>
#include <mutex>

#include "IActionListener.h"
#include "IEventListener.h"

#include "EStateId.h"
#include "IState.h"
#include "IStateFactory.h"

#include "NullableValue.h"

#include "Impl/NotifierImpl.h"

class StateMachine
    : public IEventListener
    , public IActionListener
    , public NotifierImpl<decltype(&IStateChangeHandler<EStateId>::onStateChanged),
                          &IStateChangeHandler<EStateId>::onStateChanged> {
private:
    IStateFactory<EStateId, EEventID, bool>& mStateFactory;
    std::shared_ptr<IState<EStateId, EEventID, bool>> mCurrentState;
    NullableValue<EEventID> mEventId;
    NullableValue<bool> mIsActive;
    std::mutex mIncomingValuesMutex;

public:
    StateMachine(IStateFactory<EStateId, EEventID, bool>& stateFactory);

public:  // IActionListener
    void onAction(bool isActive) override;

public:  // IEventListener
    void onEvent(EEventID eventId) override;

private:
    void processIncomingValues();
};

#endif  // CODETEMPLATES_STATEMACHINE_H
