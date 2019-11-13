//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_AGEGENERATOR_H
#define MYPARTICLESYSTEM_AGEGENERATOR_H


#include "Generator.h"

class AgeGenerator : public Generator{

public:
    float maxAge{0.0};
    float minAge{5.0};
    
    virtual void generate(Container *p, size_t startId, size_t endId) override;
};


#endif //MYPARTICLESYSTEM_AGEGENERATOR_H
