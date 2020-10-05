//
// Created by yzvihunov on 8/29/19.
//

#ifndef CODETEMPLATES_IMESSAGEQUEUE_H
#define CODETEMPLATES_IMESSAGEQUEUE_H

namespace com {
namespace queue {

template <class TMessage>
class IMessageQueue {
public:
    virtual ~IMessageQueue() = default;

    virtual void pushMessage(TMessage message) = 0;

    virtual bool popMessage(TMessage& message) = 0;

    virtual bool isEmpty() const = 0;
};

}  // namespace queue
}  // namespace com

#endif  // CODETEMPLATES_IMESSAGEQUEUE_H
