#include <vector>
#include <cstdlib>
#include <glm/vec3.hpp>
#include <glm/vec3.hpp>
#include <iostream>
#include "../headers/system/System.h"
#include "../headers/generators/BasicPositionGenerator.h"
#include "../headers/generators/BasicColorGenerator.h"
#include "../headers/updaters/PositionUpdater.h"
#include "../headers/updaters/ColorUpdater.h"
#include "../headers/updaters/AgeUpdater.h"
#include "../headers/updaters/VelocityUpdater.h"
#include "../headers/updaters/GravityUpdater.h"
#include "../headers/generators/VelocityGenerator.h"
#include "../headers/generators/AccelerationGenerator.h"
#include "../headers/generators/AgeGenerator.h"
#include "../headers/SOIL/SOIL.h"
#include "../headers/updaters/ColorUpdater.h"
#include "../headers/generators/MassGenerator.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

const float DELTA = 2;
const int NUMBER_OF_PARTICLES = 3000;
const float LENGTH = 100.0;
const int POINT_SIZE = 3;
const int MIN_INIT_VELOCITY = 10;
const int MAX_INIT_VELOCITY = 100;
const int MAX_VELOCITY = 200;

const int MIN_MASS = 2;
const int MAX_MASS = 8;
const float EMIT_RATE = 5;
const int FORCE_MAG = 2000;
const int MAX_PARTICLES = 5000;
float win_width = 1280, win_height = 720;
glm::vec3 mouse{1.0f};
std::shared_ptr<System> syst;
std::shared_ptr<GravityUpdater> gravityUpdater;
void handle_keypress(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'a':
        case 'A':
            for (auto emitter: syst.get()->emitters)
                emitter.get()->emit(syst.get()->particles(), DELTA);
            break;
        
        case 'd':
        case 'D':
            syst.get()->container.killParticles(5);
            break;
    
        case 's':
        case 'S':
            std::cout << 'x' << syst.get()->particles()->position.get()[0].x << std::endl;
            std::cout << 'y' << syst.get()->particles()->position.get()[0].y << std::endl;
            std::cout << 'ax' << syst.get()->particles()->acceleration.get()[0].x << std::endl;
            std::cout << 'ay' << syst.get()->particles()->acceleration.get()[0].y << std::endl;
            std::cout << 'a' << syst.get()->particles()->age.get()[0] << std::endl;
            break;
        case 'n':
        case 'N':
            std::cout << syst.get()->numberOfAliveParticles() << std::endl;
            break;
        
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-LENGTH, LENGTH, -LENGTH, LENGTH, -LENGTH, LENGTH);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glColor3ub( 255, 255, 255 );
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
    glVertexPointer( 2, GL_FLOAT, sizeof(glm::vec3), &syst.get()->container.position.get()[0].x);
    glColorPointer( 4, GL_FLOAT, sizeof(glm::vec3), &syst.get()->container.color.get()[0].x);
    glPointSize( POINT_SIZE );
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glDrawArrays( GL_POINTS, 0, syst.get()->numberOfAliveParticles() );
    glDisableClientState( GL_VERTEX_ARRAY );
    glDisableClientState( GL_COLOR_ARRAY );
    syst.get()->update(DELTA);
    
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    //setup windows width and height
    win_width = (w==0) ? 1 : w;
    win_height = (h==0) ? 1 : h;
    
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, win_width, win_height);
    
    //Switch to setting the camera perspective
    glMatrixMode(GL_PROJECTION);
    
    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    glOrtho(-LENGTH, LENGTH, -LENGTH, LENGTH, -LENGTH, LENGTH);
    
    glMatrixMode(GL_MODELVIEW);
}
void init()
{
    // Make big points and wide lines
    glPointSize(3);
    
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    
    //Enable transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void mouse_movement(int x, int y ){
    float ww_ratio = float(x)/win_width;
    float wh_ratio = float(y)/win_height;
    gravityUpdater->updateGravityPoint(glm::vec3((2*ww_ratio-1)*LENGTH, (1-2*wh_ratio)*LENGTH, 0));
}
int main(int argc, char **argv)
{
    auto emitter = std::make_shared<Emitter>();
    emitter.get()->emitRate = EMIT_RATE;
    auto positionGenerator = std::make_shared<BasicPositionGenerator>();
    syst = std::make_shared<System>(MAX_PARTICLES);
    auto colorGenerator = std::make_shared<BasicColorGenerator>();
    auto ageGenerator = std::make_shared<AgeGenerator>();
    auto massGenerator = std::make_shared<MassGenerator>();
    auto velocityGenerator = std::make_shared<VelocityGenerator>();
    auto accelerationGenerator = std::make_shared<AccelerationGenerator>();
    auto positionUpdater = std::make_shared<PositionUpdater>();
    positionUpdater.get()->maxWidth = LENGTH;
    positionUpdater.get()->maxHeight = LENGTH;
    auto velocityUpdater = std::make_shared<VelocityUpdater>();
    auto ageUpdater = std::make_shared<AgeUpdater>();
    auto colorUpdater = std::make_shared<ColorUpdater>();
    gravityUpdater = std::make_shared<GravityUpdater>();
    gravityUpdater.get()->updateGravityPoint(mouse);
    emitter.get()->addGenerator(positionGenerator);
    emitter.get()->addGenerator(colorGenerator);
    emitter.get()->addGenerator(ageGenerator);
    emitter.get()->addGenerator(velocityGenerator);
    emitter.get()->addGenerator(accelerationGenerator);
    syst.get()->addEmitter(emitter);
    syst.get()->addUpdater(gravityUpdater);
    syst.get()->addUpdater(velocityUpdater);
    syst.get()->addUpdater(positionUpdater);
    syst.get()->addUpdater(ageUpdater);
//    syst.get()->addUpdater(colorUpdater);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(win_width, win_height);
    glutCreateWindow("Particle System");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handle_keypress);
    glutPassiveMotionFunc(mouse_movement);
    glutMainLoop();
    return 0;
}