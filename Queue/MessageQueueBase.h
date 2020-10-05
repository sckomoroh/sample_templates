//
// Created by yzvihunov on 8/29/19.
//

#ifndef CODETEMPLATES_MESSAGEQUEUEBASE_H
#define CODETEMPLATES_MESSAGEQUEUEBASE_H

#include <condition_variable>
#include <queue>

#include "IMessageQueue.h"

namespace com {
namespace queue {

template <class TMessage>
class MessageQueueBase : public IMessageQueue<TMessage> {
private:
    std::queue<TMessage> mMessages;
    std::condition_variable mWaitVar;
    std::mutex mMutex;
    bool mProcessMsg = true;

public:
    virtual ~MessageQueueBase()
    {
        mProcessMsg = false;
        mWaitVar.notify_all();
    }

    void pushMessage(TMessage message) override
    {
        std::unique_lock<std::mutex> locker(mMutex);

        mMessages.push(message);

        mWaitVar.notify_one();
    }

    bool popMessage(TMessage& message) override
    {
        auto res = false;
        std::unique_lock<std::mutex> locker(mMutex);

        mWaitVar.wait(locker, [this]() { return !mMessages.empty(); });
        if (mProcessMsg) {
            res = true;
            message = mMessages.front();
            mMessages.pop();
        }

        return res;
    }

    bool isEmpty() const override { return mMessages.empty(); }
};

}  // namespace queue
}  // namespace com

#endif  // CODETEMPLATES_MESSAGEQUEUEBASE_H
