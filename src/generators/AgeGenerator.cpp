//
// Created by jakub on 01.11.2019.
//

#include "../../headers/generators/AgeGenerator.h"
#include <glm/gtc/random.hpp>

void AgeGenerator::generate(Container *p, size_t startId, size_t endId) {
    for (size_t i = startId; i < endId; i++) {
        p->age[i] = 10 + rand() % 15;
    }
}