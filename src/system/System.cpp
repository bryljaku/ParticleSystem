//
// Created by jakub on 01.11.2019.
//

#include "../../headers/system/System.h"

System::System(size_t maxNumberOfParticles) {
    maxNumberOfParticles = maxNumberOfParticles;
    container.generate(maxNumberOfParticles);
    
    for (size_t i = 0; i < maxNumberOfParticles; ++i)
        container.isAlive[i] = false;
}

void System::update(double dt) {
//    for (auto & emmiter : emitters)
//        emmiter->emit(&container, dt);
    
    for (auto & updater : updaters)
        updater->update(dt, &container);
}

