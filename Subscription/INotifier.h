//
// Created by yzvihunov on 8/23/19.
//

#ifndef CODETEMPLATES_INOTIFIER_H
#define CODETEMPLATES_INOTIFIER_H

template<class TThis, class TFunc, TFunc func, class ...TArgs>
class INotifier {
public:
    virtual void notifyListener(TArgs... args) const = 0;
};


#endif //CODETEMPLATES_INOTIFIER_H
