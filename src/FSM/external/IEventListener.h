#ifndef _IEventListener_H_
#define _IEventListener_H_

#include "EEventID.h"

class IEventListener {
public:
    virtual void onEvent(EEventID eventId) = 0;
};

#endif  // _IEventListener_H_
