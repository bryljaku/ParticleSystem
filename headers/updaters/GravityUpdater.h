//
// Created by jakub on 14.11.2019.
//

#ifndef MYPARTICLESYSTEM_GRAVITYUPDATER_H
#define MYPARTICLESYSTEM_GRAVITYUPDATER_H


#include "Updater.h"

class GravityUpdater : public Updater {
private:
    std::vector<glm::vec4> gravityPoints;
public:
    void addGravityPoint(glm::vec4 gravityPoint) {gravityPoints.push_back(gravityPoint);}
    void updateMouseMovement(glm::vec4 mouse) {gravityPoints[0] = mouse;};
    virtual void update(double dt, Container *p) override;
};


#endif //MYPARTICLESYSTEM_GRAVITYUPDATER_H
