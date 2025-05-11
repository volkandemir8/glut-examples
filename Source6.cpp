#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

int en = 400, boy = 400;

float derece = 0;

float xolcu = 1, yolcu = 1, zolcu = 1;

float xpos = 0, ypos = 0, zpos = 0;

void yanuzat(void)
{
	glLoadIdentity();
	xolcu += 0.1;
}
void yankisalt(void)
{
	glLoadIdentity();
	xolcu -= 0.1;
}
void boyuzat(void)
{
	glLoadIdentity();
	yolcu += 0.1;
}
void boykisalt(void)
{
	glLoadIdentity();
	yolcu -= 0.1;
}
void cevirsol(void)
{
	glLoadIdentity();
	derece -= 5;
}
void cevirsag(void)
{
	glLoadIdentity();
	derece += 5;
}
void goturyukari(void)
{
	ypos += 0.1;
}
void goturasagi(void)
{
	ypos -= 0.1;
}
void gotursag(void)
{
	xpos += 0.1;
}
void gotursol(void)
{
	xpos -= 0.1;
}
void goturiceri(void)
{
	zpos += 0.1;
}
void goturdisari(void)
{
	zpos -= 0.1;
}

void keyFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '7':
		yanuzat();
		break;
	case '9':
		yankisalt();
		break;
	case '8':
		boyuzat();
		break;
	case '2':
		boykisalt();
		break;
	case '4':
		cevirsol();
		break;
	case '6':
		cevirsag();
		break;
	case 'w':
		goturyukari();
		break;
	case 's':
		goturasagi();
		break;
	case 'd':
		gotursag();
		break;
	case 'a':
		gotursol();
		break;
	case '1':
		goturiceri();
		break;
	case '3':
		goturdisari();
		break;
	}

	glutPostRedisplay();
}

void ucbcokgen(void)
{
	glColor3f(0.5, 0.1, 0.1);

	glTranslatef(xpos, ypos, zpos);

	glRotatef(derece, 0.0, 1.0, 0.0);

	glScalef(xolcu, yolcu, zolcu);

	glutWireCube(1.0);
}

void ciz(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	glLoadIdentity();

	gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	ucbcokgen();

	glutSwapBuffers();
}

void reshape(int en, int boy)
{
	glViewport(0, 0, en, boy);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(90, (float)en / (float)boy, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(en, boy);

	glutInitWindowPosition(150, 100);

	glutCreateWindow("3bcokgen2");

	glClearColor(1.0, 1.0, 1.0, 1.0);

	glShadeModel(GL_FLAT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glutReshapeFunc(reshape);

	glutDisplayFunc(ciz);

	glutKeyboardFunc(keyFunc);


	glutMainLoop();

	return 0;
}