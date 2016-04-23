// 多个glDrawElements的情况,这种情况不能用varray_test4.c的方法简单合,要用
//varray_test6.c的glMultiDrawElements
#include <GL/glut.h>
#include <stdlib.h>

static GLint vertices[] = 
  {1, 1, 2, 1, 2, 2, 1, 2, 1, 3,
   3, 3, 4, 3, 4, 4, 3, 4,
   5, 5, 6, 5, 6, 6};
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0, 0); //图形颜色,依次是r,g,b

    glEnableClientState (GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, vertices);

    GLuint indices1[] = {0, 1, 2, 3, 4};
    GLuint indices2[] = {5, 6, 7, 8};
    GLuint indices3[] = {9, 10, 11};
    glDrawElements(GL_LINE_STRIP, 5, GL_UNSIGNED_INT, indices1);
    glDrawElements(GL_LINE_STRIP, 4, GL_UNSIGNED_INT, indices2);
    glDrawElements(GL_LINE_STRIP, 3, GL_UNSIGNED_INT, indices3);
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