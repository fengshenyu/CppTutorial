#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
#define BUFFER_OFFSET(bytes) ((GLubyte*) NULL + (bytes))  //unsigned char
#define VERTICES 0
#define INDICES 1
#define NUM_BUFFERS 2

GLuint buffers[NUM_BUFFERS];
GLfloat vertices[][3] = {
	{-1.0f, -1.0f, -1.0f},
	{ 1.0f, -1.0f, -1.0f},
	{ 1.0f,  1.0f, -1.0f},
	{-1.0f,  1.0f, -1.0f},
	{-1.0f, -1.0f,  1.0f},
	
	{ 1.0f, -1.0f,  1.0f},
	{ 1.0f,  1.0f,  1.0f},
	{-1.0f,  1.0f,  1.0f}
};
GLubyte indices[][4] = {
	{0, 1, 2, 3},
	{4, 7, 6, 5},
	{0, 4, 5, 1},
	{3, 2, 6, 7},
	{0, 3, 7, 4},
	{1, 5, 6, 2}
};

GLfloat* bdata;

void changeSize(int w, int h) {
	printf("changeSize\n");
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w/(double)h, 0.01, 30);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyDown(unsigned char key, int x, int y) {
	switch (key) {
		case'b':
			bdata = (GLfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
			for (int i = 0; i < 24; i++) {
				*(bdata + i) *= 1.1f;
			}
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glutPostRedisplay();
			break;
	}
}

void display(void) {
	printf("display\n");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-5.0f);
	glRotatef(30.0f,1.0f,1.0f,0.0f);
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
	glutSwapBuffers();
}

void init(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glShadeModel(GL_FLAT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glewInit();
	glGenBuffers(NUM_BUFFERS, buffers);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[VERTICES]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));

	glEnableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,buffers[INDICES]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GL_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(512, 512);
	glutCreateWindow("Buffer Demo");
	glutReshapeFunc(changeSize);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyDown);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}