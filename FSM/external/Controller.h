#ifndef _Controller_H_
#define _Controller_H_

#include "IActionListener.h"
#include "IEventListener.h"
#include "NotifierImpl.h"

DECLARE_NOTIFIER(ActionNotifier, IActionListener::onAction)
DECLARE_NOTIFIER(EventNotifier, IEventListener::onEvent)

class Controller final
    : public ActionNotifier
    , public EventNotifier {
private:
    bool _isOpened;

public:
    Controller();

public:
    void startUp();
    void shutDown();
    void open();
    void close();
};

#endif  // _Controller_H_
