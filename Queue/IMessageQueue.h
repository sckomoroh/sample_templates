//
// Created by yzvihunov on 8/29/19.
//

#ifndef CODETEMPLATES_IMESSAGEQUEUE_H
#define CODETEMPLATES_IMESSAGEQUEUE_H


template<class TMessage>
class IMessageQueue {
public:
    virtual ~IMessageQueue() = default;

    void pushMessage(TMessage message);

    TMessage popMessage();
};



#endif //CODETEMPLATES_IMESSAGEQUEUE_H
