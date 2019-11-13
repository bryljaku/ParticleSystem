//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_EMITTER_H
#define MYPARTICLESYSTEM_EMITTER_H


#include "../generators/Generator.h"

class Emitter {
public:
    float emitRate;
    std::vector<std::shared_ptr<Generator>> generators;
    void emit(Container *particleContainer, double  timeDelta);
    void addGenerator(const std::shared_ptr<Generator>&);
};


#endif //MYPARTICLESYSTEM_EMITTER_H
