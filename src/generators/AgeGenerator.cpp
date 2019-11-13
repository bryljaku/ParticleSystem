//
// Created by jakub on 01.11.2019.
//

#include "../../headers/generators/AgeGenerator.h"
#include <glm/gtc/random.hpp>

void AgeGenerator::generate(Container *p, size_t startId, size_t endId) {
    for (size_t i = startId; i < endId; i++) {
        p->age[i].x = glm::linearRand(minAge, maxAge); //age left to die
        p->age[i].y = p->age[i].x / maxAge; // it will be used to mix colors
        p->age[i].z = 0.0; // same ^
    }
}