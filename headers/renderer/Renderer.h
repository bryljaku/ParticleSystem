//
// Created by jakub on 02.11.2019.
//

#ifndef MYPARTICLESYSTEM_RENDERER_H
#define MYPARTICLESYSTEM_RENDERER_H


#include "../system/System.h"

class Renderer {
public:
    Renderer() {}
    virtual ~Renderer() {}
    virtual void generate(System *system) = 0;
    virtual void destroy() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};


#endif //MYPARTICLESYSTEM_RENDERER_H
