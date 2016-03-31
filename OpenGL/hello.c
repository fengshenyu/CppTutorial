#include <GL/glut.h>
#include <stdlib.h>

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   glColor3f (1.0, 0, 0); //图形颜色,依次是r,g,b
   glBegin(GL_POLYGON);
      glVertex3f (0.25, 0.25, 0.0);
      glVertex3f (0.75, 0.25, 0.0);
      glVertex3f (0.75, 0.75, 0.0);
      glVertex3f (0.25, 0.75, 0.0);
   glEnd();

   glFlush();
}

void init (void) 
{
   glClearColor (1.0, 1.0, 1.0, 0.0); //背景颜色,3个参数依次是r,g,b,alpha

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (1000, 1000);//窗口的大小,单位是像素
   glutInitWindowPosition (500, 500);//窗口左上角的位置
   glutCreateWindow ("中华人民共和国");//窗口标题
   init ();
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;  
}