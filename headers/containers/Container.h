//
// Created by jakub on 01.11.2019.
//

#include <bits/unique_ptr.h>

#ifndef MYPARTICLESYSTEM_PARTICLECONTAINER_H
#define MYPARTICLESYSTEM_PARTICLECONTAINER_H
#include <vector>
#include <memory>
#include <glm/vec4.hpp>

class Container {
public:
    size_t countAlive;
    size_t maxSize;
    std::unique_ptr<glm::vec4[]> position;
    std::unique_ptr<glm::vec4[]> color;
    std::unique_ptr<glm::vec4[]> velocity;
    std::unique_ptr<glm::vec4[]> acceleration;
    std::unique_ptr<glm::vec4[]> age;
    std::unique_ptr<bool[]> isAlive;
    
    Container() {};
    explicit Container(size_t maxNumberOfParticles) { generate(maxNumberOfParticles);}
    ~Container() {};
    
    Container &operator=(const Container&) = delete;
    
    void generate(size_t maxParticles);
    void swapParticles(size_t a, size_t b);
    void killParticle(size_t id);
    void wakeParticle(size_t id);
};
#endif //MYPARTICLESYSTEM_PARTICLECONTAINER_H
