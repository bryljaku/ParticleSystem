//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_BASICPOSITIONGENERATOR_H
#define MYPARTICLESYSTEM_BASICPOSITIONGENERATOR_H


#include "Generator.h"

class BasicPositionGenerator : public Generator {
public:
    glm::vec3 maxPosition {100.0};
    glm::vec3 minPosition {0.0};
    virtual void generate(Container *p, size_t startId, size_t endId) override;
};


#endif //MYPARTICLESYSTEM_BASICPOSITIONGENERATOR_H
