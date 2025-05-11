#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <math.h>

GLfloat angle = 0.0;

GLfloat red = 0.0, blue = 0.0, green = 0.0;


void displayFunc(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glRotatef(angle, 0.0, 1.0, 0.0);

    glColor3f(red, green, blue);

    glBegin(GL_TRIANGLES);

    glColor3f(red, green, blue);

    glVertex3f(-1.5, -1.5, 0.0);

    glColor3f(1.0, 0.0, 0.0);

    glVertex3f(1.5, 0.0, 0.0);

    glColor3f(0.0, 1.0, 0.0);

    glVertex3f(0.0, 1.5, 0.0);

    glEnd();

    glPopMatrix();

    angle = angle + 0.05;

    glutSwapBuffers();

}

void reshapeFunc(int n, int h)
{
    if (h == 0)
    {
        h = 1;
    }
    GLfloat ratio = 1.0 * n / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, n, h);
    gluPerspective(45, ratio, 1, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);
}

void specFunc(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_F1:
        red = 1.0;
        green = 0.0;
        blue = 0.0;
        break;
    case GLUT_KEY_F2:
        red = 0.0;
        green = 1.0;
        blue = 0.0;
        break;
    case GLUT_KEY_F3:
        red = 0.0;
        green = 0.0;
        blue = 1.0;
        break;
    }
}

void keyFunc(unsigned char key, int x, int y)
{
    if (key == 27)
    {
        exit(0);
    }
}

void main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(150, 100);

    glutInitWindowSize(400, 400);

    glutCreateWindow("Donen Ucgen");

    glutDisplayFunc(displayFunc);

    glutIdleFunc(displayFunc);

    glutReshapeFunc(reshapeFunc);

    glutSpecialFunc(specFunc);

    glutKeyboardFunc(keyFunc);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

}