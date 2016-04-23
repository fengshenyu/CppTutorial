/*
glutReshapeFunc()表示当窗口的大小发生改变时应采取什么操作
glutKeyboardFunc()和glutMouseFunc()允许把键盘上的一个键或鼠标上的一个按钮与一个函数相关联,当这个键或按钮被 按下或释放时,这个函数就会调用.
glutMotionFunc()注册了一个函数,当按下鼠标按钮移动鼠标时,这个函数就会调用
*/
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
   //每当clut确定一个窗口的内容需要重新显示时,通过glutDisplayFuc()注册的那个函数就会被执行
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;  
}