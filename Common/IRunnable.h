#ifndef com_IRunnable_H_
#define com_IRunnable_H_

namespace com {
namespace common {

template <class... TArgs>
class IRunnable {
public:
    virtual ~IRunnable() = default;

public:
    virtual void run(TArgs... args) = 0;
};

}  // namespace common
}  // namespace com

#endif  // com_IRunnable_H_
