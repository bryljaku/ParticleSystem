//
// Created by jakub on 02.11.2019.
//

#ifndef MYPARTICLESYSTEM_OPENGLRENDERER_H
#define MYPARTICLESYSTEM_OPENGLRENDERER_H


#include "Renderer.h"

class OpenGLRenderer : public Renderer {
protected:
    System * particleSystem{nullptr};
    unsigned int positionBuffer{0};
    unsigned int colorBuffer{0};
    unsigned int vertexArrayObject{0};
public:
    OpenGLRenderer() { }
    ~OpenGLRenderer() { destroy(); }
    virtual void generate(System *system) override;
    virtual void destroy() override;
    virtual void update() override;
    virtual void render() override;
};


#endif //MYPARTICLESYSTEM_OPENGLRENDERER_H
