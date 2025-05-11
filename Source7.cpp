#include <GL/glut.h>

GLfloat mat_specular[] = { 1, 1, 1, 1 };
GLfloat mat_shinines[] = { 20.0 };
GLfloat light_position[] = { 0.0, 1.0, 1.0, 0.0 };
GLfloat blue_light[] = { 0.0, 0.0, 1.0, 0.0 };
GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 0.1 };

GLfloat red_light[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat light_position2[] = { -1.0, -1.0, 1.0, 0.0 };

GLfloat green_light[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat light_position3[] = { 1.0, -1.0, 1.0, 0.0 };

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shinines);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, blue_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, blue_light);

    glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, red_light);
    glLightfv(GL_LIGHT1, GL_SPECULAR, red_light);

    glLightfv(GL_LIGHT2, GL_POSITION, light_position3);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, green_light);
    glLightfv(GL_LIGHT2, GL_SPECULAR, green_light);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSolidSphere(1.0, 40, 20);

    glFlush();
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

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(500, 500);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("glLightfv");

    init();

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
