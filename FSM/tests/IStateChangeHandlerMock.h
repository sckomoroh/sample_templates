#ifndef _IStateChangeHandlerMock_H_
#define _IStateChangeHandlerMock_H_

#include <gmock/gmock.h>

#include "EStateId.h"
#include "IStateChangeHandler.h"

class IStateChangeHandlerMock : public IStateChangeHandler<EStateId> {
public:
    MOCK_METHOD1(onStateChanged, void(EStateId));
};

#endif  // _IStateChangeHandlerMock_H_
