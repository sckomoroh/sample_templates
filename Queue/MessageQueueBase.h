//
// Created by yzvihunov on 8/29/19.
//

#ifndef CODETEMPLATES_MESSAGEQUEUEBASE_H
#define CODETEMPLATES_MESSAGEQUEUEBASE_H

#include <condition_variable>
#include <queue>

#include "IMessageQueue.h"

template<class TMessage>
class MessageQueueBase : public IMessageQueue<TMessage>{
private:
    std::queue<TMessage> mMessages;
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
        auto message = mMessages.front();
        mMessages.pop();

        return message;
    }
};


#endif //CODETEMPLATES_MESSAGEQUEUEBASE_H
