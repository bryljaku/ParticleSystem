//
// Created by jakub on 01.11.2019.
//

#include "../../headers/updaters/AgeUpdater.h"


void AgeUpdater::update(double dt, Container *p) {
    size_t endId = p->countAlive;
    const float timeDelta = (float) dt;
    
    for (size_t i = 0; i < endId; i++) {
        p->age[i] -= timeDelta / 10.0;
        if (p->age[i] < 0) {
            p->killParticle(i);
            endId = p->countAlive;
        }
    }
}