#ifndef _StateBase_H_
#define _StateBase_H_

#include <memory>

#include "EStateId.h"
#include "FSM/IState.h"
#include "FSM/external/EEventID.h"
#include "FSM/external/IDevice.h"

using com::fsm::IState;

class StateBase : public IState<EStateId, EEventID, bool> {
protected:
    std::shared_ptr<IDevice> mDevice;

public:
    StateBase(const std::shared_ptr<IDevice>& device)
        : mDevice{device}
    {
    }

    virtual ~StateBase() = default;

public:
    template <class TDerived, class... TCtorArgs>
    static std::shared_ptr<IState> create(TCtorArgs... args)
    {
        static std::shared_ptr<StateBase> state = std::make_shared<TDerived>(args...);
        return state;
    }
};

#endif  // _StateBase_H_
