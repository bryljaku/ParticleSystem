//
// Created by jakub on 01.11.2019.
//

#include "../../headers/generators/BasicColorGenerator.h"
#include <glm/gtc/random.hpp>

void BasicColorGenerator::generate(Container *p, size_t startId, size_t endId) {
    for (size_t i = startId; i < endId; i++)
        p->color[i] = glm::linearRand(minColor, maxColor);
}
