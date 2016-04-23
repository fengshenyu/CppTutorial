#include <GL/glut.h>
#include <stdlib.h>

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   glColor3f (1.0, 0, 0); //图形颜色,依次是r,g,b
   //glBegin(GL_POLYGON);  //多边形
   //glBegin(GL_POINTS);     //孤立的点
   //glBegin(GL_LINES);     //一对顶点画一条线,不成对的忽略
   //glBegin(GL_LINE_STRIP);     //一系列连接直线,首尾不相连
   //glBegin(GL_LINE_LOOP);     //一系列连接直线,首尾相连
   //glBegin(GL_TRIANGLES);     //3个点被解释成一个三角形,不是3的倍数忽略
   glBegin(GL_TRIANGLE_STRIP);     //3个点被解释成一个三角形,不是3的倍数忽略
      glVertex2f (2, 2);
      glVertex2f (6, 2);
      glVertex2f (6, 4);
	  glVertex2f (2, 4);
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