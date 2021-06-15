#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include <time.h>

int i, j, score = 0, flag = 1;
float x1 = 0, y2 = 0, num = 1;
int visible[5] = {1, 1, 1, 1, 1};

void init()
{
	glClearColor(0.4, 0, 0.2, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, -50, 50);
}

void welcomeDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	char title[] = "FLIGEL";
	glColor3d(1, 1, 1);
	glRasterPos2d(240, 400);
	for (i = 0;i < sizeof(title);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);

	char heading[] = "SUBMITTED BY";
	glColor3d(1, 1, 1);
	glRasterPos2d(220, 300);
	for (i = 0;i < sizeof(heading);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, heading[i]);


	char member1[] = "SIMONNE LETETIA PINTO           USN: 4SO18CS110";
	glColor3d(1, 1, 1);
	glRasterPos2d(120, 250);
	for (i = 0;i < sizeof(member1);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, member1[i]);

	char member2[] = "SIONA CRISSEL D'SOUZA           USN: 4SO18CS111";
	glColor3d(1, 1, 1);
	glRasterPos2d(120, 220);
	for (i = 0;i < sizeof(member2);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, member2[i]);


	glutSwapBuffers();
}

void scoreboard() {
	glColor3d(1, 1, 1);
	char arrow_keys[] = "Use arrow keys for moving up, down, right and left ";
	glColor3d(1, 1, 1);
	glRasterPos2d(2, 490);
	for (i = 0;i < sizeof(arrow_keys);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, arrow_keys[i]);

	glColor3d(1, 1, 1);
	char direction_keys[] = "u: Move diagonally upwards  d: move diagonally downwards";
	glColor3d(1, 1, 1);
	glRasterPos2d(310, 490);
	for (i = 0;i < sizeof(direction_keys);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, direction_keys[i]);

	glColor3d(1, 1, 1);
	char title[] = "SCORE :";
	glColor3d(1, 1, 1);
	glRasterPos2d(210, 460);
	for (i = 0;i < sizeof(title);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);

	glRasterPos2d(245, 460);
	char txt[32];
	sprintf_s(txt, "%6d", score);
	for (i = 0;i < sizeof(title);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, txt[i]);
}

