#include "Controller.h"

Controller::Controller()
    : _isOpened{false}
{
}

void Controller::startUp()
{
    ActionNotifier::notifyListener(true);
    EventNotifier::notifyListener(EEventID::Initializing);
}

void Controller::shutDown() { ActionNotifier::notifyListener(false); }

void Controller::open() { EventNotifier::notifyListener(EEventID::Open); }

void Controller::close() { EventNotifier::notifyListener(EEventID::Close); }
