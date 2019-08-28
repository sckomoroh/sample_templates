//
// Created by yzvihunov on 8/23/19.
//

#ifndef CODETEMPLATES_SUBSCRIBEREXT_H
#define CODETEMPLATES_SUBSCRIBEREXT_H

#include "Handler.h"
#include "NotifierStaticImpl.h"
#include "SubscriberImpl.h"

class SubscriberExt : public NotifierStaticImpl<Handler, decltype(Handler::notify)&, Handler::notify, int, std::string> {
private:
    using BaseClass = NotifierStaticImpl<Handler, decltype(Handler::notify)&, Handler::notify, int, std::string>;

public:
    void process(int index, std::string msg);
};


#endif //CODETEMPLATES_SUBSCRIBEREXT_H
