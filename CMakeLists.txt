cmake_minimum_required(VERSION 3.15)
project(MyParticleSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyParticleSystem src/main.cpp headers/containers/Container.h src/containers/Container.cpp src/emitters/Emitter.cpp headers/emitters/Emitter.h headers/generators/Generator.h headers/updaters/Updater.h src/updaters/AgeUpdater.cpp headers/updaters/AgeUpdater.h src/generators/AgeGenerator.cpp headers/generators/AgeGenerator.h src/generators/VelocityGenerator.cpp headers/generators/VelocityGenerator.h src/generators/AccelerationGenerator.cpp headers/generators/AccelerationGenerator.h src/generators/BasicColorGenerator.cpp headers/generators/BasicColorGenerator.h src/generators/BasicPositionGenerator.cpp headers/generators/BasicPositionGenerator.h src/updaters/VelocityUpdater.cpp headers/updaters/VelocityUpdater.h src/updaters/PositionUpdater.cpp headers/updaters/PositionUpdater.h src/system/System.cpp headers/system/System.h headers/SOIL/SOIL.h)

target_link_libraries(MyParticleSystem -lGLEW -lglut -lGL -lGLU)