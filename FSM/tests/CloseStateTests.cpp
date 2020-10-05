#include <gtest/gtest.h>

#include "FSM/Impl/ClosedState.h"
#include "IDeviceMock.h"

class CloseStateTests : public ::testing::Test {
protected:
    IDeviceMock mDeviceMock;
    ClosedState mState;

protected:  // ctor
    CloseStateTests()
        : mState{mDeviceMock}
    {
    }
};

TEST_F(CloseStateTests, active_open)
{
    EXPECT_CALL(mDeviceMock, open()).WillOnce(::testing::Return(true));
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Open, true), EStateId::Opened);
}

TEST_F(CloseStateTests, active_close)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Close, true), EStateId::Closed);
}

TEST_F(CloseStateTests, active_initialize)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Initializing, true), EStateId::Closed);
}

TEST_F(CloseStateTests, inactive_open)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).WillOnce(::testing::Return(true));
    EXPECT_EQ(mState.process(EEventID::Open, false), EStateId::ShutDown);
}

TEST_F(CloseStateTests, inactive_close)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).WillOnce(::testing::Return(true));
    EXPECT_EQ(mState.process(EEventID::Close, false), EStateId::ShutDown);
}

TEST_F(CloseStateTests, inactive_initialize)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).WillOnce(::testing::Return(true));
    EXPECT_EQ(mState.process(EEventID::Initializing, false), EStateId::ShutDown);
}

TEST_F(CloseStateTests, open_failed)
{
    EXPECT_CALL(mDeviceMock, open()).WillOnce(::testing::Return(false));
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Open, true), EStateId::Closed);
}

TEST_F(CloseStateTests, shutdown_failed)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).WillOnce(::testing::Return(false));
    EXPECT_EQ(mState.process(EEventID::Open, false), EStateId::Closed);
}
