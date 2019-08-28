//
// Created by yzvihunov on 8/23/19.
//

#include "SubscriberExt.h"

void SubscriberExt::process(int index, std::string msg) {
    BaseClass::notifyListener(index, msg);
}