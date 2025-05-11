#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glVertex2f(1, 0);
	glVertex2f(-1, 0);
	glEnd();

	glFlush();
}

void triangle(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0, 0.5);
	glEnd();

	glFlush();
}

void quad(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);
	glEnd();

	glFlush();
}

void circle(void)
{
	double rad = 0;
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (int a = 0; a < 360; a++)
	{
		rad = 2 * 3.14 * a / 360;
		glVertex2f(cos(rad) * 0.5, sin(rad) * 0.5);
	}
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Ýlk Program");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_FLAT);
	glutDisplayFunc(circle);

	glutMainLoop();
	return 0;
}