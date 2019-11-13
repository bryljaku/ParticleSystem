//
// Created by jakub on 01.11.2019.
//

#include "../../headers/containers/Container.h"
#include <assert.h>
#include <algorithm>
#include <memory>
#include <bits/unique_ptr.h>


void Container::generate(size_t maxNumberOfParticles) {
    maxSize = maxNumberOfParticles;
    countAlive = 0;
    acceleration = std::make_unique<glm::vec4[]>(maxSize);
    position = std::make_unique<glm::vec4[]>(maxSize);
    velocity = std::make_unique<glm::vec4[]>(maxSize);
    color = std::make_unique<glm::vec4[]>(maxSize);
    age = std::make_unique<glm::vec4[]>(maxSize);
    isAlive.reset(new bool[maxSize]);
}

void Container::wakeParticle(size_t id) {
    if (countAlive < maxSize) {
        isAlive[id] = true;
        swapParticles(id, countAlive);
        countAlive++;
    }
}

void Container::killParticle(size_t id) {
    if (countAlive > 0) {
        isAlive[id] = false;
        countAlive--;
        swapParticles(id, countAlive);
    }
}
void Container::swapParticles(size_t a, size_t b) {
    std::swap(acceleration[a], acceleration[b]);
    std::swap(position[a], position[b]);
    std::swap(velocity[a], velocity[b]);
    std::swap(isAlive[a], isAlive[b]);
    std::swap(color[a], color[b]);
    std::swap(age[a], age[b]);
}
