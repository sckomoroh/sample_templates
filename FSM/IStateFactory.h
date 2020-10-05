//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_ISTATEFACTORY_H
#define CODETEMPLATES_ISTATEFACTORY_H

#include <memory>

#include "IState.h"

namespace com {
namespace fsm {

template <class TStateId, class TAction, class... TArgs>
class IStateFactory {
public:
    virtual std::shared_ptr<IState<TStateId, TAction, TArgs...>> createState(
        EStateId stateId) const = 0;
};

}  // namespace fsm
}  // namespace com

#endif  // CODETEMPLATES_ISTATEFACTORY_H
