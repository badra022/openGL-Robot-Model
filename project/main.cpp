/*************************************************
 * Contibutors ::-- Hassan Hosni Abdel_Aleem     *
 *                  Mohamed Khaled Galloul       *
 *                  Ahmed Mohamed Mohamed        *
**************************************************/

#include <GL/glut.h>

GLfloat body = 0, shoulder1 = 0, shoulder2 = 0, elbow1 = 0, elbow2 = 0, leg1 = 0, knee1 = 0, leg2 = 0, knee2 = 0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();             /* DRAWING STACK */
    glScalef(0.7, 0.7, 0.7);
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)body, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glTranslatef(0.0, 2.0, 0.0);
    glPushMatrix();             /* BODY STACK */
    glScalef(2.0, 3.0, 1.0);    
    glutWireCube(1.0);          /* drawing the actual body center */
    glPopMatrix();              /* BODY STACK */

    /*******************************************************
     *                        HEAD                         *
    ********************************************************/
    glPushMatrix();             /* HEAD STACK */
    glTranslatef(0.0, 2.5, 0.0);
    glutSolidSphere(1.0, 50, 50); /* drawing the actual head */
    glPopMatrix();              /* HEAD STACK */

    /*******************************************************
     *                        SHOULDER 1                   *
    ********************************************************/
    glPushMatrix();             /* ARM 1 STACK */
    glTranslatef(1.0, 1.2, 0.0);
    glRotatef((GLfloat)shoulder1, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();             /* SHOULDER 1 STACK */
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);          /* drawing the actual shoulder */
    glPopMatrix();              /* SHOULDER 1 STACK */

    /*******************************************************
     *                        ELBOW 1                      *
    ********************************************************/
    glPushMatrix();             /* ELBOW 1 STACK */
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow1, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);          /* drawing the actual elbow */
    glPopMatrix();              /* ELBOW 1 STACK */
    glPopMatrix();              /* ARM 1 STACK */

    /*******************************************************
     *                        SHOULDER 2                   *
    ********************************************************/
    glPushMatrix();             /* ARM 2 STACK */
    glTranslatef(-1.0, 1.2, 0.0);
    glRotatef((GLfloat)shoulder2, 0.0, 0.0, 1.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glPushMatrix();             /* SHOULDER 2 STACK */
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);          /* drawing the actual shoulder */
    glPopMatrix();              /* SHOULDER 2 STACK */

    /*******************************************************
     *                        ELBOW 2                      *
    ********************************************************/
    glPushMatrix();             /* ELBOW 2 STACK */
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow2, 0.0, 0.0, 1.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);          /* drawing the actual elbow */
    glPopMatrix();              /* ELBOW 2 STACK */
    glPopMatrix();              /* ARM 2 STACK */

    /*******************************************************
     *                        LEG 1                        *
    ********************************************************/
    glPushMatrix();             /* LEG 1 STACK */
    glTranslatef(1.0, -1.35, 0.0);
    glRotatef((GLfloat)leg1, 1.0, 0.0, 0.0);
    glTranslatef(-0.35, -1.2, 0.0);
    glPushMatrix();             /* THIGH 1 STACK */
    glScalef(0.7, 2.0, 1.0);
    glutWireCube(1.0);          /* drawing the actual leg */
    glPopMatrix();              /* THIGH 1 STACK */

    /*******************************************************
     *                        KNEE 1                       *
    ********************************************************/
    glPushMatrix();             /* LOWER LEG 1 STACK */
    glTranslatef(1.0, -1.35, 0.0);
    glRotatef((GLfloat)knee1, 1.0, 0.0, 0.0);
    glTranslatef(-1, -0.7, 0.0);
    glPushMatrix();             /* KNEE 1 STACK */
    glScalef(0.7, 2.0, 1.0);
    glutWireCube(1.0);          /* drawing the actual knee */
    glPopMatrix();              /* KNEE 1 STACK */
    glTranslatef(0.0, -1.3, 0.0);
    glScalef(0.8, 0.7, 2.0);
    glutSolidCube(1.0);         /* drawing the actual ankle */
    glPopMatrix();              /* LOWER LEG 1 STACK */
    glPopMatrix();              /* LEG 1 STACK */

    /*******************************************************
     *                        LEG 2                        *
    ********************************************************/
    glPushMatrix();             /* LEG 2 STACK */
    glTranslatef(1.0, -1.35, 0.0);
    glRotatef((GLfloat)leg2, 1.0, 0.0, 0.0);
    glTranslatef(-1.65, -1.2, 0.0);
    glPushMatrix();             /* THIGH 2 STACK */
    glScalef(0.7, 2.0, 1.0);
    glutWireCube(1.0);          /* drawing the actual leg */
    glPopMatrix();              /* THIGH 2 STACK */

    /*******************************************************
     *                        KNEE 2                       *
    ********************************************************/
    glPushMatrix();             /* LOWER LEG 2 STACK */
    glTranslatef(1.0, -1.35, 0.0);
    glRotatef((GLfloat)knee2, 1.0, 0.0, 0.0);
    glTranslatef(-1, -0.7, 0.0);
    glPushMatrix();             /* KNEE 2 STACK */
    glScalef(0.7, 2.0, 1.0);
    glutWireCube(1.0);          /* drawing the actual knee */
    glPopMatrix();              /* KNEE 2 STACK */
    glTranslatef(0.0, -1.3, 0.0);
    glScalef(0.8, 0.7, 2.0);
    glutSolidCube(1.0);          /* drawing the actual ankle */
    glPopMatrix();              /* LOWER LEG 2 STACK */
    glPopMatrix();              /* LEG 2 STACK */

    glPopMatrix();              /* DRAWING STACK */
    glutSwapBuffers(); /* Swap buffers after creating the draw */
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}
// control the movement of fingers and shoulder and elbow joints
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        if (shoulder1 >= 90)
        {
            shoulder1 = 90;
        }
        else
        {
            shoulder1 = (shoulder1 + 5);
            glutPostRedisplay();
        }
        break;
    case 'S':
        if (shoulder1 <= -90)
        {
            shoulder1 = -90;
        }
        else
        {
            shoulder1 = (shoulder1 - 5);
            glutPostRedisplay();
        }
        break;
    case 'q':
        if (shoulder2 >= 90)
        {
            shoulder2 = 90;
        }
        else
        {
            shoulder2 = (shoulder2 + 5);
            glutPostRedisplay();
        }
        break;
    case 'Q':
        if (shoulder2 <= -90)
        {
            shoulder2 = -90;
        }
        else
        {
            shoulder2 = (shoulder2 - 5);
            glutPostRedisplay();
        }
        break;

    case 'e':
        if (elbow1 >= 150)
        {
            elbow1 = 150;
        }
        else
        {
            elbow1 = (elbow1 + 5);
            glutPostRedisplay();
        }
        break;
    case 'E':
        if (elbow1 <= 0)
        {
            elbow1 = 0;
        }
        else
        {
            elbow1 = (elbow1 - 5);
            glutPostRedisplay();
        }
        break;
    case 'm':
        if (elbow2 >= 150)
        {
            elbow2 = 150;
        }
        else
        {
            elbow2 = (elbow2 + 5);
            glutPostRedisplay();
        }
        break;
    case 'M':
        if (elbow2 <= 0)
        {
            elbow2 = 0;
        }
        else
        {
            elbow2 = (elbow2 - 5);
            glutPostRedisplay();
        }
        break;
    case 'l':
        if (leg1 >= 90)
        {
            leg1 = 90;
        }
        else
        {
            leg1 = (leg1 + 5);
            glutPostRedisplay();
        }
        break;
    case 'L':
        if (leg1 <= -90)
        {
            leg1 = -90;
        }
        else
        {
            leg1 = (leg1 - 5);
            glutPostRedisplay();
        }
        break;
    case 'k':
        if (knee1 >= 90)
        {
            knee1 = 90;
        }
        else
        {
            knee1 = (knee1 + 5);
            glutPostRedisplay();
        }
        break;
    case 'K':
        if (knee1 <= 0)
        {
            knee1 = 0;
        }
        else
        {
            knee1 = (knee1 - 5);
            glutPostRedisplay();
        }
        break;
    case 'p':
        if (leg2 >= 90)
        {
            leg2 = 90;
        }
        else
        {
            leg2 = (leg2 + 5);
            glutPostRedisplay();
        }
        break;
    case 'P':
        if (leg2 <= -90)
        {
            leg2 = -90;
        }
        else
        {
            leg2 = (leg2 - 5);
            glutPostRedisplay();
        }
        break;
    case 'o':
        if (knee2 >= 90)
        {
            knee2 = 90;
        }
        else
        {
            knee2 = (knee2 + 5);
            glutPostRedisplay();
        }
        break;
    case 'O':
        if (knee2 <= 0)
        {
            knee2 = 0;
        }
        else
        {
            knee2 = (knee2 - 5);
            glutPostRedisplay();
        }
        break;


    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(5000, 5000);
    glutInitWindowPosition(10, 10);
    glutCreateWindow(argv[0]);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
