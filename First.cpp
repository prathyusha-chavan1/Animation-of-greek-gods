#include<GL/glut.h>

void displayMe(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(500, 100);
	glutCreateWindow("Hello world :D");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}