//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_GENERATOR_H
#define MYPARTICLESYSTEM_GENERATOR_H

#include "../containers/Container.h"

class Generator {
public:
    Generator() { }
    virtual ~Generator() { }
    virtual void generate(Container *p, size_t startId, size_t endId) = 0;
};


#endif //MYPARTICLESYSTEM_GENERATOR_H
