//
// Created by yzvihunov on 8/29/19.
//

#ifndef CODETEMPLATES_MESSAGEQUEUEBASE_H
#define CODETEMPLATES_MESSAGEQUEUEBASE_H

#include <condition_variable>
#include <deque>

#include "IMessageQueue.h"

template<class TMessage>
class MessageQueueBase : public IMessageQueue<TMessage>{
private:
    std::deque<TMessage> mMessages;
    std::condition_variable mWaitVar;

public:
    void pushMessage(TMessage message) override {
        mMessages.push_back(message);

        mWaitVar.notify_all();
    }

    TMessage popMessage() override {
        std::mutex mutex;
        std::unique_lock<std::mutex> locker(mutex);

        mWaitVar.wait(locker, [this](){ return mMessages.size() > 0; });
        auto message = mMessages.at(0);
        mMessages.pop_front();

        return message;
    }
};


#endif //CODETEMPLATES_MESSAGEQUEUEBASE_H
