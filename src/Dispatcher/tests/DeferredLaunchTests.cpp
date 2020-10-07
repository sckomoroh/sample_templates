#include <gtest/gtest.h>

#include <iostream>
#include <thread>

#include "Dispatcher/DeferredLaunch.h"

using com::dispatcher::DeferredLaunch;

class DeferredLaunchTests : public ::testing::Test {
};

TEST_F(DeferredLaunchTests, SimpleTest)
{
    using namespace std::chrono_literals;

    DeferredLaunch<> defferedLaunch;

    auto inputTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch());
    std::cout << inputTime.count() << std::endl;
    defferedLaunch.launch(100ms, []() -> void {
        auto runTime = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch());
        std::cout << runTime.count() << std::endl;
    });

    std::this_thread::sleep_for(1s);
}