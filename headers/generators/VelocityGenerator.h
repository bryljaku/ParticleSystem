//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_VELOCITYGENERATOR_H
#define MYPARTICLESYSTEM_VELOCITYGENERATOR_H


#include "Generator.h"

class VelocityGenerator : public Generator {
public:
    glm::vec3 maxVelocity{-1.0};
    glm::vec3 minVelocity{1.0};
    void generate(Container *p, size_t startId, size_t endId) override;
};


#endif //MYPARTICLESYSTEM_VELOCITYGENERATOR_H
