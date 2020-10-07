#include <gtest/gtest.h>

#include "FSM/Impl/InitializationState.h"
#include "IDeviceMock.h"

class InitializationStateTests : public ::testing::Test {
protected:
    std::shared_ptr<IDeviceMock> mDeviceMock;
    InitializationState mState;

protected:  // ctor
    InitializationStateTests()
        : mDeviceMock{new IDeviceMock}
        , mState{mDeviceMock}
    {
    }
};

TEST_F(InitializationStateTests, active_open)
{
    EXPECT_CALL(*mDeviceMock, open()).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Open, true), EStateId::Opened);
}

TEST_F(InitializationStateTests, active_close)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Close, true), EStateId::Initialization);
}

TEST_F(InitializationStateTests, active_initialize)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Initializing, true), EStateId::Initialization);
}

TEST_F(InitializationStateTests, inactive_open)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).WillOnce(::testing::Return(true));
    EXPECT_EQ(mState.process(EEventID::Open, false), EStateId::ShutDown);
}

TEST_F(InitializationStateTests, inactive_close)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).WillOnce(::testing::Return(true));
    EXPECT_EQ(mState.process(EEventID::Close, false), EStateId::ShutDown);
}

TEST_F(InitializationStateTests, inactive_initialize)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).WillOnce(::testing::Return(true));
    EXPECT_EQ(mState.process(EEventID::Initializing, false), EStateId::ShutDown);
}

TEST_F(InitializationStateTests, open_failed)
{
    EXPECT_CALL(*mDeviceMock, open()).WillOnce(::testing::Return(false));
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).Times(0);
    EXPECT_EQ(mState.process(EEventID::Open, true), EStateId::Initialization);
}

TEST_F(InitializationStateTests, shutdown_failed)
{
    EXPECT_CALL(*mDeviceMock, open()).Times(0);
    EXPECT_CALL(*mDeviceMock, close()).Times(0);
    EXPECT_CALL(*mDeviceMock, initialize()).Times(0);
    EXPECT_CALL(*mDeviceMock, shutdown()).WillOnce(::testing::Return(false));
    EXPECT_EQ(mState.process(EEventID::Open, false), EStateId::Initialization);
}
