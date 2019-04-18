#include<glut.h>
#include<stdio.h>
#include<math.h>

#include<iostream>
using namespace std;

float bottomx = 650, bottomy1 = 790, bottomy2 = 790;
bool flag = true;
int cl,el;
void drawCloud(int, int, int, int, int, int, int, double);
float scale = 0.5,width,height;
const float DEG2RAD = 3.14159 / 180;

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1920, 0, 1080);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_NORMALIZE);
	glPointSize(5);
	glLineWidth(2);
	//glTranslatef(500, 200, 0);
	//glScalef(0.5, 0.5, 0.5);
	
}

void drawCircleFilled(double centerX, double centerY, double radiusX, double radiusY)
{
	
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
void drawmouth()
{
	glColor3f(0, 0, 0);
	/*glBegin(GL_LINES);
	glVertex2i(305, 295);
	glVertex2i(332, 295);
	glEnd();
	glFlush();*/
	float x2, y2;
	glBegin(GL_LINE_STRIP);
	for (float angle = 250.0; angle < 291.0; angle += 0.2)
	{
		x2 = 317.5 + cos(angle*DEG2RAD) * 40;
		y2 = 333 + sin(angle*DEG2RAD) * 40;
		glVertex2f(x2, y2);
	}
	glEnd();
}
void drawface()
{
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2i(225, 330);
	glVertex2i(255, 430);
	glVertex2i(385, 430);
	glVertex2i(415, 330);
	glEnd();
	glFlush();
}


//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glClearColor(1, 1, 1, 0);
//
//	// clear display window
//
//
//	glColor3f(1, 0, 0);
//
//
//}

void drawCloud(int xx, int yy, int p, int q, int r, int u, int v, double a)
{
	int x = xx, y = yy;

	glColor3f(a, a, a);
	drawCircleFilled(x, y, p, q);
	glColor3f(a, a, a);
	drawCircleFilled(x + u, y + v, r, r);
	glColor3f(a, a, a);
	drawCircleFilled(x + u, y - v, r, r);
	glColor3f(a, a, a);
	drawCircleFilled(x - u, y - v, r, r);
	glColor3f(a, a, a);
	drawCircleFilled(x - u, y + v, r, r);
}

void drawcloud() {
	float angle,n=6, x1, x2, y1, y2;
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);

	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 320 + sin(angle) * 120;
		y2 = 650 + cos(angle) * 80;
		glVertex2f(x2, y2);
	}
	glEnd();

	for (float i = 1; i <= 8; i++) {
		x1 = 320 + 120 * sin((i * 360 / n) * DEG2RAD);
		y1 = 650 + 80 * cos((i * 360 / n) * DEG2RAD);
		glBegin(GL_POLYGON);
		for (angle = 1.0f; angle < 361.0f; angle += 0.2)
		{
			x2 = x1 + sin(angle) * 30;
			y2 = y1 + cos(angle) * 30;
			glVertex2f(x2, y2);
		}
		glEnd();
	}
	glFlush();
}

void drawlightning() {
	glColor3f(1, 1, 0);
	time(&current_time);
	cl = clock();
	
	
	if (flag) {
		el = cl + 5000;
		flag = false;
		cout << cl;
	}
	if (bottomx > 600) {
		if (cl - el <= 5000) {
			el += 5000;
			bottomx--;
			bottomy1 -= 10;
			bottomy2 -= 10;
		}
	}
	
	glBegin(GL_POLYGON);
	glVertex2f(600, 800);
	glVertex2f(650, 800);
	glVertex2f(bottomx, bottomy1);
	glVertex2f(600, bottomy2);
	glEnd();
	glFlush();
}

