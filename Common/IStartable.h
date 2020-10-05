#ifndef _IStartable_H_
#define _IStartable_H_

namespace com {
namespace common {

template <class... TArgs>
class IStartable {
private:
public:
    virtual ~IStartable() = default;

    virtual void start(TArgs... args) = 0;

    virtual void stop() = 0;

    virtual bool isStarted() const = 0;
};

}  // namespace common
}  // namespace com

#endif  // _IStartable_H_
