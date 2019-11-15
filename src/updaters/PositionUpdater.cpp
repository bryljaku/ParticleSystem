//
// Created by jakub on 01.11.2019.
//

#include "../../headers/updaters/PositionUpdater.h"

void PositionUpdater::update(double dt, Container *p) {
    size_t endId = p->countAlive;
    float timeDelta = (float) dt / 10.0;
    float maxHeight2 = maxHeight/2;
    float maxWidth2 = maxWidth/2;
    
    for (size_t i = 0; i < endId; i++) {
        p->position[i] += p->velocity[i] * timeDelta;
        if (p->position[i].x <-maxWidth2)
            p->position[i].x = maxWidth2;
        else if (p->position[i].x >= maxWidth2)
            p->position[i].x = -maxWidth2;
        if (p->position[i].y <= -maxHeight2)
            p->position[i].y = maxHeight2;
        else if (p->position[i].y >= maxHeight2)
            p->position[i].y = -maxHeight2;
    }
}
