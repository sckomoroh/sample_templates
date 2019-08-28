//
// Created by yzvihunov on 8/23/19.
//

#ifndef CODETEMPLATES_HANDLER_H
#define CODETEMPLATES_HANDLER_H

#include <string>
#include <functional>

#include "SubscriberImpl.h"

class Handler {
public:
    void onNotify(int index, std::string msg);

    static void notify(Handler* pThis, int index, std::string msg) {
        pThis->onNotify(index, msg);
    }
};

#endif //CODETEMPLATES_HANDLER_H
