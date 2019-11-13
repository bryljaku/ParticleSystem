


#include <vector>
#include <cstdlib>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <iostream>
#include "../headers/system/System.h"
#include "../headers/generators/BasicPositionGenerator.h"
#include "../headers/generators/BasicColorGenerator.h"
#include "../headers/updaters/PositionUpdater.h"
#include "../headers/updaters/AgeUpdater.h"
#include "../headers/updaters/VelocityUpdater.h"
#include "../headers/generators/VelocityGenerator.h"
#include "../headers/generators/AccelerationGenerator.h"
#include "../headers/generators/AgeGenerator.h"
#include "../headers/SOIL/SOIL.h"
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

struct Point
{
    glm::vec4 position;
    glm::vec3 color;
};
std::vector< Point > points;
std::shared_ptr<System> syst;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50, 50, -50, 50, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // draw
    glColor3ub( 255, 255, 255 );
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
    glVertexPointer( 2, GL_FLOAT, sizeof(Point), &syst.get()->particles()->position.get()->x );
    glColorPointer( 4, GL_FLOAT, sizeof(Point), &points[0].color.r);
    glPointSize( 3.0 );
    glDrawArrays( GL_POINTS, 0, points.size() );
    glDisableClientState( GL_VERTEX_ARRAY );
    glDisableClientState( GL_COLOR_ARRAY );
    
    glFlush();
    glutSwapBuffers();
    syst.get()->update(100);
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
    ageGenerator.get()->maxAge+=5.0;
    auto velocityGenerator = std::make_shared<VelocityGenerator>();
    auto accelerationGenerator = std::make_shared<AccelerationGenerator>();
    accelerationGenerator.get()->maxAcceleration += 5.0;
    auto positionUpdater = std::make_shared<PositionUpdater>();
    auto velocityUpdater = std::make_shared<VelocityUpdater>();
    auto ageUpdater = std::make_shared<AgeUpdater>();
    emitter.get()->addGenerator(positionGenerator);
    emitter.get()->addGenerator(colorGenerator);
    emitter.get()->addGenerator(ageGenerator);
    emitter.get()->addGenerator(velocityGenerator);
    emitter.get()->addGenerator(accelerationGenerator);
    syst.get()->addEmitter(emitter);
    syst.get()->addUpdater(velocityUpdater);
    syst.get()->addUpdater(positionUpdater);
    syst.get()->addUpdater(ageUpdater);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    
    glutInitWindowSize(640,480);
    glutCreateWindow("Random Points");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    // populate points
    for( size_t i = 0; i < 1000; ++i )
    {
        Point pt;
        pt.position.x = -50 + (rand() % 100);
        pt.position.y = -50 + (rand() % 100);
        pt.color.r = rand() % 255;
        pt.color.g = rand() % 255;
        pt.color.b = rand() % 255;
        pt.color.x = 255;
        points.push_back(pt);
    }
    
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