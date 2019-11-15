//
// Created by jakub on 14.11.2019.
//

#include "../../headers/updaters/GravityUpdater.h"

void GravityUpdater::update(double dt, Container *p) {
    size_t endId = p-> countAlive;
    float timeDelta = (float) dt / 20.0;
    
    glm::vec3 force{1.0f};
    for (int i = 0; i < endId; i++){
            force.x = (gravityPoint.x - p->position[i].x) * timeDelta;
            force.y = (gravityPoint.y - p->position[i].y) * timeDelta;
            p->acceleration[i] = force;
    }
}
