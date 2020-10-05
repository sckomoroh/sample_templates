//
// Created by yzvihunov on 8/23/19.
//

#ifndef CODETEMPLATES_INOTIFIER_H
#define CODETEMPLATES_INOTIFIER_H

namespace com {
namespace subscription {

template <class... TArgs>
class INotifier {
public:
    virtual void notifyListener(TArgs... args) = 0;
};

}  // namespace subscription
}  // namespace com

#endif  // CODETEMPLATES_INOTIFIER_H
