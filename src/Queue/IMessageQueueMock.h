#ifndef com_IMessageQueueMock_H_
#define com_IMessageQueueMock_H_

#include <gmock/gmock.h>

#include "IMessageQueue.h"

namespace com {
namespace queue {

template <class TMsg>
class IMessageQueueMock : public IMessageQueue<TMsg> {
public:
    MOCK_METHOD1_T(pushMessage, void(TMsg));
    MOCK_METHOD1_T(popMessage, bool(TMsg&));
    MOCK_CONST_METHOD0_T(isEmpty, bool());
};

}  // namespace queue
}  // namespace com

#endif  // com_IMessageQueueMock_H_
