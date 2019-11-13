//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_COLORUPDATER_H
#define MYPARTICLESYSTEM_COLORUPDATER_H


#include "Updater.h"

class ColorUpdater : public Updater {
public:
    virtual void update(double dt, Container *p) override;
};

#endif //MYPARTICLESYSTEM_COLORUPDATER_H
