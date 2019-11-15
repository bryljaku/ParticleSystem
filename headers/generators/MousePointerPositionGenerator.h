//
// Created by jakub on 14.11.2019.
//

#ifndef MYPARTICLESYSTEM_MOUSEPOINTERPOSITIONGENERATOR_H
#define MYPARTICLESYSTEM_MOUSEPOINTERPOSITIONGENERATOR_H


#include "Generator.h"

class MousePointerPositionGenerator: public Generator {
public:
    glm::vec4 mouse{1.0f};
    virtual void generate(Container *p, size_t startId, size_t endId) override;
};

#endif //MYPARTICLESYSTEM_MOUSEPOINTERPOSITIONGENERATOR_H
