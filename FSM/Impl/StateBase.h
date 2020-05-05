#ifndef _StateBase_H_
#define _StateBase_H_

#include <memory>

#include "EEventID.h"
#include "EStateId.h"
#include "IDevice.h"
#include "IState.h"

class StateBase : public IState<EStateId, EEventID, bool> {
protected:
    IDevice& mDevice;

public:
    StateBase(IDevice& device)
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
