//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_ISTATE_H
#define CODETEMPLATES_ISTATE_H

#include "IStateChangeHandler.h"
#include "Subscription/ISubscriber.h"

namespace com {
namespace fsm {

template <class TStateId, class... TArgs>
class IState {
public:
    virtual TStateId process(TArgs... args) = 0;

    virtual TStateId getStateId() const = 0;
};

}  // namespace fsm
}  // namespace com

#endif  // CODETEMPLATES_ISTATE_H
