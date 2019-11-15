//
// Created by jakub on 01.11.2019.
//

#include "../../headers/updaters/PositionUpdater.h"

void PositionUpdater::update(double dt, Container *p) {
    size_t endId = p->countAlive;
    float timeDelta = (float) dt / 1000.0;
    
    for (size_t i = 0; i < endId; i++) {
        p->position[i] += p->velocity[i] * timeDelta;
        if (p->position[i].x < -maxWidth){
            p->position[i].x = maxWidth;
        }
        else if (p->position[i].x >= maxWidth){
            p->position[i].x = -maxWidth;
        }
        if (p->position[i].y <= -maxHeight){
            p->position[i].y = maxHeight;
        }
        else if (p->position[i].y >= maxHeight){
            p->position[i].y = -maxHeight;
        }
    }
}
