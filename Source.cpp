#include <GL\glut.h>
#include <math.h>

// Arrow keys to move the robot
// 1, 3, 4, 6 to move the arms

float angle = 0;
float xScale = 1, yScale = 1, zScale = 1;
float xPos = 0, yPos = 0, zPos = 0;
float govdeAci = 0, tekerlekAci = 0;
float omuzAci = 0, dirsekAci = 0, omuzAci2 = 0, dirsekAci2 = 0;
int b = 1, a = 1;
#define DUZELT 0.0174532925

void kolHareketi()
{
    glLoadIdentity();

    if (a == 1)
        omuzAci += 2, omuzAci2 -= 2;

    if (omuzAci >= 45)
        a = 2;

    if (a == 2)
        omuzAci -= 2, omuzAci2 += 2;

    if (omuzAci <= -45)
        a = 1;
}

void yuru(void)
{
    glLoadIdentity();

    tekerlekAci += 2;

    if (tekerlekAci >= 360)
        tekerlekAci = 0;


    if (b == 1)
        govdeAci += 0.5;

    if (govdeAci >= 25)
        b = 2;


    if (b == 2)
        govdeAci -= 0.5;

    if (govdeAci <= 0)
        b = 1;


    kolHareketi();
}

void goturSol(void)
{
    angle += 2;
}

void goturSag(void)
{
    angle -= 2;
}

void goturIleri(void)
{
    xPos += (float)sin(angle * DUZELT) * 0.3;
    zPos += (float)cos(angle * DUZELT) * 0.3;
}

void goturGeri(void)
{
    xPos -= (float)sin(angle * DUZELT) * 0.3;
    zPos -= (float)cos(angle * DUZELT) * 0.3;
}

void solidBox(GLdouble width, GLdouble height, GLdouble depth)
{
    glPushMatrix();
    glScalef(width, height, depth);
    glutSolidCube(1.0);
    glPopMatrix();
}

void mainBody(void)
{
    //Govde
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.3, 0.4);
    //on
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(-1.5, 2.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.5, 2.0, 1.0);
    //arka
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(1.5, 2.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.5, 2.0, -1.0);
    //sag
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(1.5, 2.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.5, 2.0, -1.0);
    //sol
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-1.5, 2.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.5, 2.0, 1.0);
    //ust
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-1.5, 2.0, -1.0);
    glVertex3f(-1.5, 2.0, 1.0);
    glVertex3f(1.5, 2.0, 1.0);
    glVertex3f(1.5, 2.0, -1.0);
    //alt
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
}

void leftShoulder(void)
{
    glTranslatef(1.5, 1.5, 0.0);
    glColor3f(0.0, 0.2, 0.5);
    solidBox(1.0, 0.5, 0.5);
    glTranslatef(0.45, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.2);
    glutSolidSphere(0.45, 20, 20);
    glTranslatef(-0.45, 0.0, 0.0);
    glTranslatef(-1.5, -1.5, 0.0);
}

void rightShoulder(void)
{
    glTranslatef(-1.5, 1.5, 0.0);
    glColor3f(0.0, 0.2, 0.5);
    solidBox(1.0, 0.5, 0.5);
    glTranslatef(-0.45, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.2);
    glutSolidSphere(0.45, 20, 20);
    glTranslatef(0.45, 0.0, 0.0);
    glTranslatef(1.5, -1.5, 0.0);
}

void leftArm(void)
{
    glTranslatef(2.0, 1.5, 0.0);
    glRotatef((GLfloat)omuzAci, 1.0, 0.0, 0.0);
    glTranslatef(-2.0, -1.5, 0.0);

    glTranslatef(2.0, 1.0, 0.0);
    glColor3f(0.0, 0.2, 0.5);
    solidBox(0.5, 1, 0.5);
    glTranslatef(0.0, -0.45, 0.0);
    glColor3f(0.0, 0.0, 0.2);
    glutSolidSphere(0.45, 20, 20);
    glTranslatef(0.0, 0.45, 0.0);
    glTranslatef(-2.0, -1.0, 0.0);

    glTranslatef(2.0, 0.5, 0.0);
    glRotatef(-(GLfloat)dirsekAci, 1.0, 0.0, 0.0);
    glTranslatef(-2.0, -0.5, 0.0);

    glTranslatef(2.0, 0.0, 0.0);
    glColor3f(0.0, 0.2, 0.5);
    solidBox(0.5, 1.0, 0.5);
    glTranslatef(-2.0, 0.0, 0.0);
}

void rightArm(void)
{
    glTranslatef(-2.0, 1.5, 0.0);
    glRotatef((GLfloat)omuzAci2, 1.0, 0.0, 0.0);
    glTranslatef(2.0, -1.5, 0.0);

    glTranslatef(-2.0, 1.0, 0.0);
    glColor3f(0.0, 0.2, 0.5);
    solidBox(0.5, 1, 0.5);
    glTranslatef(0.0, -0.45, 0.0);
    glColor3f(0.0, 0.0, 0.2);
    glutSolidSphere(0.45, 20, 20);
    glTranslatef(0.0, 0.45, 0.0);
    glTranslatef(2.0, -1.0, 0.0);

    glTranslatef(-2.0, 0.5, 0.0);
    glRotatef(-(GLfloat)dirsekAci2, 1.0, 0.0, 0.0);
    glTranslatef(2.0, -0.5, 0.0);

    glTranslatef(-2.0, 0.0, 0.0);
    glColor3f(0.0, 0.2, 0.5);
    solidBox(0.5, 1.0, 0.5);
    glTranslatef(2.0, 0.0, 0.0);
}

