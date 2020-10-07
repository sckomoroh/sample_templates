//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_STATEMACHINE_H
#define CODETEMPLATES_STATEMACHINE_H

#include <functional>
#include <memory>
#include <mutex>

#include "FSM/external/IActionListener.h"
#include "FSM/external/IEventListener.h"

#include "EStateId.h"
#include "FSM/IState.h"
#include "FSM/IStateFactory.h"

#include "Common/NullableValue.h"

#include "Subscription/Notifier.h"

namespace com {
namespace fsm {

using com::common::NullableValue;
using com::subscription::Notifier;

DECLARE_NOTIFIER(StateChangeNotifier, IStateChangeHandler<EStateId>::onStateChanged);

class StateMachine
    : public IEventListener
    , public IActionListener
    , public StateChangeNotifier {
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

}  // namespace fsm
}  // namespace com

#endif  // CODETEMPLATES_STATEMACHINE_H
