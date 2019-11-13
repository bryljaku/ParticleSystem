//
// Created by jakub on 01.11.2019.
//

#include <glm/gtc/random.hpp>
#include "../../headers/generators/VelocityGenerator.h"

void VelocityGenerator::generate(Container *p, size_t startId, size_t endId) {
    for (size_t i = startId; i < endId; i++)
        p->velocity[i] = glm::linearRand(minVelocity, maxVelocity);
}
