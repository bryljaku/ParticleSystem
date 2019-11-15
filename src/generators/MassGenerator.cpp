//
// Created by jakub on 14.11.2019.
//

#include "../../headers/generators/MassGenerator.h"

void MassGenerator::generate(Container *p, size_t startId, size_t endId) {
    for (size_t i = startId; i < endId; i++)
        p->mass[i] = 1 + rand() % 4;
}
