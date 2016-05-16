
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float getSlope(int x1, int y1, int x2, int y2) {
   return ((float)(y2 - y1)) / (x2 - x1);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   glColor3f (1.0, 1.0, 1.0); 
   glBegin(GL_POINTS);
      // float slope = getSlope(100, 100, 400, 200);
      float slope = getSlope(100, 100, 200, 400);
      if (slope < 1) {
         float y = 100;
         for (int x = 100; x < 400; x++, y += slope) {
            glVertex2f (x, round(y));
         }
      } else {
         float x = 100;
         for (int y = 100; y < 400; y++, x += (1 / slope)) {
            glVertex2f (x, y);
         }
      }
   glEnd();
   glFlush();
}

void init (void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (0, 0);
   glutCreateWindow ("title");
   init ();
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;  
}