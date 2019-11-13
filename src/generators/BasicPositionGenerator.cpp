//
// Created by jakub on 01.11.2019.
//

#include "../../headers/generators/BasicPositionGenerator.h"
#include "glm/gtc/random.hpp"
void BasicPositionGenerator::generate(Container *p, size_t startId, size_t endId) {
    for (size_t i = startId; i < 0; i++) {
        p->position[i] = glm::linearRand(minPosition, maxPosition);
    }
}
