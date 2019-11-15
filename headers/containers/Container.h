//
// Created by jakub on 01.11.2019.
//

#include <bits/unique_ptr.h>

#ifndef MYPARTICLESYSTEM_PARTICLECONTAINER_H
#define MYPARTICLESYSTEM_PARTICLECONTAINER_H
#include <vector>
#include <memory>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

class Container {
public:
    size_t countAlive;
    size_t maxSize;
    std::unique_ptr<glm::vec3[]> position;
    std::unique_ptr<int[]> mass;
    std::unique_ptr<glm::vec3[]> color;
    std::unique_ptr<glm::vec3[]> velocity;
    std::unique_ptr<glm::vec3[]> acceleration;
    std::unique_ptr<int[]> age;
    std::unique_ptr<bool[]> isAlive;
    
    Container() {};
    explicit Container(size_t maxNumberOfParticles) { generate(maxNumberOfParticles);}
    ~Container() {};
    
    Container &operator=(const Container&) = delete;
    
    void generate(size_t maxParticles);
    void swapParticles(size_t a, size_t b);
    void killParticle(size_t id);
    void killParticles(size_t number);
    void wakeParticle(size_t id);
};
#endif //MYPARTICLESYSTEM_PARTICLECONTAINER_H
