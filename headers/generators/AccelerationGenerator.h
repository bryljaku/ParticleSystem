//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_ACCELERATIONGENERATOR_H
#define MYPARTICLESYSTEM_ACCELERATIONGENERATOR_H

#include "Generator.h"

class AccelerationGenerator : public Generator {
    public:
        glm::vec4 maxAcceleration{5.0};
        glm::vec4 minAcceleration{-5.0};
        void generate(Container *p, size_t startId, size_t endId) override;
};


#endif //MYPARTICLESYSTEM_ACCELERATIONGENERATOR_H
