#cmake_minimum_required(VERSION 3.10)

project(Samples)

set(CMAKE_CXX_STANDARD 14)

include_directories(
    ./
)

add_executable(
    Samples

    FSM/Impl/StateMachine.cpp
    FSM/Impl/InitializationState.cpp
    FSM/Impl/OpenedState.cpp
    FSM/Impl/ClosedState.cpp
    FSM/Impl/ShutdownState.cpp

    FSM/tests/CloseStateTests.cpp
    FSM/tests/OpenStateTests.cpp
    FSM/tests/InitializationStateTests.cpp
    FSM/tests/ShutdownStateTests.cpp
    FSM/tests/StateMachineTests.cpp

    FSM/external/Controller.cpp
    FSM/Impl/InitialState.cpp

    FSM/IStateChangeHandler.h

    Common/tests/NullableValueTests.cpp
    Dispatcher/tests/DispatcherTests.cpp
)

target_link_libraries(
    Samples

    pthread

    gtest
    gmock
    gtest_main
)