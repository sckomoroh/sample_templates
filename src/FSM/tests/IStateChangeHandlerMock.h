#ifndef _IStateChangeHandlerMock_H_
#define _IStateChangeHandlerMock_H_

#include <gmock/gmock.h>

#include "FSM/IStateChangeHandler.h"
#include "FSM/Impl/EStateId.h"

using com::fsm::IStateChangeHandler;

class IStateChangeHandlerMock : public IStateChangeHandler<EStateId> {
public:
    MOCK_METHOD1(onStateChanged, void(EStateId));
};

#endif  // _IStateChangeHandlerMock_H_
