#include <GL/glut.h>

int w = 200, h = 200;

float degree = 0;

GLfloat DIFFUSE[] = { 1.0, 1.0 };
GLfloat SPECULAR[] = { 0.1, 0.1 };
GLfloat SHININESS[] = { 5.0 };

void right(void)
{
	glLoadIdentity();

	degree += 0.5;
}

void left(void)
{
	glLoadIdentity();

	degree -= 0.5;
}

void init(void)
{
	glClearColor(1, 1, 1, 1);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_COLOR_MATERIAL);

	glColorMaterial(GL_FRONT, GL_DIFFUSE);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void specialFunc(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:left(); break;

	case GLUT_KEY_RIGHT:right(); break;
	}

	glutPostRedisplay();
}

void cube(void)
{
	glRotatef(degree, 0.0, 1.0, 0.0);

	glColor3f(1.0, 0.0, 0.0);

	glutSolidCube(1.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SPECULAR);
	glMaterialfv(GL_FRONT, GL_SHININESS, SHININESS);

	glLoadIdentity();

	gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	cube();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if (w <= h)

		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,

			1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);

	else

		glOrtho(-1.5 * (GLfloat)w / (GLfloat)h,

			1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(w, h);

	glutInitWindowPosition(0, 0);

	glutCreateWindow("glColorMaterial");

	init();

	glutReshapeFunc(reshape);

	glutDisplayFunc(display);

	glutSpecialFunc(specialFunc);



	glutMainLoop();

	return 0;
}