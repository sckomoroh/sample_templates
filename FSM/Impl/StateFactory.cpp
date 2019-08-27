//
// Created by yzvihunov on 8/27/19.
//

#include "StateFactory.h"

#include "State1.h"
#include "State2.h"
#include "State3.h"

std::shared_ptr<IState> StateFactory::createState(EStateId stateId) const {
    std::shared_ptr<IState> state = nullptr;

    switch (stateId) {
        case EStateId::State1:
            state = std::make_shared<State1>();
            break;
        case EStateId::State2:
            state = std::make_shared<State2>();
            break;
        case EStateId::State3:
            state = std::make_shared<State3>();
            break;
        default:
            break;
    }

    return state;
}
