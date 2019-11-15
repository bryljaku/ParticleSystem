//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_BASICCOLORGENERATOR_H
#define MYPARTICLESYSTEM_BASICCOLORGENERATOR_H


#include "Generator.h"

class BasicColorGenerator : public Generator{
public:
    glm::vec3 minColor {0.0};
    glm::vec3 maxColor {1.0};
    virtual void generate(Container *p, size_t startId, size_t endId) override;
};


#endif //MYPARTICLESYSTEM_BASICCOLORGENERATOR_H
