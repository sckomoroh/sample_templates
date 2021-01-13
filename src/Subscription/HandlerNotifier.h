#pragma onces

#include <algorithm>
#include <list>

namespace com {
namespace subscription {

template <class THandler>
class HandlerContainer {
protected:
    // TODO: protect from inherit classes
    std::list<THandler*> _handlers;

public:
    bool addHandler(THandler* handler)
    {
        auto res = false;
        auto iter = std::find_if(_handlers.begin(), _handlers.end(),
                                 [&handler](THandler* item) { return item == handler; });

        if (iter == _handlers.end()) {
            res = true;
            _handlers.push_back(handler);
        }

        return res;
    }

    bool removeHandler(THandler* handler)
    {
        auto res = false;
        auto iter = std::find_if(_handlers.begin(), _handlers.end(),
                                 [&handler](THandler* item) { return item == handler; });

        if (iter != _handlers.end()) {
            res = true;
            _handlers.erase(iter);
        }

        return res;
    }

    void clear() { _handlers.clear(); }
};

template <class TFunc>
class HandlerNotifier;

template <class THandler, class... TArgs>
class HandlerNotifier<void (THandler::*)(TArgs...)> : public HandlerContainer<THandler> {
public:
    template <void (THandler::*VMember)(TArgs...)>
    bool addHandlerWithNotification(THandler* handler, TArgs... args)
    {
        auto res = addHandler(handler);
        if (res) {
            (handler->*VMember)(args...);
        }

        return res;
    }

    template <void (THandler::*VMember)(TArgs...)>
    void notifyHandlers(TArgs... args)
    {
        for (auto handler : HandlerContainer<THandler>::_handlers) {
            if (handler) {
                (handler->*VMember)(args...);
            }
        }
    }
};

template <class... THandlers>
class ComplexHandlersNotifier : protected HandlerNotifier<THandlers>... {
public:
    template <class THandler>
    bool addHandler(THandler* handler)
    {
        return HandlerContainer<THandler>::addHandler(handler);
    }

    template <class THandler>
    bool removeHandler(THandler* handler)
    {
        return HandlerContainer<THandler>::removeHandler(handler);
    }

    template <class THandler>
    void clear(THandler* handler)
    {
        HandlerContainer<THandler>::clear();
    }
};

}  // namespace subscription
}  // namespace com
