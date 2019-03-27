#include <iostream>
#include <ctime>
#include <vector>
#include <GL/glut.h>

using namespace std;




class Position
{
public:
	Position(float X = 0.0, float Y = 0.0)
		: x(X), y(Y)
	{}
	float x, y;
};

vector<Position> vecClouds;
vector<Position> vecHouses;
vector<Position> vecMales;
vector<Position> vecFemales;


const int CLOUD = 0;
const int HOUSE = 1;
const int FEMALE = 2;
const int MALE = 3;

bool bDrawCloud = false;
bool bDrawHouse = false;
bool bDrawFemale = false;
bool bDrawMale = false;

Position posMotion;

void drawCircle(double centerX, double centerY, double radiusX, double radiusY);
void drawCircleFilled(double centerX, double centerY, double radiusX, double radiusY);
void drawHouse(const Position& pos);
void drawMale(const Position& pos);
void drawFemale(const Position& pos);
void drawCloud(const Position& pos);
void drawBackground();



float width, height;    // global variables to store window width and height

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);    // set display-window color to white
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

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);        // clear display window


	drawBackground();
	if (bDrawHouse)
		drawHouse(posMotion);
	for (unsigned int i = 0; i < vecHouses.size(); ++i)
		drawHouse(vecHouses[i]);

	if (bDrawMale)
		drawMale(posMotion);
	for (unsigned int i = 0; i < vecMales.size(); ++i)
		drawMale(vecMales[i]);

	if (bDrawFemale)
		drawFemale(posMotion);
	for (unsigned int i = 0; i < vecFemales.size(); ++i)
		drawFemale(vecFemales[i]);

	if (bDrawCloud)
		drawCloud(posMotion);
	for (unsigned int i = 0; i < vecClouds.size(); ++i) {
		drawCloud(vecClouds[i]);
	}
	//move the clouds :P
	for (unsigned int i = 0; i < vecClouds.size(); ++i) {
		vecClouds[i].x += 0.1;
		if (vecClouds[i].x >= width)
			vecClouds[i].x = 0;
	}


	glFlush();            // process all openGl routines as quickly as possible
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 'R' || key == 'r') // reset all
	{
		vecClouds.clear();
		vecHouses.clear();
		vecFemales.clear();
		vecMales.clear();
	}
	if (key == 'Z' || key == 'z') {
		if (bDrawFemale) {
			if (vecFemales.size() != 0)
				vecFemales.erase(vecFemales.end() - 1);
		}
		else if (bDrawHouse) {
			if (vecHouses.size() != 0)
				vecHouses.erase(vecHouses.end() - 1);
		}
		else if (bDrawMale) {
			if (vecMales.size() != 0)
				vecMales.erase(vecMales.end() - 1);
		}
		else if (bDrawCloud) {
			if (vecClouds.size() != 0)
				vecClouds.erase(vecClouds.end() - 1);
		}

	}

	if (key == 27) //exit the screen on esc
		exit(0);
}

void mouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (bDrawMale)
			vecMales.push_back(Position(x, height - y));

		if (bDrawHouse)
			vecHouses.push_back(Position(x, height - y));

		if (bDrawFemale)
			vecFemales.push_back(Position(x, height - y));

		if (bDrawCloud)
			vecClouds.push_back(Position(x, height - y));

	}
}

void passiveMouseMotion(int x, int y)
{
	posMotion.x = x;
	posMotion.y = height - y;
}

void processMenuEvents(int option)
{

	switch (option)
	{

	case MALE:    bDrawCloud = false;
		bDrawHouse = false;
		bDrawMale = true;
		bDrawFemale = false;
		break;

	case FEMALE:    bDrawCloud = false;
		bDrawHouse = false;
		bDrawMale = false;
		bDrawFemale = true;
		break;

	case HOUSE: bDrawCloud = false;
		bDrawHouse = true;
		bDrawMale = false;
		bDrawFemale = false;
		break;

	case CLOUD:bDrawCloud = true;
		bDrawHouse = false;
		bDrawMale = false;
		bDrawFemale = false;
		break;


	}
}

void createMenu()
{
	// create people submenu
	int menuPeople = glutCreateMenu(processMenuEvents);
	//add entries to submenu
	glutAddMenuEntry("Female", FEMALE);
	glutAddMenuEntry("Male", MALE);

	// create popup menu
	int menu = glutCreateMenu(processMenuEvents);
	//add entries to menu
	glutAddMenuEntry("Cloud", CLOUD);
	glutAddMenuEntry("House", HOUSE);

	// attach submenu to main menu
	glutAddSubMenu("People", menuPeople);

	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void main(int argc, char** argv)
{

	glutInit(&argc, argv);                            // initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // set display mode
	glutInitWindowPosition(20, 20);        // set top left display window position
	glutInitWindowSize(600, 600);            // set display window width and height
	glutCreateWindow("Graphic's HW");    // create display window

	init();                                // execute initialization function
	createMenu();
	glutKeyboardFunc(processNormalKeys);
	glutMouseFunc(mouseClick);
	glutPassiveMotionFunc(passiveMouseMotion);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);                // send graphics to display window
	glutIdleFunc(display);
	glutMainLoop();                        // dispaly everthing and wait
}

