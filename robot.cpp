/*************************************
 * NAME ::-- Hassan Hosni Abdel_Aleem
 * SEC ::-- 1
 * B.N ::- 27
 * 
************************************/
#include <GL/glut.h>
#include <stdlib.h>

static int body = 0, shoulder1 = 0,shoulder2 = 0,elbow1 = 0,elbow2 = 0 , leg1=0,knee1=0, leg2=0,knee2=0;
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
   glPushMatrix();
   glScalef (0.7, 0.7, 0.7);
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
   glTranslatef (-1.0, 0.0, 0.0);
   glRotatef ((GLfloat) body, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glTranslatef (0.0, 2.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 2.0, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   //////////////////////////head
   glPushMatrix();
   glTranslatef (0.0, 2.0, 0.0);
   glutSolidSphere(1.0,10.0,10.0);
   glPopMatrix();
   /////////////////shoulder1
   glPushMatrix();
   glTranslatef (1.0, 0.7, 0.0);
   glRotatef ((GLfloat) shoulder1, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.6, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   //////////////elbow1
   glPushMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) elbow1, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.6, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();

   ///////////////////////////////////
   ////////shoulder2
   glPushMatrix();
   glTranslatef (-1.0, 0.7, 0.0);
   glRotatef ((GLfloat) shoulder2, 0.0, 0.0, 1.0);
   glTranslatef (-1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.6, 1.0);
   glutWireCube (1.0);
   
   //////////////elbow2
   glPushMatrix();
   glTranslatef (-1.0, 0.0, 0.0);
   glRotatef ((GLfloat) elbow2, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.0, 1.0, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();
   /////////////////leg1
   glPushMatrix();
   glTranslatef (1.0, 0.7, 0.0);
   glRotatef ((GLfloat) leg1, 1.0, 0.0, 0.0);
   glTranslatef (-0.35, -2.7, 0.0);
   glPushMatrix();
   glScalef (0.7, 2.0, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   //////////////knee1
   glPushMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) knee1, 1.0, 0.0, 0.0);
   glTranslatef (-1.0, -2.0, 0);
   glPushMatrix();
   glScalef (0.7, 2.0, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   ///***
   glPushMatrix();
   glTranslatef (0.0, -1.3, 0.0);
   glScalef (0.8, 0.7, 2.0);
   glutSolidCube(1.0);
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();
   /////////////////leg2
   glPushMatrix();
   glTranslatef (1.0, 0.7, 0.0);
   glRotatef ((GLfloat) leg2, 1.0, 0.0, 0.0);
   glTranslatef (-1.6, -2.7, 0.0);
   glPushMatrix();
   glScalef (0.7, 2.0, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   //////////////knee2
   glPushMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) knee2, 1.0, 0.0, 0.0);
   glTranslatef (-1.0, -2.0, 0);
   glPushMatrix();
   glScalef (0.7, 2.0, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   ///***
   glPushMatrix();
   glTranslatef (0.0, -1.3, 0.0);
   glScalef (0.8, 0.7, 2.0);
   glutSolidCube(1.0);
   glPopMatrix();
   
   glPopMatrix();
   glPopMatrix();

   


    

   
    /////////// for first puch
   glPopMatrix();

   /////////////////////////

   glutSwapBuffers();
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
      shoulder1 = (shoulder1 + 5) % 90;
      glutPostRedisplay();
      break;
   case 'S':
      shoulder1 = (shoulder1 - 5) % 90;
      glutPostRedisplay();
      break;
      case 'q':
      shoulder2 = (shoulder2 + 5) % 90;
      glutPostRedisplay();
      break;
   case 'Q':
      shoulder2 = (shoulder2 - 5) % 90;
      glutPostRedisplay();
      break;

   case 'e':
      elbow1 = (elbow1 + 5) % 10;
      glutPostRedisplay();
      break;
   case 'E':
      elbow1 = (elbow1 - 5) %150;
      glutPostRedisplay();
      break;
   case 'm':
      elbow2 = (elbow2 + 5) % 10;
      glutPostRedisplay();
      break;
   case 'M':
      elbow2 = (elbow2 - 5) %150;
      glutPostRedisplay();
      break;
   case 'l':
      leg1 = (leg1 + 5) % 130;
      glutPostRedisplay();
      break;
   case 'L':
      leg1 = (leg1 - 5) %30;
      glutPostRedisplay();
      break;
   case 'k':
      knee1 = (knee1 + 5) % 90;
      glutPostRedisplay();
      break;
   case 'K':
      knee1 = (knee1 - 5) %10;
      glutPostRedisplay();
      break;
   case 'p':
      leg2 = (leg2 + 5) % 130;
      glutPostRedisplay();
      break;
   case 'P':
      leg2 = (leg2 - 5) %30;
      glutPostRedisplay();
      break;
   case 'o':
      knee2 = (knee2 + 5) % 90;
      glutPostRedisplay();
      break;
   case 'O':
      knee2 = (knee2 - 5) %10;
      glutPostRedisplay();
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



int main(int argc, char **argv)
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