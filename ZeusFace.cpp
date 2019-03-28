#include <iostream>
#include <GL/glut.h>

using namespace std;
void drawCloud(int, int,int, int ,int,int,int,double);

float width, height;
void drawCircleFilled(double centerX, double centerY, double radiusX, double radiusY)
{
	const float DEG2RAD = 3.14159 / 180;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2d(centerX, centerY);
	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(centerX + cos(degInRad) * radiusX,
			centerY + sin(degInRad) * radiusY);

	}

	glEnd();
	glFlush();
}
void drawline()
{
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(277,240);
	glVertex2i(281,240);
	glEnd();
	glFlush();



}
void drawface()
{
	glColor3f(0.96,0.80,0.69);
	glBegin(GL_POLYGON);
	glVertex2i(230,255);
	glVertex2i(250,290);
	glVertex2i(310,290);
	glVertex2i(330,255);

	glEnd();
	glFlush();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1, 0);

	// clear display window
	
	drawCloud(280, 260, 60, 35, 30, 20, 15, 0.658824);//hair
	drawCloud(280, 230, 55, 30, 25, 15, 10, 0.80);//beard
	drawface();

	glColor3f(0, 0, 0);
	drawCircleFilled(265, 270, 4,4);
	glColor3f(0, 0, 0);
	drawCircleFilled(292, 270, 4,4);
	glColor3f(0.96, 0.80, 0.69);
	drawCircleFilled(280,240,11,7);
	glColor3f(0, 0, 0);
	drawline();
	glColor3f(1,0,0);

	
}



void reshape(int width, int height)
{
	::width = width;
	::height = height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);        // set projection parameters
	glLoadIdentity();
	gluOrtho2D(0.0, width, 0.0, height);

	glMatrixMode(GL_MODELVIEW);        // set projection parameters
	glLoadIdentity();
}
void init()
{
	glClearColor(0, 0, 0, 1);
}
void main(int argc, char** argv)
{

	glutInit(&argc, argv);                            // initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // set display mode
	glutInitWindowPosition(0,0);        // set top left display window position
	glutInitWindowSize(600, 600);            // set display window width and height
	glutCreateWindow("Graphic's HW");    // create display window

	init();                                // execute initialization function


	glutReshapeFunc(reshape);
	glutDisplayFunc(display);                // send graphics to display window

	glutMainLoop();                        // dispaly everthing and wait
}
void drawCloud(int xx,int yy,int p, int q, int r,int u,int v,double a)
{
	int x = xx, y = yy;

	glColor3f(a,a,a);
	drawCircleFilled(x, y, p,q);
	glColor3f(a, a,a);
	drawCircleFilled(x + u, y + v, r,r);
	glColor3f(a,a,a);
	drawCircleFilled(x + u, y - v, r,r);
	glColor3f(a,a,a);
	drawCircleFilled(x - u, y - v, r,r);
	glColor3f(a,a,a);
	drawCircleFilled(x - u,y + v, r,r);
}




