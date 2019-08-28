//
// Created by yzvihunov on 8/28/19.
//

#include "Subscriber2Sample.h"

void Subscriber2Sample::process(int index, std::string value) {
    notifyListener(index, value);
}
