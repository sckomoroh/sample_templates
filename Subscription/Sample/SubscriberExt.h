//
// Created by yzvihunov on 8/23/19.
//

#ifndef CODETEMPLATES_SUBSCRIBEREXT_H
#define CODETEMPLATES_SUBSCRIBEREXT_H

#include "Handler.h"
#include "SubscriberImpl.h"

class SubscriberExt : public SubscriberImpl<Handler> {
public:
    void process(int index, std::string msg);
};


#endif //CODETEMPLATES_SUBSCRIBEREXT_H