void eye(void)
{
    glTranslatef(0.0, 1.0, 1.0);
    glColor3f(0.2, 1.0, 1.0);
    glutSolidSphere(0.6, 20, 20);

    glColor3f(0.0, 0.1, 0.2);
    glutSolidTorus(0.25, 0.5, 20, 20);

    glTranslatef(0.0, -1.0, -1.0);
}

void bottomPart(void)
{
    glTranslatef(0.0, -1.0, 0.0);
    glColor3f(0.0, 0.2, 0.5);
    solidBox(0.65, 1.0, 0.5);
    glTranslatef(0.0, 1.0, 0.0);
}

void wheel(void)
{
    glTranslatef(0.0, -2.0, 0.0);
    glRotatef(90, 0.0, 1.0, 0.0);

    glRotatef((GLfloat)tekerlekAci, 0.0, 0.0, 1.0);

    glColor3f(0.0, 0.1, 0.2);
    glutSolidTorus(0.25, 0.5, 20, 20);

    glColor3f(0.7, 0.0, 0.3);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.0, -0.5, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(-0.5, 0.0, 0.0);
    glEnd();
}

void background(void)
{
    //arka
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.6, 1.0);
    glVertex3f(-50.0, -3.0, -50.0);
    glVertex3f(-50.0, 50.0, -50.0);
    glVertex3f(50.0, 50.0, -50.0);
    glVertex3f(50.0, -3.0, -50.0);
    //sol
    glColor3f(0.0, 0.6, 0.9);
    glVertex3f(-50.0, -3.0, -50.0);
    glVertex3f(-50.0, 50.0, -50.0);
    glVertex3f(-50.0, 50.0, 50.0);
    glVertex3f(-50.0, -3.0, 50.0);
    //sag
    glColor3f(0.0, 0.6, 0.9);
    glVertex3f(50.0, -3.0, -50.0);
    glVertex3f(50.0, 50.0, -50.0);
    glVertex3f(50.0, 50.0, 50.0);
    glVertex3f(50.0, -3.0, 50.0);
    //on
    glColor3f(0.0, 0.6, 0.9);
    glVertex3f(50.0, -3.0, 50.0);
    glVertex3f(50.0, 50.0, 50.0);
    glVertex3f(-50.0, 50.0, 50.0);
    glVertex3f(-50.0, -3.0, 50.0);
    //alt
    glColor3f(0.0, 0.7, 0.3);
    glVertex3f(-50.0, -3.0, -50.0);
    glVertex3f(-50.0, -3.0, 50.0);
    glVertex3f(50.0, -3.0, 50.0);
    glVertex3f(50.0, -3.0, -50.0);
    glEnd();


    //agaclar
    glPushMatrix();
    glTranslatef(-20.0, 0.0, -25.0);

    glColor3f(0.3, 0.0, 0.0);
    solidBox(1.0, 5.0, 1.0);

    glTranslatef(0.0, 1.0, 0.0);
    glRotatef(-90, 1.0, 0.0, 0.0);

    glColor3f(0.0, 0.7, 0.3);
    glutSolidCone(5.0, 5.0, 20, 20);

    glTranslatef(0.0, 0.0, 2.0);
    glutSolidCone(4.5, 5.0, 20, 20);

    glTranslatef(0.0, 0.0, 2.0);
    glutSolidCone(4.0, 5.5, 20, 20);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(10.0, 0.0, -25.0);

    glColor3f(0.3, 0.0, 0.0);
    solidBox(1.0, 5.0, 1.0);

    glTranslatef(0.0, 1.0, 0.0);
    glRotatef(-90, 1.0, 0.0, 0.0);

    glColor3f(0.0, 0.7, 0.3);
    glutSolidCone(5.0, 5.0, 20, 20);

    glTranslatef(0.0, 0.0, 2.0);
    glutSolidCone(4.5, 5.0, 20, 20);

    glTranslatef(0.0, 0.0, 2.0);
    glutSolidCone(4.0, 5.5, 20, 20);
    glPopMatrix();
}

void draw(void)
{
    glTranslatef(xPos, yPos, zPos);
    glRotatef(angle, 0.0, 1.0, 0.0);


    glPushMatrix();

    //Govde donme noktasi
    glTranslatef(0.0, -1.0, 0.0);
    glRotatef(-(GLfloat)govdeAci, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 1.0, 0.0);

    //Govde
    mainBody();

    //Goz
    eye();

    //Sol omuz
    leftShoulder();

    //Sag omuz
    rightShoulder();

    //Sol kol
    glPushMatrix();
    leftArm();
    glPopMatrix();

    //Sag kol
    glPushMatrix();
    rightArm();
    glPopMatrix();

    glPopMatrix();


    //Alt taraf
    bottomPart();

    //Tekerlek
    glPushMatrix();
    wheel();
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(15.0, 15.0, 35.0, xPos, yPos, zPos, 0.0, 1.0, 0.0);

    //Zemin
    background();

    //Karakter
    draw();

    glutSwapBuffers();
}

void specFunc(int dugme, int x, int y)
{
    switch (dugme)
    {
    case GLUT_KEY_LEFT:goturSol(); yuru(); break;

    case GLUT_KEY_RIGHT:goturSag(); yuru(); break;

    case GLUT_KEY_UP:goturIleri(); yuru(); break;

    case GLUT_KEY_DOWN:goturGeri(); yuru(); break;
    }

    glutPostRedisplay();
}

void keyFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '4':dirsekAci += 2; break;

    case '1':dirsekAci -= 2; break;

    case '6':dirsekAci2 += 2; break;

    case '3':dirsekAci2 -= 2; break;
    }

    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 2000.0);
    glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);


    //Isiklandirma
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Volkan Demirbacak");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specFunc);
    glutKeyboardFunc(keyFunc);

    glutMainLoop();
    return 0;
}