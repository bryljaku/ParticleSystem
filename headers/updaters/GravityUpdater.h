//
// Created by jakub on 14.11.2019.
//

#ifndef MYPARTICLESYSTEM_GRAVITYUPDATER_H
#define MYPARTICLESYSTEM_GRAVITYUPDATER_H


#include "Updater.h"

class GravityUpdater : public Updater {
private:
    glm::vec3 gravityPoint;
    float forceMagnitude = 10.0f;
public:
    void updateGravityPoint(glm::vec3 mouse) {gravityPoint = mouse;};
    virtual void update(double dt, Container *p) override;
};


#endif //MYPARTICLESYSTEM_GRAVITYUPDATER_H
