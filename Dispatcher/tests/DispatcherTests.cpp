#include <gtest/gtest.h>

#include "Dispatcher/Dispatcher.h"

#include "IDispatcherListenerMock.h"
#include "Queue/IMessageQueueMock.h"

using com::common::IRunnable;
using com::dispatcher::Dispatcher;
using com::dispatcher::IDispatcherListenerMock;
using com::queue::IMessageQueueMock;

class TestRunnable : public IRunnable<> {
public:
    void run() override {}
};

enum class EDeviceEvent { Open, Close, Error };

class DispatcherTests : public ::testing::Test {
};

TEST_F(DispatcherTests, SimpleTest)
{
    auto event = EDeviceEvent::Open;
    IDispatcherListenerMock<EDeviceEvent> listener;

    IMessageQueueMock<EDeviceEvent> queue;
    Dispatcher<EDeviceEvent> dispatcher{queue};

    EXPECT_CALL(queue, pushMessage(event)).Times(1);
    EXPECT_CALL(queue, popMessage(::testing::_))
        .WillOnce(::testing::DoAll(::testing::SetArgReferee<0>(event), ::testing::Return(true)))
        .WillOnce(::testing::Return(false));
    EXPECT_CALL(listener, onMessageAvailable(event)).Times(1);

    queue.pushMessage(event);

    dispatcher.subscribe(listener);
    dispatcher.start();
}