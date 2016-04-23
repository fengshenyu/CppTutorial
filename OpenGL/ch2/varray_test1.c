// glArrayElement的使用方法
#include <GL/glut.h>
#include <stdlib.h>

static GLint vertices[] = {1, 1,
                       9, 1,
                       9, 9,
                       8, 8,
                       1, 9};
void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 0, 0); //图形颜色,依次是r,g,b

   glEnableClientState (GL_VERTEX_ARRAY);
   glVertexPointer(2, GL_INT, 0, vertices);
   glBegin(GL_POLYGON);//顶点数组中第0,1,2,4个顶点画四边形
      glArrayElement(0);
      glArrayElement(1);
      glArrayElement(2);
      glArrayElement(4);
   glEnd();

   glFlush();
}

void init (void) 
{
   glClearColor (1.0, 1.0, 1.0, 0.0); //背景颜色,3个参数依次是r,g,b,alpha

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);//窗口的大小,单位是像素
   glutInitWindowPosition (0, 0);//窗口左上角的位置
   glutCreateWindow ("中华人民共和国");//窗口标题
   init ();
   //每当clut确定一个窗口的内容需要重新显示时,通过glutDisplayFuc()注册的那个函数就会被执行
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;  
}