//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_ISTATELISTENER_H
#define CODETEMPLATES_ISTATELISTENER_H


class IStateListener {
public:
    virtual void onStateChanged(int value) = 0;
};


#endif //CODETEMPLATES_ISTATELISTENER_H
