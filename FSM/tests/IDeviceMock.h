#ifndef _IDeviceMock_H_
#define _IDeviceMock_H_

#include <gmock/gmock.h>

#include "IDevice.h"

class IDeviceMock : public IDevice {
public:
    MOCK_METHOD0(initialize, bool());
    MOCK_METHOD0(open, bool());
    MOCK_METHOD0(close, bool());
    MOCK_METHOD0(shutdown, bool());
};

#endif  // _IDeviceMock_H_
