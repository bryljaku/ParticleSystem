//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_AGEUPDATER_H
#define MYPARTICLESYSTEM_AGEUPDATER_H

#include "Updater.h"

class AgeUpdater : public Updater {
public:
    virtual void update(double dt, Container *p) override;
};


#endif //MYPARTICLESYSTEM_AGEUPDATER_H
