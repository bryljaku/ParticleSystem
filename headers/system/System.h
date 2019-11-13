//
// Created by jakub on 01.11.2019.
//

#ifndef MYPARTICLESYSTEM_SYSTEM_H
#define MYPARTICLESYSTEM_SYSTEM_H


#include "../emitters/Emitter.h"
#include "../updaters/Updater.h"
#ifdef __APPLE__
#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#endif
class System {
protected:
    size_t maxNumberOfParticles;
    std::vector<std::shared_ptr<Emitter>> emitters;
    std::vector<std::shared_ptr<Updater>> updaters;
public:
    Container container;
    explicit System(size_t maxNumberOfParticles);
    ~System() { }
    
    System &operator=(const System&) = delete;
    
    void update(double dt);
    
    void draw();
    
    virtual size_t numberOfAliveParticles() const  {return container.countAlive;}
    virtual size_t maxParticles() const  {return container.maxSize;}
    
    void addEmitter(std::shared_ptr<Emitter> emitter) {emitters.push_back(emitter);}
    void addUpdater(std::shared_ptr<Updater> updater) {updaters.push_back(updater);}
    Container  *particles() { return &container; }
    
};

#endif //MYPARTICLESYSTEM_SYSTEM_H
