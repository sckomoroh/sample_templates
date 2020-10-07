#ifndef com_IDispatcherListener_H_
#define com_IDispatcherListener_H_

namespace com {
namespace dispatcher {

template <class TMessage>
class IDispatcherListener {
public:
    virtual ~IDispatcherListener() = default;

public:
    virtual void onMessageAvailable(TMessage msg) = 0;
};

}  // namespace dispatcher
}  // namespace com

#endif  // com_IDispatcherListener_H_