void drawCircle(double centerX, double centerY, double radiusX, double radiusY)
{
	const float DEG2RAD = 3.14159 / 180;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(centerX + cos(degInRad) * radiusX,
			centerY + sin(degInRad) * radiusY);
	}
	glEnd();
}

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
}

void drawHouse(const Position& pos)
{
	// draw house roof
	float roofBase = 0.07 * width;
	float roofHeight = 0.07 * height;
	glColor3f(80 / 255.0, 67 / 255.0, 169 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(pos.x - roofBase / 2, pos.y);
	glVertex2f(pos.x, pos.y + roofHeight * 5 / 6);
	glVertex2f(pos.x + roofBase / 2, pos.y);
	glEnd();



	//draw the rest of the roof
	glColor3f(26 / 255.0, 15 / 255.0, 92 / 255.0);
	glBegin(GL_QUADS);
	glVertex2f(pos.x, pos.y + roofHeight * 5 / 6);
	glVertex2f(pos.x + roofBase / 2, pos.y);
	glVertex2f(pos.x + roofBase / 2 + roofBase * 2, pos.y);
	glVertex2f(pos.x + roofBase / 2 + roofBase * 16 / 10, pos.y + roofHeight * 5 / 6);
	glEnd();



	// draw house wall
	float wallWidth = roofBase;
	float wallHeight = roofHeight * 5 / 4;
	glColor3f(80 / 255.0, 80 / 255.0, 80 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(pos.x - wallWidth / 2, pos.y);
	glVertex2f(pos.x + wallWidth / 2, pos.y);
	glVertex2f(pos.x + wallWidth / 2, pos.y - wallHeight);
	glVertex2f(pos.x - wallWidth / 2, pos.y - wallHeight);
	glEnd();



	//draw the rest of the wall
	glColor3f(60 / 255.0, 60 / 255.0, 60 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(pos.x + wallWidth / 2, pos.y);
	glVertex2f(pos.x + wallWidth / 2, pos.y - wallHeight);
	glVertex2f(pos.x + wallWidth / 2 + wallWidth * 2, pos.y - wallHeight);
	glVertex2f(pos.x + wallWidth / 2 + wallWidth * 2, pos.y);
	glEnd();

	//draw left window
	glColor3f(255 / 255.0, 204 / 255.0, 51 / 255.0);
	glBegin(GL_QUADS);
	glVertex2f(pos.x + wallWidth * 9 / 10, pos.y - wallHeight / 3);
	glVertex2f(pos.x + wallWidth * 9 / 10, pos.y - wallHeight + wallHeight / 3);
	glVertex2f(pos.x + wallWidth * 9 / 10 + wallWidth * 4 / 9, pos.y - wallHeight + wallHeight / 3);
	glVertex2f(pos.x + wallWidth * 9 / 10 + wallWidth * 4 / 9, pos.y - wallHeight / 3);
	glEnd();

	//draw right window
	glColor3f(255 / 255.0, 204 / 255.0, 51 / 255.0);
	glBegin(GL_QUADS);
	glVertex2f(pos.x + wallWidth * 7 / 4, pos.y - wallHeight / 3);
	glVertex2f(pos.x + wallWidth * 7 / 4, pos.y - wallHeight + wallHeight / 3);
	glVertex2f(pos.x + wallWidth * 7 / 4 + wallWidth * 4 / 9, pos.y - wallHeight + wallHeight / 3);
	glVertex2f(pos.x + wallWidth * 7 / 4 + wallWidth * 4 / 9, pos.y - wallHeight / 3);
	glEnd();

	// draw door
	float doorWidth = wallWidth / 4.0;
	float doorHeight = wallHeight / 1.9;
	glColor3f(204 / 255.0, 204 / 255.0, 153 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(pos.x - doorWidth, pos.y - (wallHeight - doorHeight));
	glVertex2f(pos.x + doorWidth, pos.y - (wallHeight - doorHeight));
	glVertex2f(pos.x + doorWidth, pos.y - wallHeight);
	glVertex2f(pos.x - doorWidth, pos.y - wallHeight);
	glEnd();

}

void drawMale(const Position& pos)
{
	glColor3f(26 / 255.0, 15 / 255.0, 92 / 255.0);

	double scale = width / 100.0;
	// draw head
	double headScale = scale;
	double refX = pos.x - headScale / 2.0;
	double refY = pos.y - headScale / 2.0;
	drawCircleFilled(refX + headScale / 2, refY + headScale, headScale, headScale);

	// draw neck
	double neckScale = scale / 3.0;
	refX = pos.x - neckScale / 2.0;
	refY = pos.y - headScale / 2.0;
	glBegin(GL_QUADS);
	glVertex2d(refX, refY);
	glVertex2d(refX + neckScale, refY);
	glVertex2d(refX + neckScale, refY - neckScale);
	glVertex2d(refX, refY - neckScale);
	glEnd();

	// draw chest
	double chestScale = scale * 1.75;
	refX -= (chestScale / 2.0 - neckScale / 2.0);
	refY -= neckScale;
	glBegin(GL_QUADS);
	glVertex2d(refX, refY);
	glVertex2d(refX + chestScale, refY);
	glVertex2d(refX + chestScale, refY - chestScale);
	glVertex2d(refX, refY - chestScale);
	glEnd();

	// draw left leg
	double legWidth = chestScale / 3.0;
	double legHeight = chestScale;
	refX += legWidth / 3.0;
	refY -= chestScale;
	glBegin(GL_QUADS);
	glVertex2d(refX, refY);
	glVertex2d(refX + legWidth, refY);
	glVertex2d(refX + legWidth, refY - legHeight);
	glVertex2d(refX, refY - legHeight);
	glEnd();

	refX += legWidth + legWidth / 3.0;
	// draw right leg
	glBegin(GL_QUADS);
	glVertex2d(refX, refY);
	glVertex2d(refX + legWidth, refY);
	glVertex2d(refX + legWidth, refY - legHeight);
	glVertex2d(refX, refY - legHeight);
	glEnd();

}

void drawFemale(const Position& pos)
{
	glColor3f(1.0, 0.0, 127 / 255.0);

	double scale = width / 100.0;
	// draw head
	double headScale = scale;
	double refX = pos.x - headScale / 2.0;
	double refY = pos.y - headScale / 2.0;
	glLineWidth(2.0);
	drawCircleFilled(refX + headScale / 2, refY + headScale, headScale, headScale);


	// draw body
	double neckScale = scale / 3.0;
	refX = pos.x - neckScale / 2.0;
	refY = pos.y - headScale / 2.0;
	double chestScale = scale * 1.75;
	refX -= (chestScale / 2.0 - neckScale / 2.0);
	refY -= neckScale;
	drawCircleFilled(refX + chestScale / 2, refY - chestScale / 2, chestScale / 2, chestScale * 3 / 4);


	// draw dress
	double legWidth = chestScale / 2.0;
	double legHeight = chestScale;
	refX += legWidth / 2.0;
	refY -= chestScale;
	glBegin(GL_QUADS);
	glVertex2d(refX, refY);
	glVertex2d(refX + legWidth, refY);
	glVertex2d(refX + legWidth + legWidth, refY - legHeight);
	glVertex2d(refX - legWidth, refY - legHeight);
	glEnd();

	refX += legWidth + legWidth / 3.0;


}

void drawCloud(const Position& pos)
{
	int x = pos.x, y = pos.y;

	glColor3f(255.0, 255.0, 255.0);
	drawCircleFilled(x, y, 80, 45);
	glColor3f(255.0, 255.0, 255.0);
	drawCircleFilled(x + 25, y + 15, 35, 35);
	glColor3f(255.0, 255.0, 255.0);
	drawCircleFilled(x + 25, y - 15, 35, 35);
	glColor3f(255.0, 255.0, 255.0);
	drawCircleFilled(x - 25, y - 15, 35, 35);
	glColor3f(255.0, 255.0, 255.0);
	drawCircleFilled(x - 25, y + 15, 35, 35);
}

void drawBackground() {
	//drawSky

	glColor3f(102 / 255.0, 51 / 255.0, 0 / 255.0);
	glBegin(GL_QUADS);
	glVertex2d(0, 0);
	glVertex2d(width, 0);
	glVertex2d(width, height * 65 / 100);
	glVertex2d(0, height * 65 / 100);
	glEnd();

	//drawLand
	glColor3f(135 / 255.0, 206 / 255.0, 250 / 255.0);
	glBegin(GL_QUADS);
	glVertex2d(0, height * 65 / 100);
	glVertex2d(width, height * 65 / 100);
	glVertex2d(width, height);
	glVertex2d(0, height);
	glEnd();
}