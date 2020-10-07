#include <gtest/gtest.h>

#include "FSM/Impl/OpenedState.h"
#include "IDeviceMock.h"

class OpenedStateTests : public ::testing::Test {
protected:
    std::shared_ptr<IDeviceMock> mDeviceMock;
    OpenedState mState;

protected:  // ctor
    OpenedStateTests()
        : mDeviceMock{new IDeviceMock}
        , mState{mDeviceMock}
    {
    }
};

TEST_F(OpenedStateTests, active_open)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Open, true), EStateId::Opened);
}

TEST_F(OpenedStateTests, active_close)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Close, true), EStateId::Closed);
}

TEST_F(OpenedStateTests, active_initialize)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Initializing, true), EStateId::Opened);
}

TEST_F(OpenedStateTests, inactive_open)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).WillOnce(::testing::Return(true));
    EXPECT_EQ(mState.process(EEventID::Open, false), EStateId::ShutDown);
}

TEST_F(OpenedStateTests, inactive_close)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).WillOnce(::testing::Return(true));
    EXPECT_EQ(mState.process(EEventID::Close, false), EStateId::ShutDown);
}

TEST_F(OpenedStateTests, inactive_initialize)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).WillOnce(::testing::Return(true));
    EXPECT_EQ(mState.process(EEventID::Initializing, false), EStateId::ShutDown);
}

TEST_F(OpenedStateTests, close_failed)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).WillOnce(::testing::Return(false));
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Close, true), EStateId::Opened);
}

TEST_F(OpenedStateTests, shutdown_failed)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).WillOnce(::testing::Return(false));
    EXPECT_EQ(mState.process(EEventID::Open, false), EStateId::Opened);
}
