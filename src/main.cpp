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
#include "../headers/generators/VelocityGenerator.h"
#include "../headers/generators/AccelerationGenerator.h"
#include "../headers/generators/AgeGenerator.h"
#include "../headers/SOIL/SOIL.h"
#include "../headers/updaters/ColorUpdater.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

std::shared_ptr<System> syst;
void handle_keypress(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'a':
        case 'A':
            syst.get()->container.wakeParticle(10);
            break;
        
        case 'd':
        case 'D':
            syst.get()->container.killParticle(10);
            break;
        
        case 's':
        case 'S':
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
    glVertexPointer( 4, GL_FLOAT, sizeof(glm::vec4), &syst.get()->container.position.get()[0].x);
    glColorPointer( 4, GL_FLOAT, sizeof(glm::vec4), &syst.get()->container.color.get()[0].x);
    glPointSize( 5 );
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glDrawArrays( GL_POINTS, 0, syst.get()->numberOfAliveParticles() );
    glDisableClientState( GL_VERTEX_ARRAY );
    glDisableClientState( GL_COLOR_ARRAY );
    
    glFlush();
    glutSwapBuffers();
    syst.get()->update(1);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
}

int main(int argc, char **argv)
{
    auto emitter = std::make_shared<Emitter>();
    auto positionGenerator = std::make_shared<BasicPositionGenerator>();
    syst = std::make_shared<System>(15000);
    auto colorGenerator = std::make_shared<BasicColorGenerator>();
    auto ageGenerator = std::make_shared<AgeGenerator>();
    auto velocityGenerator = std::make_shared<VelocityGenerator>();
    auto accelerationGenerator = std::make_shared<AccelerationGenerator>();
    auto positionUpdater = std::make_shared<PositionUpdater>();
    auto velocityUpdater = std::make_shared<VelocityUpdater>();
    auto ageUpdater = std::make_shared<AgeUpdater>();
    auto colorUpdater = std::make_shared<ColorUpdater>();
    emitter.get()->addGenerator(positionGenerator);
    emitter.get()->addGenerator(colorGenerator);
    emitter.get()->addGenerator(ageGenerator);
    emitter.get()->addGenerator(velocityGenerator);
    emitter.get()->addGenerator(accelerationGenerator);
    syst.get()->addEmitter(emitter);
    syst.get()->addUpdater(velocityUpdater);
    syst.get()->addUpdater(positionUpdater);
    syst.get()->addUpdater(ageUpdater);
    syst.get()->addUpdater(colorUpdater);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(640,480);
    glutCreateWindow("Particle System");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handle_keypress);
    
    glutMainLoop();
    return 0;
}














//const float DELTA = 1;
//const int NUMBER_OF_PARTICLES = 3000;
//const float LENGTH = 100.0;
//
//const int MIN_INIT_VELOCITY = 10;
//const int MAX_INIT_VELOCITY = 100;
//const int MAX_VELOCITY = 200;
//
//const int MIN_MASS = 2;
//const int MAX_MASS = 8;
//
//const int FORCE_MAG = 2000;
//
//const int MAX_PARTICLES = 10000;
//float win_width = 400, win_height = 400;
//
//
//std::shared_ptr<System> syst;
//
//void handle_keypress(unsigned char key, int x, int y){
//    switch(key){
//        case 27:
//            exit(0);
//            break;
//    }
//    glutPostRedisplay();
//}
//
//void draw()
//{
//    glLoadIdentity();
//    //Draw particles
//    glPushMatrix();
//        syst.get()->update(1000);
//        syst.get()->draw();
//    glPopMatrix();
//
//    //Draw overlaying quad for trail
//    glColor4f(0, 0, 0, 0.1);
//    glBegin(GL_QUADS);
//    glVertex3f(-LENGTH, -LENGTH, 100);
//    glVertex3f(LENGTH, -LENGTH, 100);
//    glVertex3f(LENGTH, LENGTH, 100);
//    glVertex3f(-LENGTH, LENGTH, 100);
//    glEnd();
//
//    glutSwapBuffers();
//    glutPostRedisplay();
//}
//
//void handle_resize(int w, int h)
//{
//    //setup windows width and height
//    win_width = (w==0) ? 1 : w;
//    win_height = (h==0) ? 1 : h;
//
//    //Tell OpenGL how to convert from coordinates to pixel values
//    glViewport(0, 0, win_width, win_height);
//
//    //Switch to setting the camera perspective
//    glMatrixMode(GL_PROJECTION);
//
//    //Set the camera perspective
//    glLoadIdentity(); //Reset the camera
//    glOrtho(-LENGTH, LENGTH, -LENGTH, LENGTH, -LENGTH, LENGTH);
//
//    glMatrixMode(GL_MODELVIEW);
//}
//void init()
//{
//    // Make big points and wide lines
//    glPointSize(3);
//
//    glEnable(GL_POINT_SMOOTH);
//    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
//    //Enable transparency
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//}
//int main(int argc, char** argv) {
//
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowSize(win_width, win_height); //Set the window size
//
//    //Create the window and initialize OpenGL
//    glutCreateWindow("Particle System");
//
//
//    //Set handler functions for drawing, keypresses, and window resizes
//    glutDisplayFunc(draw);
//    glutKeyboardFunc(handle_keypress);
//    glutReshapeFunc(handle_resize);
//    glutFullScreen();
//
//    glutMainLoop();
//    return 0;
//}