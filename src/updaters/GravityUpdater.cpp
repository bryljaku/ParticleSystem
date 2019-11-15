//
// Created by jakub on 14.11.2019.
//

#include "../../headers/updaters/GravityUpdater.h"

void GravityUpdater::update(double dt, Container *p) {
    size_t endId = p-> countAlive;
    float timeDelta = (float) dt;
    
    glm::vec4 dist;
    for (int i = 0; i < endId; i++)
        for (int j = 0; j < gravityPoints.size(); j++) {
            dist.x = p->position[i].x - gravityPoints[j].x;
            dist.y = p->position[i].y - gravityPoints[j].y;
            
            dist = gravityPoints[j] / dist ;
            dist *= p->mass[i];
            p->acceleration[i] += dist;
        }
}
