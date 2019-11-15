//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_ACCELERATIONGENERATOR_H
#define MYPARTICLESYSTEM_ACCELERATIONGENERATOR_H

#include "Generator.h"

class AccelerationGenerator : public Generator {
    public:
        glm::vec3 maxAcceleration{1.0};
        glm::vec3 minAcceleration{-1.0};
        void generate(Container *p, size_t startId, size_t endId) override;
};


#endif //MYPARTICLESYSTEM_ACCELERATIONGENERATOR_H
