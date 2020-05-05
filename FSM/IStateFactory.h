//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_ISTATEFACTORY_H
#define CODETEMPLATES_ISTATEFACTORY_H

#include <memory>

#include "EStateId.h"
#include "IState.h"

template <class TStateId, class TAction, class... TArgs>
class IStateFactory {
public:
    virtual std::shared_ptr<IState<TStateId, TAction, TArgs...>> createState(
        EStateId stateId) const = 0;
};

#endif  // CODETEMPLATES_ISTATEFACTORY_H
