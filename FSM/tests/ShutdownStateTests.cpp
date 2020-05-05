#include <gtest/gtest.h>

#include "IDeviceMock.h"
#include "ShutdownState.h"

class ShutdownStateTests : public ::testing::Test {
protected:
    IDeviceMock mDeviceMock;
    ShutdownState mState;

protected:  // ctor
    ShutdownStateTests()
        : mState{mDeviceMock}
    {
    }
};

TEST_F(ShutdownStateTests, active_open)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Open, true), EStateId::ShutDown);
}

TEST_F(ShutdownStateTests, active_close)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Close, true), EStateId::ShutDown);
}

TEST_F(ShutdownStateTests, active_initialize)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).WillOnce(::testing::Return(true));
    EXPECT_CALL(mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Initializing, true), EStateId::Initialization);
}

TEST_F(ShutdownStateTests, inactive_open)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Open, false), EStateId::ShutDown);
}

TEST_F(ShutdownStateTests, inactive_close)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Close, false), EStateId::ShutDown);
}

TEST_F(ShutdownStateTests, inactive_initialize)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Initializing, false), EStateId::ShutDown);
}

TEST_F(ShutdownStateTests, initialize_failed)
{
    EXPECT_CALL(mDeviceMock, open()).Times(0);
    EXPECT_CALL(mDeviceMock, close()).Times(0);
    EXPECT_CALL(mDeviceMock, initialize()).WillOnce(::testing::Return(false));
    EXPECT_CALL(mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Initializing, true), EStateId::ShutDown);
}
