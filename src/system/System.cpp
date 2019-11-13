//
// Created by jakub on 01.11.2019.
//

#include "../../headers/system/System.h"

System::System(size_t maxNumberOfParticles) {
    maxNumberOfParticles = maxNumberOfParticles;
    container.generate(maxNumberOfParticles);
    
    for (size_t i = 0; i < maxNumberOfParticles; ++i)
        container.isAlive[i] = false;
}

void System::update(double dt) {
    for (auto & emmiter : emitters)
        emmiter->emit(&container, dt);
    
    for (auto & updater : updaters)
        updater->update(dt, &container);
}

void System::draw() {
    
    size_t aliveParticles = numberOfAliveParticles();
    particles();
    for (size_t i = 0; i < aliveParticles; i++) {
        auto color = container.color[i];
        auto position = container.position[i];
            
            glColor4f(color.x, color.y, color.z, 1);
            glBegin(GL_POINTS);
            glVertex3f(position.x, position.y, position.z);
            glEnd();
        }
        
    
}
