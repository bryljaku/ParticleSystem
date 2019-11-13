//
// Created by jakub on 01.11.2019.
//

#include "../../headers/emitters/Emitter.h"

void Emitter::emit(Container *particleContainer, double timeDelta) {
    const size_t numberOfParticlesToEmit = (size_t) timeDelta * emitRate;
    const size_t startId = particleContainer->countAlive;
    const size_t endId = std::min(startId + numberOfParticlesToEmit, particleContainer->maxSize - 1);
    
    for (auto &gen: generators)
        gen->generate(particleContainer, startId, endId);
    
    for (int i = startId; i < endId; i++)
        particleContainer->wakeParticle(i);
}

void Emitter::addGenerator(const std::shared_ptr<Generator>& generator) {
    generators.push_back(generator);
}