void bricks(int x) {
	glColor3d(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2d(x, 300.0);
	glVertex2d(x + 15, 300.0);
	glVertex2d(x + 15, 315.0);
	glVertex2d(x, 315.0);
	glEnd();
}
void castle()
{
	int k;
	//Sky 
	glColor3d(0.0, 0.7, 0.96);
	glBegin(GL_POLYGON);
	glVertex2d(0.0, 300.0);
	glVertex2d(500.0, 30.0);
	glVertex2d(500.0, 500.0);
	glVertex2d(0.0, 500.0);
	glEnd();

	//Castle ground
	glColor3d(0.2, 0.6, 0.2);
	glBegin(GL_POLYGON);
	glVertex2d(0.0, 0.0);
	glVertex2d(500.0, 0.0);
	glVertex2d(500.0, 100.0);
	glVertex2d(0.0, 100.0);
	glEnd();

	//Main castle wall
	glColor3d(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2d(0.0, 100.0);
	glVertex2d(500.0, 100.0);
	glVertex2d(500.0, 300.0);
	glVertex2d(0.0, 300.0);
	glEnd();

	//window on wall(left)
	glColor3d(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2d(80.0, 230.0);
	glVertex2d(170.0, 230.0);
	glVertex2d(170.0, 270.0);
	glVertex2d(80.0, 270.0);
	glEnd();

	//window on wall(right)
	glColor3d(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2d(330.0, 230.0);
	glVertex2d(420.0, 230.0);
	glVertex2d(420.0, 270.0);
	glVertex2d(330.0, 270.0);
	glEnd();


	//Tomb structure(left)
	glColor3d(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2d(50, 100.0);
	glVertex2d(50.0, 320.0);
	glVertex2d(0.0, 320.0);
	glVertex2d(0.0, 100.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(50.0, 320.0);
	glVertex2d(60.0, 320.0);
	glVertex2d(60.0, 380.0);
	glVertex2d(50.0, 380.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(50.0, 320.0);
	glVertex2d(50.0, 350.0);
	glVertex2d(40.0, 350.0);
	glVertex2d(40.0, 320.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(40.0, 320.0);
	glVertex2d(40.0, 380.0);
	glVertex2d(25.0, 380.0);
	glVertex2d(25.0, 320.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(25.0, 320.0);
	glVertex2d(25.0, 350.0);
	glVertex2d(15.0, 350.0);
	glVertex2d(15.0, 320.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(15.0, 320.0);
	glVertex2d(15.0, 380.0);
	glVertex2d(0.0, 380.0);
	glVertex2d(0.0, 320.0);
	glEnd();


	//Tomb structure(right)
	glColor3d(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2d(500 - 50, 100.0);
	glVertex2d(500 - 50.0, 320.0);
	glVertex2d(500.0, 320.0);
	glVertex2d(500.0, 100.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(500 - 50.0, 320.0);
	glVertex2d(500 - 60.0, 320.0);
	glVertex2d(500 - 60.0, 380.0);
	glVertex2d(500 - 50.0, 380.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(500 - 50.0, 320.0);
	glVertex2d(500 - 50.0, 350.0);
	glVertex2d(500 - 40.0, 350.0);
	glVertex2d(500 - 40.0, 320.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(500 - 40.0, 320.0);
	glVertex2d(500 - 40.0, 380.0);
	glVertex2d(500 - 25.0, 380.0);
	glVertex2d(500 - 25.0, 320.0);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2d(500 - 25.0, 320.0);
	glVertex2d(500 - 25.0, 350.0);
	glVertex2d(500 - 15.0, 350.0);
	glVertex2d(500 - 15.0, 320.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(500 - 15.0, 320.0);
	glVertex2d(500 - 15.0, 380.0);
	glVertex2d(500.0, 380.0);
	glVertex2d(500.0, 320.0);
	glEnd();


	//Tomb(big) structure(left)
	glColor3d(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2d(100, 300.0);
	glVertex2d(100.0, 400.0);
	glVertex2d(100.0 + 50, 400.0);
	glVertex2d(100.0 + 50, 300.0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2d(100.0, 400.0);
	glVertex2d(100.0 + 25.0, 450.0);
	glVertex2d(100.0 + 50.0, 400.0);
	glEnd();

	glColor3d(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2d(115, 330.0);
	glVertex2d(115, 380.0);
	glVertex2d(135, 380.0);
	glVertex2d(135, 330.0);
	glEnd();

	glColor3d(0.2, 0.2, 0.2);
	glBegin(GL_LINES);
	glVertex2d(115, 330.0);
	glVertex2d(135, 380.0);
	glVertex2d(115, 380.0);
	glVertex2d(135, 330.0);
	glEnd();

	//Tomb(big) structure(right)
	glColor3d(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2d(450 - 100, 300.0);
	glVertex2d(450 - 100.0, 400.0);
	glVertex2d(450 - 100.0 + 50, 400.0);
	glVertex2d(450 - 100.0 + 50, 300.0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2d(450 - 100.0, 400.0);
	glVertex2d(450 - 100.0 + 25.0, 450.0);
	glVertex2d(450 - 100.0 + 50.0, 400.0);
	glEnd();

	glColor3d(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2d(365, 330.0);
	glVertex2d(365, 380.0);
	glVertex2d(385, 380.0);
	glVertex2d(385, 330.0);
	glEnd();

	glColor3d(0.2, 0.2, 0.2);
	glBegin(GL_LINES);
	glVertex2d(365, 330.0);
	glVertex2d(385, 380.0);
	glVertex2d(365, 380.0);
	glVertex2d(385, 330.0);
	glEnd();

	//Main Door
	glColor3d(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2d(200.0, 100.0);
	glVertex2d(300.0, 100.0);
	glVertex2d(300.0, 300.0);
	glVertex2d(250.0, 400.0);
	glVertex2d(200.0, 300.0);
	glEnd();

	glColor3d(0.25, 0.25, 0.25);
	glBegin(GL_POLYGON);
	glVertex2d(230, 100.0);
	glVertex2d(270, 100.0);
	glVertex2d(270, 250.0);
	glVertex2d(230, 250.0);
	glEnd();

	//windows
	glColor3d(0.3, 0.3, 0.3);
	glPointSize(25);
	glBegin(GL_POINTS);
	glVertex2d(25, 200);
	glVertex2d(25, 250);
	glVertex2d(475, 200);
	glVertex2d(475, 250);
	glEnd();

	//bricks
	bricks(70);
	bricks(90);
	bricks(110);
	bricks(130);
	bricks(150);
	bricks(170);
	bricks(320);
	bricks(340);
	bricks(360);
	bricks(380);
	bricks(400);
	bricks(420);
}

void newCircle(float x, float y, float radius) {
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

	glPointSize(2);
	glBegin(GL_POINTS);
	for (int i = 0;i < 3600;++i)
	{
		float th = i * 3.142 / 1800;
		glVertex2f(x + cos(th) * radius, y + sin(th) * radius);
	}
	glEnd();
}

void hoop(float x, float y){

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(x, 0.0);
	glVertex2d(x + 2, 0.0);
	glVertex2d(x + 2, y);
	glVertex2d(x, y);
	glEnd();

	glPushMatrix();
	glTranslatef(x, 50 + y, 0);   
	glRotatef(70, 0, 1, 0);
	newCircle(0, 0, 50);
	glPopMatrix();
}


void snitch(int id, int x, int y) {
	if (num == 6) {
		num = 1;
		for (int k = 1; k < 5; k++)
			visible[k] = 1;
	}

	glColor3f(0.95, 0.84, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0;i < 3600;++i)
	{
		float th = i * 3.142 / 1800;
		glVertex2f(7 * cos(th) + x, 7 * sin(th) + y);
	}
	glEnd();
	glColor3f(0.9, 1, 1);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(7 + x, y);
	glVertex2f(12 + x, 7 + y);
	glVertex2f(18 + x, 3 + y);
	glVertex2f(25 + x, y);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x - 7, y);
	glVertex2f(x - 12, y + 7);
	glVertex2f(x - 18, y + 3);
	glVertex2f(x - 25, y);
	glEnd();


	if (((x == 2*x1)) && ((y == y2)) && (num == id)) {
		flag = 0;
		num++;
		visible[id - 1] = 0;
	}
}

void playground() {
	hoop(55, 130);

	if(visible[0] == 1)
		snitch(1, 100, 200); 

	hoop(180, 90);
	if (visible[1] == 1)
		snitch(2, 232, 120);

	hoop(340, 180);

	hoop(450, 125);
	if (visible[2] == 1)
		snitch(3, 420, 100);

	hoop(550, 85);

	hoop(680, 190);
	if (visible[3] == 1)
		snitch(4, 700, 200);

	hoop(800, 100);
	if (visible[4] == 1)
		snitch(5, 832, 170);
	
	if (visible[4] == 0 && x1 == 500)
		visible[0] = 1;
		
	hoop(940, 70);

}

void harry()
{
	//Leg
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(0, 10);
	glVertex2d(10, 10);
	glVertex2d(10, 20);
	glVertex2d(0, 20);

	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(0, 10);
	glVertex2d(25, 10);
	glVertex2d(20, 20);
	glVertex2d(0, 20);
	glEnd();
	//Socks 
	glColor3d(0.9, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2d(0.0, 20.0);
	glVertex2d(10.0, 20.0);
	glVertex2d(10.0, 40.0);
	glVertex2d(0.0, 40.0);
	glEnd();
	glColor3d(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0, 20.0);
	glVertex2d(10.0, 20.0);
	glVertex2d(10.0, 40.0);
	glVertex2d(0.0, 40.0);
	glEnd();

	glColor3d(0.9, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2d(10.0, 20.0);
	glVertex2d(20.0, 20.0);
	glVertex2d(20.0, 40.0);
	glVertex2d(10.0, 40.0);
	glEnd();
	glColor3d(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(10.0, 20.0);
	glVertex2d(20.0, 20.0);
	glVertex2d(20.0, 40.0);
	glVertex2d(10.0, 40.0);
	glEnd();

	//Trousers
	glColor3f(0.1, 0.2, 0.3);
	glBegin(GL_POLYGON);
	glVertex2d(0, 40);
	glVertex2d(20, 40);
	glVertex2d(20, 50);
	glVertex2d(0, 50);
	glEnd();
	//Shirt
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(0, 50);
	glVertex2d(20, 50);
	glVertex2d(20, 70);
	glVertex2d(0, 70);
	glEnd();

	//Head
	glColor3f(0.9, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2d(0, 70);
	glVertex2d(20, 70);
	glVertex2d(20, 90);
	glVertex2d(0, 90);
	glEnd();

	//Hair
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(0, 70);
	glVertex2d(5, 70);
	glVertex2d(5, 90);
	glVertex2d(0, 90);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2d(0, 90);
	glVertex2d(2, 104);
	glVertex2d(10, 95);
	glVertex2d(3, 95);
	glVertex2d(9, 103);
	glVertex2d(16, 95);
	glVertex2d(5, 90);
	glVertex2d(18, 104);
	glVertex2d(20, 90);
	glEnd();

	//Eye
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2d(15, 85);
	glEnd();
}

void move()
{
	printf("%f", x1);
	printf("%f", y2);

	if (flag == 0) {
		flag = 1;
		score = score + 1;
	}

	glPushMatrix();
	glTranslatef(-x1, 0, 0);
	playground();
	glFlush();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(x1, y2, 0);
	harry();
	glFlush();
	glPopMatrix();

	glPushMatrix();
	scoreboard(); 
	glFlush();
	glPopMatrix();

	glutSwapBuffers();
	//glutPostRedisplay();

}

void myKey(unsigned char key, int x, int y)
{
	if (key == 'u')
	{
		if (x1  < 500)
			x1 += 1;
		else if (x1 == 500)
			x1 = 0;
	}
	if (key == 'd')
	{
		if (x1 > 0)
			x1 -= 1;
		else if (x1 <= 0)
			x1 = 500;
	}
	if (key == 'u')
	{
		if (y2 < 500)
			y2 += 1;
		else if (y2 == 500)
			y2 = 0;
	}
	if (key == 'd')
	{
		if (y2 > 0)
			y2 -= 1;
		else if (y2 <= 0)
			y2 = 500;
	}	
}

void mainKey(int key, int x, int y) {
	if (key == GLUT_KEY_RIGHT)
	{
		if (x1 < 500)
			x1 += 2;
		else if (x1 == 500)
			x1 = 0;
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (x1 > 0)
			x1 -= 2;
		else if (x1 <= 0)
			x1 = 500;
	}
	if (key == GLUT_KEY_UP)
	{
		if (y2 < 500)
			y2 += 2;
		else if (y2 == 500)
			y2 = 0;
	}
	if (key == GLUT_KEY_DOWN)
	{
		if (y2 > 0)
			y2 -= 2;
		else if (y2 <= 0)
			y2 = 500;
	}
}

void display()
{
	castle();
	move();
	glutPostRedisplay();
}

void myTimer(int val) {
	glutDisplayFunc(display);
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(150, 0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("FLIGEL");
	init();
	glutDisplayFunc(welcomeDisplay);
	glutTimerFunc(2000, myTimer, 0);
	glutSpecialFunc(mainKey);
	glutKeyboardFunc(myKey);
	glutMainLoop();
}