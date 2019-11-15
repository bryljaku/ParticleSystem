//
// Created by jakub on 01.11.2019.
//

#include <cmath>
#include "../../headers/updaters/VelocityUpdater.h"
float mag(glm::vec3 vec);
glm::vec3 limitSpeed(glm::vec3 vec);

void VelocityUpdater::update(double dt, Container *p) {
    size_t endId = p-> countAlive;
    float timeDelta = (float) dt;
    
    for (size_t i = 0; i < endId; i++) {
        p->velocity[i] +=  p->acceleration[i];
        if(mag(p->velocity[i]) >= maxVelocity.x)
            p->velocity[i] = limitSpeed(p->velocity[i]) *  maxVelocity.x;
    
    }
}

float mag(glm::vec3 vec)
{
    float x = vec.x;
    float y = vec.y;
    float z = vec.z;
    return sqrt(x*x + y*y + z*z);
}
glm::vec3 limitSpeed(glm::vec3 vec) {
    float m = mag(vec);
    if(m == 0)
        throw "invalid vector";
    return glm::vec3(vec.x/m, vec.y/m, vec.z/m);
}
