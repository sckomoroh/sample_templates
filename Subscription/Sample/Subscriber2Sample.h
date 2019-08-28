//
// Created by yzvihunov on 8/28/19.
//

#ifndef CODETEMPLATES_SUBSCRIBER2SAMPLE_H
#define CODETEMPLATES_SUBSCRIBER2SAMPLE_H


#include "Handler.h"
#include "NotifierImpl.h"

class Subscriber2Sample : public NotifierImpl<Handler, void(Handler::*)(int, std::string), &Handler::onNotify, int, std::string> {
public:
    void process(int index, std::string value);
};


#endif //CODETEMPLATES_SUBSCRIBER2SAMPLE_H
