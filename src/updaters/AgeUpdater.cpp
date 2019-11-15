//
// Created by jakub on 01.11.2019.
//

#include "../../headers/updaters/AgeUpdater.h"


void AgeUpdater::update(double dt, Container *p) {
    size_t endId = p->countAlive;
    const float timeDelta = (float) dt;
    
    for (size_t i = 0; i < endId; i++) {
        p->age[i].x -= timeDelta;
        if (p->age[i].x < 0) {
            p->killParticle(i);
            endId = p->countAlive;
        }
    }
}