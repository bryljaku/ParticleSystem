//
// Created by jakub on 01.11.2019.
//

#include "../../headers/updaters/ColorUpdater.h"

void ColorUpdater::update(double dt, Container *p) {
    size_t endId = p-> countAlive;
    float timeDelta = (float) dt;
    
    for (size_t i = 0; i < endId; i++) {
        p->color[i] *=  0.99 ;
    }
}
