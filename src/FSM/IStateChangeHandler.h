//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_ISTATELISTENER_H
#define CODETEMPLATES_ISTATELISTENER_H

namespace com {
namespace fsm {

template <class TStateId>
class IStateChangeHandler {
public:
    virtual void onStateChanged(TStateId stateId) = 0;
};

}  // namespace fsm
}  // namespace com

#endif  // CODETEMPLATES_ISTATELISTENER_H
