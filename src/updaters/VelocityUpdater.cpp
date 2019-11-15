//
// Created by jakub on 01.11.2019.
//

#include "../../headers/updaters/VelocityUpdater.h"

void VelocityUpdater::update(double dt, Container *p) {
    size_t endId = p-> countAlive;
    float timeDelta = (float) dt;
    
    for (size_t i = 0; i < endId; i++) {
        p->velocity[i] +=  p->acceleration[i];
    }
}