void drawzeus() {
	float hx = 25, x1 = hx + 150, y1 = 190, x2, y2;
	float angle, radius = 10;
	//thunderbolt
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(hx + 100, 300);
	glVertex2f(hx + 120, 200);
	glVertex2f(hx + 135, 220);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(hx + 170, 100);
	glVertex2f(hx + 150, 250);
	glVertex2f(hx + 130, 230);
	glEnd();

	//left hand
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(hx + 150, 195);
	glVertex2f(hx + 210, 250);
	glVertex2f(hx + 220, 240);
	glVertex2f(hx + 160, 190);
	glEnd();

	//right robe flap
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(387, 237);
	glVertex2f(370, 90);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(385, 92);
	glColor3f(0.3, 0.3, 0.3);
	glVertex2f(420, 95);
	glEnd();

	//right hand
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(395, 240);
	glVertex2f(405, 240);
	glVertex2f(417, 160);
	glVertex2f(405, 160);
	glVertex2f(405, 200);
	glEnd();

	glBegin(GL_POLYGON);
	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = 405 + sin(angle) * 12;
		y2 = 160 + cos(angle) * 12;
		glVertex2f(x2, y2);
	}
	glEnd();
	//robe lower
	glColor3f(0.85, 0.85, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(210, 130);
	glVertex2f(240, 190);
	glVertex2f(245, 185);
	glVertex2f(215, 125);
	glEnd();

	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(245, 185);
	glVertex2f(207, 110);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(242, 90);
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(243, 120);
	glEnd();

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
	glVertex2f(245, 185);
	glVertex2f(237, 70);
	glVertex2f(265, 65);
	glVertex2f(310, 75);
	glVertex2f(365, 65);
	glVertex2f(390, 70);
	glVertex2f(382, 185);
	glEnd();

	//shading
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(245, 185);
	glVertex2f(237, 70);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(265, 65);
	glColor3f(0.9, 0.9, 0.9);
	glVertex2f(278, 100);

	glVertex2f(300, 200);
	glEnd();

	//waist left
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(239, 220);
	glVertex2f(240, 190);
	glVertex2f(245, 185);
	glVertex2f(260, 184);
	glVertex2f(245, 240);
	glEnd();

	//left crease
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(300, 165);
	glVertex2f(265, 65);
	glVertex2f(295, 70);
	glEnd();

	//right crease
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(320, 155);
	glVertex2f(325, 70);
	glVertex2f(355, 65);
	glEnd();

	//robe upper
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(245, 238);
	glVertex2f(260, 184);
	glVertex2f(265, 170);
	glVertex2f(300, 145);
	glVertex2f(330, 135);
	glVertex2f(385, 185);
	glVertex2f(355, 240);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(388, 75);
	glVertex2f(393, 77);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(398, 80);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(385, 185);
	glVertex2f(330, 135);
	glEnd();

	//waist right
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(355, 240);
	glVertex2f(385, 185);
	glVertex2f(390, 240);
	//glVertex2f(390, 77);
	glEnd();

	//mid left crease
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(280, 215);
	glVertex2f(288, 200);
	glVertex2f(320, 155);
	glVertex2f(360, 135);
	glVertex2f(330, 170);
	glEnd();

	//mid right crease
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(310, 215);
	glVertex2f(330, 190);
	glVertex2f(360, 160);
	glVertex2f(348, 190);
	glEnd();
	int n = 16;
	//zpratz
	//zhair
	glColor3f(0.55, 0.55, 0.55);
	glBegin(GL_POLYGON);

	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 320 + sin(angle) * 120;
		y2 = 350 + cos(angle) * 130;
		glVertex2f(x2, y2);
	}
	glEnd();

	for (float i = 1; i <= n; i++) {
		x1 = 320 + 110 * sin((i * 360 / n) * DEG2RAD);
		y1 = 350 + 120 * cos((i * 360 / n) * DEG2RAD);
		glBegin(GL_POLYGON);
		for (angle = 1.0f; angle < 361.0f; angle += 0.2)
		{
			x2 = x1 + sin(angle) * 25;
			y2 = y1 + cos(angle) * 25;
			glVertex2f(x2, y2);
		}
		glEnd();
	}
	//zface
	drawface();
	//zbeard
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);

	for (angle = 90; angle < 270; angle += 0.2)
	{
		x2 = 320 + sin(angle * DEG2RAD) * 95;
		y2 = 330 + cos(angle*DEG2RAD) * 100;
		glVertex2f(x2, y2);
	}
	glEnd();

	for (float i = 1; i <= n / 2 - 1; i++) {
		//printf("%f\n",(i * 360 / n));
		x1 = 320 + 80 * sin((90 + i * 360 / n) * DEG2RAD);
		y1 = 330 + 95 * cos((90 + i * 360 / n) * DEG2RAD);
		//glVertex2f(x1, y1);
		glBegin(GL_POLYGON);
		for (angle = 1.0f; angle < 361.0f; angle += 0.2)
		{
			x2 = x1 + sin(angle) * 35;
			y2 = y1 + cos(angle) * 35;
			glVertex2f(x2, y2);
		}
		glEnd();
	}
	//zeyes
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 280 + cos(angle) * 10;
		y2 = 350 + sin(angle) * 10;
		glVertex2f(x2, y2);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 355 + cos(angle*DEG2RAD) * 10;
		y2 = 350 + sin(angle*DEG2RAD) * 10;
		glVertex2f(x2, y2);
	}
	glEnd();
	//zmouth
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 317.5 + cos(angle*DEG2RAD) * 30;
		y2 = 295 + sin(angle*DEG2RAD) * 20;
		glVertex2f(x2, y2);
	}
	glEnd();
	drawmouth();
	glFlush();
}

void display() {
	
	glClearColor(0.6, 0.6, 0.9, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	drawzeus();
	//drawcloud();
	drawlightning();
}

//void reshape(int w, int h) {
//	
//	if(w>=h)
//		glViewport(0, 0, (GLsizei)h, (GLsizei)h);
//	else
//		glViewport(0, 0, (GLsizei)w, (GLsizei)w);
//}

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
	glScalef(0.5, 0.5, 0.5);
	glTranslatef(1100, 400, 0);

}

void idle() {
	//glutPostRedisplay();
	//glutDisplayFunc(display);
	drawlightning();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("Zues");
	myinit();
	glutDisplayFunc(display);
	glutFullScreen();
	glutIdleFunc(idle);
	//glutReshapeFunc(reshape);
	glutMainLoop();
}



