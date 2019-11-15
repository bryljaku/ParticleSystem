//
// Created by jakub on 01.11.2019.
//

#include "../../headers/updaters/ColorUpdater.h"

void ColorUpdater::update(double dt, Container *p) {
    size_t endId = p-> countAlive;
    float timeDelta = (float) dt / 10000;
    for (size_t i = 0; i < endId; i++) {
        p->color[i].x =   1 / (p->color[i].x + p->acceleration[i].x * timeDelta);
        p->color[i].y =  1/(p->color[i].y + p->acceleration[i].y * timeDelta);
        p->color[i].z =   1/(p->color[i].z + p->acceleration[i].z * timeDelta);
    }
}
