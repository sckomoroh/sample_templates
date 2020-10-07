#ifndef _Controller_H_
#define _Controller_H_

#include "IActionListener.h"
#include "IEventListener.h"
#include "Subscription/Notifier.h"

namespace com {
namespace fsm {

using ::com::subscription::Notifier;

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

}  // namespace fsm
}  // namespace com

#endif  // _Controller_H_
