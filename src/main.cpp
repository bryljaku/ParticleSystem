#include <vector>
#include <cstdlib>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
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

const float DELTA = 1;
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
const int MAX_PARTICLES = 500;
float win_width = 1280, win_height = 720;
glm::vec4 mouse{1000.0f};
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
    glOrtho(-50, 50, -50, 50, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glColor3ub( 255, 255, 255 );
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
    glVertexPointer( 2, GL_FLOAT, sizeof(glm::vec4), &syst.get()->container.position.get()[0].x);
    glColorPointer( 4, GL_FLOAT, sizeof(glm::vec4), &syst.get()->container.color.get()[0].x);
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
    glViewport(0, 0, w, h);
}
void mouse_movement(int x, int y ){
    float ww_ratio = float(x)/LENGTH;
    float wh_ratio = float(y)/LENGTH;
    mouse.x = ww_ratio;
    mouse.y = wh_ratio;
    gravityUpdater->updateMouseMovement(mouse);
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
    gravityUpdater.get()->addGravityPoint(mouse);
    emitter.get()->addGenerator(positionGenerator);
    emitter.get()->addGenerator(colorGenerator);
    emitter.get()->addGenerator(ageGenerator);
    emitter.get()->addGenerator(velocityGenerator);
    emitter.get()->addGenerator(accelerationGenerator);
    syst.get()->addEmitter(emitter);
    syst.get()->addUpdater(gravityUpdater);
    syst.get()->addUpdater(velocityUpdater);
    syst.get()->addUpdater(positionUpdater);
//    syst.get()->addUpdater(ageUpdater);
    syst.get()->addUpdater(colorUpdater);

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