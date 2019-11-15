//
// Created by jakub on 14.11.2019.
//

#ifndef MYPARTICLESYSTEM_MASSGENERATOR_H
#define MYPARTICLESYSTEM_MASSGENERATOR_H


#include "Generator.h"

class MassGenerator : public Generator {
public:
    virtual void generate(Container *p, size_t startId, size_t endId) override;
};


#endif //MYPARTICLESYSTEM_MASSGENERATOR_H
