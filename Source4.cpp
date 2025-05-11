#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

GLfloat a = 0;

void settings(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}

void triangle(void)
{
	glColor3f(1, 0, 0);
	glLoadIdentity();
	glTranslatef(-0.1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0, 0.3);
	glEnd();
}

void scaleFunc(void)
{
	glColor3f(0, 0, 0);
	glScalef(0.9, 0.9, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.0, 0.3);
	glEnd();
}

void rotateFunc(void)
{
	glColor3f(0.0, 0.0, 0.0);
	glLoadIdentity();
	glRotatef(a, 1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.2, -0.2);
	glVertex2f(0.2, -0.2);
	glVertex2f(0.0, 0.2);
	glEnd();
}

void calc(void)
{
	a = a + 0.1;
	glutPostRedisplay();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//gluOrtho2D(-2, 2, -2, 2);
	glLoadIdentity();
	rotateFunc();
	glLoadIdentity();

	calc();

	glutSwapBuffers();
}

void reshapeFunc(int en, int boy)
{
	glViewport(0, 0, (GLsizei)en, (GLsizei)boy);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (en <= boy)
	{
		gluOrtho2D(-2.0, 2.0, -2.0 * (float)boy / (float)en, 2.0 * (float)boy / (float)en);
	}
	else
		gluOrtho2D(-2.0 * (float)en / (float)boy, 2.0 * (float)en / (float)boy, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Ýlk Program");
	settings();
	glutReshapeFunc(reshapeFunc);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}