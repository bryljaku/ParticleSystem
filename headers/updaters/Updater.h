//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_UPDATER_H
#define MYPARTICLESYSTEM_UPDATER_H
#include "../containers/Container.h"

class Updater
{
public:
    Updater() { }
    virtual ~Updater() { }
    
    virtual void update(double dt, Container *p) = 0;
};


#endif //MYPARTICLESYSTEM_UPDATER_H
