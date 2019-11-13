//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_POSITIONUPDATER_H
#define MYPARTICLESYSTEM_POSITIONUPDATER_H


#include "Updater.h"

class PositionUpdater : public Updater {
public:
    int maxWidth;
    int maxHeight;
    virtual void update(double dt, Container *p) override;
};


#endif //MYPARTICLESYSTEM_POSITIONUPDATER_H
