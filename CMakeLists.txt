#cmake_minimum_required(VERSION 3.10)

project(Samples)

set(CMAKE_CXX_STANDARD 14)

include_directories(
    ./src
)

add_executable(
    Samples

    src/FSM/Impl/StateMachine.cpp
    src/FSM/Impl/InitializationState.cpp
    src/FSM/Impl/OpenedState.cpp
    src/FSM/Impl/ClosedState.cpp
    src/FSM/Impl/ShutdownState.cpp

    src/FSM/tests/CloseStateTests.cpp
    src/FSM/tests/OpenStateTests.cpp
    src/FSM/tests/InitializationStateTests.cpp
    src/FSM/tests/ShutdownStateTests.cpp
    src/FSM/tests/StateMachineTests.cpp

    src/FSM/external/Controller.cpp
    src/FSM/Impl/InitialState.cpp

    src/FSM/IStateChangeHandler.h

    src/Common/tests/NullableValueTests.cpp
    src/Dispatcher/tests/DispatcherTests.cpp
    src/Dispatcher/tests/DeferredLaunchTests.cpp
)

target_link_libraries(
    Samples

    pthread

    gtest
    gmock
    gtest_main
)