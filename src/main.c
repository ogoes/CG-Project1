#include <GL/glut.h>
#include <stdio.h>


int mode = 0; // 0 tralation, 1 rotartion

float middleX, middleY;

int side_view[] = {0, 100, 0, 100};
/* 
      __________
      |        |
      |        | 10x10 square
    10|        |
      |________|
          10
 */
int point0[] = {0, 0};
int point1[] = {0, 10};
int point2[] = {10, 10};
int point3[] = {10, 0};


int step = 2; // step number

float squareColor[] = {1.0, 0.0, 0.0}; // red square

float degree = 0.0; // rotation degree


int init (void) {
  glClearColor(1.0, 1.0, 1.0, 1.0); // white screen
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(side_view[0], side_view[1], side_view[2], side_view[3]);
}

void display (void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3fv(squareColor);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();



  glTranslatef(middleX , middleY , 0.0);
  glRotatef(degree, 0.0, 0.0, 1.0);
  glTranslatef(-middleX , -middleY , 0.0);

  glBegin(GL_POLYGON);
    glVertex2iv(point0);
    glVertex2iv(point1);
    glVertex2iv(point2);
    glVertex2iv(point3);

	
  glEnd();

  glFlush();
}

void specialsKeys (int key, int x, int y) {
  

  if (key == GLUT_KEY_LEFT) { // move -step em relação a x

    if (!mode) {
      point0[0] -= step;
      point1[0] -= step;
      point2[0] -= step;
      point3[0] -= step;

    } else {
      degree += 10.0;
    }

  } else if (key == GLUT_KEY_UP) { // move step em relação a y

    if (!mode) {
      point0[1] += step;
      point1[1] += step;
      point2[1] += step;
      point3[1] += step;
    }
  } else if (key == GLUT_KEY_RIGHT) { // move step em relação a x

    if (!mode) {
      point0[0] += step;
      point1[0] += step;
      point2[0] += step;
      point3[0] += step;

    } else {
      degree -= 10.0;      
    }
  } else if (key == GLUT_KEY_DOWN) { // move -step em relação a y

    if (!mode) {
      point0[1] -= step;
      point1[1] -= step;
      point2[1] -= step;
      point3[1] -= step;
    }
  }

  if (!mode) {
    middleX = ((float) point0[0] + (float) point2[0]) / 2;
    middleY = ((float) point1[1] + (float) point3[1]) / 2;
  }
  // printf("%f - %f ----> %f\n", (middleX), (middleY), degree);
  glutPostRedisplay();
}

void keyboardKeys (unsigned char key, int x, int y) {
  if (key == 'R' || key == 'r') {
    mode = 1; // rotation mode
  } else if (key == 'T' || key == 't') {
    mode = 0; // translation mode
  }
}




int main (int argc, char ** argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Projeto Bonus");

  init();

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboardKeys);
  glutSpecialFunc(specialsKeys);
  glutMainLoop();

  return 0;
}
