//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_VELOCITYUPDATER_H
#define MYPARTICLESYSTEM_VELOCITYUPDATER_H


#include "Updater.h"

class VelocityUpdater : public Updater {
public:
    virtual void update(double dt, Container *p) override;
};

#endif //MYPARTICLESYSTEM_VELOCITYUPDATER_H
