//
// Created by yzvihunov on 8/27/19.
//

#ifndef CODETEMPLATES_STATEFACTORY_H
#define CODETEMPLATES_STATEFACTORY_H

#include "IStateFactory.h"

class StateFactory : public IStateFactory {
public:
    std::shared_ptr<IState> createState(EStateId stateId) const override;
};


#endif //CODETEMPLATES_STATEFACTORY_H
