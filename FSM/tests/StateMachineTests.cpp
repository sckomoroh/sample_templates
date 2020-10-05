#include <gtest/gtest.h>

#include "FSM/Impl/StateFactory.h"
#include "FSM/Impl/StateMachine.h"
#include "FSM/external/Controller.h"
#include "IDeviceMock.h"
#include "IStateChangeHandlerMock.h"

using ::testing::StrictMock;

using com::fsm::ActionNotifier;
using com::fsm::Controller;
using com::fsm::EventNotifier;
using com::fsm::StateMachine;

class StateMachineTests : public ::testing::Test {
protected:
    StrictMock<IDeviceMock> device;
    StateFactory stateFactory;
    StateMachine stateMachine;
    Controller controller;
    IStateChangeHandlerMock stateHandler;

protected:
    StateMachineTests()
        : device{}
        , stateFactory{device}
        , stateMachine{stateFactory}
    {
        controller.ActionNotifier::subscribe(stateMachine);
        controller.EventNotifier::subscribe(stateMachine);
        stateMachine.subscribe(stateHandler);
    }
};

TEST_F(StateMachineTests, startUpTest_success)
{
    EXPECT_CALL(device, initialize()).WillOnce(::testing::Return(true));
    EXPECT_CALL(stateHandler, onStateChanged(EStateId::Initialization));

    controller.startUp();
}

TEST_F(StateMachineTests, shutDownTest_success)
{
    EXPECT_CALL(device, initialize()).WillOnce(::testing::Return(true));
    EXPECT_CALL(device, shutdown()).WillOnce(::testing::Return(true));
    EXPECT_CALL(stateHandler, onStateChanged(EStateId::Initialization));
    EXPECT_CALL(stateHandler, onStateChanged(EStateId::ShutDown));

    controller.startUp();
    controller.shutDown();
}

TEST_F(StateMachineTests, openTest)
{
    controller.startUp();
    controller.open();
}

TEST_F(StateMachineTests, closeTest)
{
    controller.startUp();
    controller.open();
    controller.close();
}