#ifndef com_IDispatcherListenerMock_H_
#define com_IDispatcherListenerMock_H_

#include <gmock/gmock.h>

#include "Dispatcher/IDispatcherListener.h"

namespace com {
namespace dispatcher {

template <class TMessage>
class IDispatcherListenerMock : public IDispatcherListener<TMessage> {
public:
    MOCK_METHOD1_T(onMessageAvailable, void(TMessage));
};

}  // namespace dispatcher
}  // namespace com

#endif  // com_IDispatcherListenerMock_H_
