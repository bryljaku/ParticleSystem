//
// Created by jakub on 01.11.2019.
//

#include "../../headers/generators/AccelerationGenerator.h"
#include <glm/gtc/random.hpp>

void AccelerationGenerator::generate(Container *p, size_t startId, size_t endId) {
    for (size_t i = startId; i < endId; i++)
        p->velocity[i] = glm::linearRand(minAcceleration, maxAcceleration);
}