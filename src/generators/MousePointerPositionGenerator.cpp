//
// Created by jakub on 14.11.2019.
//

#include "../../headers/generators/MousePointerPositionGenerator.h"

void MousePointerPositionGenerator::generate(Container *p, size_t startId, size_t endId) {
    for (size_t i = startId; i < 0; i++) {
        p->position[i] = mouse;
    }
}
