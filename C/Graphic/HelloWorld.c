
#include <GL/glut.h>
#include <stdlib.h>

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   glColor3f (1.0, 1.0, 1.0); 
   glBegin(GL_POINTS);
      for (int i = 100; i < 400; i++) {
         glVertex2f (i, 100);
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