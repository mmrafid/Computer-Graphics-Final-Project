#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
#include<cstdio>
#include <GL/gl.h>
# define PI           3.14159265358979323846

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
GLfloat i = 0.6f;

GLfloat position = 0.0f;
GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat speed = 0.01f;
GLfloat speed1 = 0.01f;
GLfloat speed2 = 0.01f;
GLfloat speed3 = 0.01f;
void demo_morning();
void demo_day(int val);
void demo_night(int val);
void demo_rain(int val);
void demo_evening(int val);
void demo_latenight(int val);
void sound(int val);
void sound2(int val);
void handleKeypress(unsigned char key, int x, int y);
GLfloat moonposition=0.0f;
GLfloat moonspeed=0.01f;
GLfloat moonposition2=0.0f;
GLfloat moonspeed2=0.02f;
GLfloat sunposition2=0.0f;
GLfloat sunspeed2=0.02f;
void moonupdate(int moonvalue) {

    if(moonposition >1.5)
        moonposition = -1.5f;

    moonposition += moonspeed;

	glutPostRedisplay();


	glutTimerFunc(25, moonupdate, 0);
}
void moonupdate2(int moonvalue) {

    if(moonposition2 <-2.5)
        moonposition2 = 2.5f;

    moonposition2 -= moonspeed2;

	glutPostRedisplay();


	glutTimerFunc(25, moonupdate2, 0);
}

void sunupdate2(int sunvalue) {

    if(sunposition2 <-2.0)
        sunposition2 = 2.0f;

    sunposition2 -= sunspeed2;

	glutPostRedisplay();


	glutTimerFunc(25, sunupdate2, 0);
}

//negtopos
void update(int value) {

    if(position >2.50)
        position = -2.50f;

    position += speed;

	glutPostRedisplay();


	glutTimerFunc(22, update, 0);
}
//postoneg
void update1(int value) {

    if(position1 >1.5)
        position1 = -1.5f;

    position1 += speed1;

	glutPostRedisplay();


	glutTimerFunc(25, update1, 0);
}

void update2(int value) {

    if(position2 <-4.0)
        position2 = 2.5f;

    position2 -= speed2;

	glutPostRedisplay();


	glutTimerFunc(25, update2, 0);
}
void update3(int value) {

    if(position3 <-2.5)
        position3 = 2.5f;

    position3 -= speed3;

	glutPostRedisplay();


	glutTimerFunc(25, update3, 0);
}
void sound(int val)
{

    PlaySound("city.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}
void sound2(int val)
{

    PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}


void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void demo_back(int val){

glutDisplayFunc(demo_morning);

}

void day() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);




//Sky
glBegin(GL_QUADS);
        glColor3ub(240, 250, 250);
        glVertex2f(1.0,1.0);
        glVertex2f(-1.0,1.0);
        glVertex2f(-1.0,-0.6);
        glVertex2f(1.0,-0.6);
        glEnd();
//sun



  glPushMatrix();
glTranslatef(position1-1,position1,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(249, 248, 154);
	   int is;
	   float xs=0.77;
	   float ys=0.77;
		glVertex2f(xs, ys);
		for(is = 0; is <= 100;is++) {
			glVertex2f(
		            xs + (0.2 * cos(is *  2.0f*PI/ 100)),
			    ys + (0.2 * sin(is * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//clouds1
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
	   int ic1;
	   float xc1=0.75;
	   float yc1=0.7;
		glVertex2f(xc1, yc1);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc1 + (0.15 * cos(ic1 *  2.0f*PI/ 100)),
			    yc1 + (0.15 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);

	   float xc2=0.9;
	   float yc2=0.68;
		glVertex2f(xc2, yc2);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc2 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc2 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
	   int ic2;
	   float xc3=0.45;
	   float yc3=0.4;
		glVertex2f(xc3, yc3);
		for(ic2 = 0; ic2 <= 100;ic2++) {
			glVertex2f(
		            xc3 + (0.15 * cos(ic2 *  2.0f*PI/ 100)),
			    yc3 + (0.15 * sin(ic2 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);

	   float xc4=0.6;
	   float yc4=0.38;
		glVertex2f(xc4, yc4);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc4 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc4 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();
//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
	   int ic3;
	   float xc5=0.05;
	   float yc5=0.7;
		glVertex2f(xc5, yc5);
		for(ic3 = 0; ic3 <= 100;ic3++) {
			glVertex2f(
		            xc5 + (0.15 * cos(ic3 *  2.0f*PI/ 100)),
			    yc5 + (0.15 * sin(ic3 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);

	   float xc6=0.2;
	   float yc6=0.7;
		glVertex2f(xc5, yc5);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc6 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc6 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();
//Background 1
glBegin(GL_QUADS);//Left_Building1
        glColor3ub(45, 90, 143);
        glVertex2f(-0.9,0.6);
        glVertex2f(-1.0,0.7);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.9,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Left_Building2
        glColor3ub(45, 90, 143);
        glVertex2f(-0.7,0.78);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.88,0.78);
        glVertex2f(-0.88,-0.6);
        glVertex2f(-0.7,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.75,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Left_Building3
        glColor3ub(45, 90, 143);
        glVertex2f(-0.4,0.47);
        glVertex2f(-0.4,0.78);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.6,0.78);
        glVertex2f(-0.6,0.47);
        glVertex2f(-0.69,0.4);
        glVertex2f(-0.69,-0.6);
        glVertex2f(-0.3,-0.6);
        glVertex2f(-0.3,0.4);

        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.5,-0.6);
        glEnd();
//background 2
glBegin(GL_POLYGON);//Right_Building1
        glColor3ub(149, 187, 187);
        glVertex2f(-0.1,0.53);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.35,0.53);
        glVertex2f(-0.35,-0.6);
        glVertex2f(-0.1,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.23,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Right_Building2
        glColor3ub(149, 187, 187);
        glVertex2f(-0.39,0.41);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.65,0.41);
        glVertex2f(-0.65,-0.6);
        glVertex2f(-0.39,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.45,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Right_Building3
        glColor3ub(149, 187, 187);
        glVertex2f(-0.67,0.45);
        glVertex2f(-0.8,0.5);
        glVertex2f(-1.0,0.45);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.67,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.8,0.5);
        glVertex2f(-0.8,-0.6);
        glEnd();
//footpath
glBegin(GL_QUADS);
        glColor3ub(201, 201, 201);
        glVertex2f(1.0,-0.6);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-1.0,-0.8);
        glVertex2f(1.0,-0.8);
        glEnd();

//Building row 2
glTranslatef(-1.15,0.1,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(213, 182, 149);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();


glTranslatef(-0.53,0.1,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(239, 200, 31);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(170, 140, 9);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(-0.5,0.3,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(50, 154, 115);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(0.25,0.25,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(109, 135, 156);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(54, 67, 78);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

//trees
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);
        int it;
	   float xt=0.78;
	   float yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt1=0.8;
	   float yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt2=0.82;
	   float yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();

glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//front buildings
glBegin(GL_POLYGON);//Left Building1
        glColor3ub(184, 46, 46);
        glVertex2f(-0.6,-0.1);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.85,-0.13);
        glVertex2f(-0.85,-0.67);
        glVertex2f(-0.8,-0.7);
        glVertex2f(-0.6,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.8,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.0f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.6);
        glVertex2f(-0.78,-0.6);
        glVertex2f(-0.78,-0.7);
        glVertex2f(-0.62,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building2
        glColor3ub(198, 123, 123);
        glVertex2f(-0.3,-0.25);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.6,-0.27);
        glVertex2f(-0.6,-0.67);
        glVertex2f(-0.55,-0.7);
        glVertex2f(-0.3,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.55,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(0.11f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.33,-0.58);
        glVertex2f(-0.52,-0.58);
        glVertex2f(-0.52,-0.7);
        glVertex2f(-0.33,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building3
        glColor3ub(88, 25, 27);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(31, 5, 6);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.02,-0.6);
        glVertex2f(-0.05,-0.6);
        glVertex2f(-0.05,-0.7);
        glVertex2f(0.02,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building4
        glColor3ub(237, 187, 188);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();

glLoadIdentity();

glLoadIdentity();

glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.35,-0.6);
        glVertex2f(0.25,-0.6);
        glVertex2f(0.25,-0.7);
        glVertex2f(0.35,-0.7);
        glEnd();
glTranslatef(-1.73,-0.08,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
//Street Lights
glLineWidth(4);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();

glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
        glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//road
glBegin(GL_QUADS);
        glColor3ub(158,158,158);
        glVertex2f(1.0,-0.8);
        glVertex2f(-1.0,-0.8);
        glVertex2f(-1.0,-1.0);
        glVertex2f(1.0,-1.0);
        glEnd();
//Road Stripes
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(1.0,-0.89);
        glVertex2f(0.8,-0.89);
        glVertex2f(0.83,-0.91);
        glVertex2f(1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.6,-0.89);
        glVertex2f(0.3,-0.89);
        glVertex2f(0.33,-0.91);
        glVertex2f(0.63,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.12,-0.89);
        glVertex2f(-0.12,-0.89);
        glVertex2f(-0.15,-0.91);
        glVertex2f(0.15,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1.0,-0.89);
        glVertex2f(-0.8,-0.89);
        glVertex2f(-0.83,-0.91);
        glVertex2f(-1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.6,-0.89);
        glVertex2f(-0.3,-0.89);
        glVertex2f(-0.33,-0.91);
        glVertex2f(-0.63,-0.91);
        glEnd();

//left to right
//car
glPushMatrix();
glTranslatef(position,0,0);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(+1.1,0,0);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.88,-0.74);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.876,-0.745);
        glVertex2f(-0.89,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();
//bus
glPushMatrix();
glTranslatef(position,0,0);
glTranslatef(0.4,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.35,-0.675);
        glVertex2f(-0.38,-0.675);
        glVertex2f(-0.38,-0.775);
        glVertex2f(-0.35,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.39,-0.685);
        glVertex2f(-0.89,-0.685);
        glVertex2f(-0.89,-0.765);
        glVertex2f(-0.39,-0.765);

glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.37,-0.84);
        glVertex2f(-0.37,-0.8);
        glVertex2f(-0.35,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.885,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.78);
        glVertex2f(-0.885,-0.78);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.75;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.43;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glPopMatrix();
//right to left
//car
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(0.5,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(1.8,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(1.0,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.72,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.69,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.725,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.7,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glPopMatrix();

//bus
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(1.0,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(-1.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();



glutTimerFunc(5000,demo_rain,0);
	glFlush();
}

void demo_day(int val){

glutDisplayFunc(day);

}

void morning() {

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);




//Sky
glBegin(GL_QUADS);
        glColor3ub(141, 221, 226);
        glVertex2f(1.0,1.0);
        glVertex2f(-1.0,1.0);
        glVertex2f(-1.0,-0.6);
        glVertex2f(1.0,-0.6);
        glEnd();

//clouds1
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
	   int ic1;
	   float xc1=0.75;
	   float yc1=0.7;
		glVertex2f(xc1, yc1);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc1 + (0.15 * cos(ic1 *  2.0f*PI/ 100)),
			    yc1 + (0.15 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);

	   float xc2=0.9;
	   float yc2=0.68;
		glVertex2f(xc2, yc2);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc2 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc2 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
	   int ic2;
	   float xc3=0.45;
	   float yc3=0.4;
		glVertex2f(xc3, yc3);
		for(ic2 = 0; ic2 <= 100;ic2++) {
			glVertex2f(
		            xc3 + (0.15 * cos(ic2 *  2.0f*PI/ 100)),
			    yc3 + (0.15 * sin(ic2 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);

	   float xc4=0.6;
	   float yc4=0.38;
		glVertex2f(xc4, yc4);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc4 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc4 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
	   int ic3;
	   float xc5=0.05;
	   float yc5=0.7;
		glVertex2f(xc5, yc5);
		for(ic3 = 0; ic3 <= 100;ic3++) {
			glVertex2f(
		            xc5 + (0.15 * cos(ic3 *  2.0f*PI/ 100)),
			    yc5 + (0.15 * sin(ic3 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);

	   float xc6=0.2;
	   float yc6=0.7;
		glVertex2f(xc5, yc5);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc6 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc6 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();
glLineWidth(1);
//Background 1
glBegin(GL_QUADS);//Left_Building1
        glColor3ub(45, 90, 143);
        glVertex2f(-0.9,0.6);
        glVertex2f(-1.0,0.7);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.9,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Left_Building2
        glColor3ub(45, 90, 143);
        glVertex2f(-0.7,0.78);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.88,0.78);
        glVertex2f(-0.88,-0.6);
        glVertex2f(-0.7,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.75,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Left_Building3
        glColor3ub(45, 90, 143);
        glVertex2f(-0.4,0.47);
        glVertex2f(-0.4,0.78);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.6,0.78);
        glVertex2f(-0.6,0.47);
        glVertex2f(-0.69,0.4);
        glVertex2f(-0.69,-0.6);
        glVertex2f(-0.3,-0.6);
        glVertex2f(-0.3,0.4);

        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.5,-0.6);
        glEnd();
//background 2
glBegin(GL_POLYGON);//Right_Building1
        glColor3ub(149, 187, 187);
        glVertex2f(-0.1,0.53);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.35,0.53);
        glVertex2f(-0.35,-0.6);
        glVertex2f(-0.1,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.23,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Right_Building2
        glColor3ub(149, 187, 187);
        glVertex2f(-0.39,0.41);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.65,0.41);
        glVertex2f(-0.65,-0.6);
        glVertex2f(-0.39,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.45,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Right_Building3
        glColor3ub(149, 187, 187);
        glVertex2f(-0.67,0.45);
        glVertex2f(-0.8,0.5);
        glVertex2f(-1.0,0.45);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.67,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.8,0.5);
        glVertex2f(-0.8,-0.6);
        glEnd();
//footpath
glBegin(GL_QUADS);
        glColor3ub(201, 201, 201);
        glVertex2f(1.0,-0.6);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-1.0,-0.8);
        glVertex2f(1.0,-0.8);
        glEnd();

//Building row 2
glTranslatef(-1.15,0.1,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(213, 182, 149);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();


glTranslatef(-0.53,0.1,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(239, 200, 31);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(170, 140, 9);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(-0.5,0.3,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(50, 154, 115);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(0.25,0.25,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(109, 135, 156);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(54, 67, 78);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

//trees
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);
        int it;
	   float xt=0.78;
	   float yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt1=0.8;
	   float yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt2=0.82;
	   float yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();

glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//front buildings
glBegin(GL_POLYGON);//Left Building1
        glColor3ub(184, 46, 46);
        glVertex2f(-0.6,-0.1);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.85,-0.13);
        glVertex2f(-0.85,-0.67);
        glVertex2f(-0.8,-0.7);
        glVertex2f(-0.6,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.8,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.0f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.6);
        glVertex2f(-0.78,-0.6);
        glVertex2f(-0.78,-0.7);
        glVertex2f(-0.62,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building2
        glColor3ub(198, 123, 123);
        glVertex2f(-0.3,-0.25);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.6,-0.27);
        glVertex2f(-0.6,-0.67);
        glVertex2f(-0.55,-0.7);
        glVertex2f(-0.3,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.55,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(0.11f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.33,-0.58);
        glVertex2f(-0.52,-0.58);
        glVertex2f(-0.52,-0.7);
        glVertex2f(-0.33,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building3
        glColor3ub(88, 25, 27);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(31, 5, 6);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.02,-0.6);
        glVertex2f(-0.05,-0.6);
        glVertex2f(-0.05,-0.7);
        glVertex2f(0.02,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building4
        glColor3ub(237, 187, 188);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();

glLoadIdentity();

glLoadIdentity();

glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.35,-0.6);
        glVertex2f(0.25,-0.6);
        glVertex2f(0.25,-0.7);
        glVertex2f(0.35,-0.7);
        glEnd();
glTranslatef(-1.73,-0.08,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
//Street Lights
glLineWidth(4);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();

glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
        glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//road
glBegin(GL_QUADS);
        glColor3ub(158,158,158);
        glVertex2f(1.0,-0.8);
        glVertex2f(-1.0,-0.8);
        glVertex2f(-1.0,-1.0);
        glVertex2f(1.0,-1.0);
        glEnd();
//Road Stripes
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(1.0,-0.89);
        glVertex2f(0.8,-0.89);
        glVertex2f(0.83,-0.91);
        glVertex2f(1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.6,-0.89);
        glVertex2f(0.3,-0.89);
        glVertex2f(0.33,-0.91);
        glVertex2f(0.63,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.12,-0.89);
        glVertex2f(-0.12,-0.89);
        glVertex2f(-0.15,-0.91);
        glVertex2f(0.15,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1.0,-0.89);
        glVertex2f(-0.8,-0.89);
        glVertex2f(-0.83,-0.91);
        glVertex2f(-1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.6,-0.89);
        glVertex2f(-0.3,-0.89);
        glVertex2f(-0.33,-0.91);
        glVertex2f(-0.63,-0.91);
        glEnd();

//left to right
//car
glPushMatrix();
glTranslatef(position,0,0);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(+1.1,0,0);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.88,-0.74);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.876,-0.745);
        glVertex2f(-0.89,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();
//bus
glPushMatrix();
glTranslatef(position,0,0);
glTranslatef(0.4,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.35,-0.675);
        glVertex2f(-0.38,-0.675);
        glVertex2f(-0.38,-0.775);
        glVertex2f(-0.35,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.39,-0.685);
        glVertex2f(-0.89,-0.685);
        glVertex2f(-0.89,-0.765);
        glVertex2f(-0.39,-0.765);

glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.37,-0.84);
        glVertex2f(-0.37,-0.8);
        glVertex2f(-0.35,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.885,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.78);
        glVertex2f(-0.885,-0.78);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.75;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.43;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glPopMatrix();
//right to left
//car
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(0.5,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(1.8,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(1.0,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.72,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.69,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.725,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.7,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glPopMatrix();

//bus
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(1.0,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(-1.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();

glutTimerFunc(5000,demo_day,0);
	glFlush();
}
void demo_morning(){

glutDisplayFunc(morning);

}
void evening(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);




//Sky
glBegin(GL_QUADS);
        glColor3ub(255, 136, 102);
        glVertex2f(1.0,1.0);
        glVertex2f(-1.0,1.0);
        glVertex2f(-1.0,-0.6);
        glVertex2f(1.0,-0.6);
        glEnd();



//sun
glPushMatrix();
glTranslatef(0,sunposition2,0);

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(249, 248, 154);
	   int is;
	   float xs=0.77;
	   float ys=0.77;
		glVertex2f(xs, ys);
		for(is = 0; is <= 100;is++) {
			glVertex2f(
		            xs + (0.2 * cos(is *  2.0f*PI/ 100)),
			    ys + (0.2 * sin(is * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//clouds1
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
	   int ic1;
	   float xc1=0.75;
	   float yc1=0.7;
		glVertex2f(xc1, yc1);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc1 + (0.15 * cos(ic1 *  2.0f*PI/ 100)),
			    yc1 + (0.15 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);

	   float xc2=0.9;
	   float yc2=0.68;
		glVertex2f(xc2, yc2);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc2 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc2 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
	   int ic2;
	   float xc3=0.45;
	   float yc3=0.4;
		glVertex2f(xc3, yc3);
		for(ic2 = 0; ic2 <= 100;ic2++) {
			glVertex2f(
		            xc3 + (0.15 * cos(ic2 *  2.0f*PI/ 100)),
			    yc3 + (0.15 * sin(ic2 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);

	   float xc4=0.6;
	   float yc4=0.38;
		glVertex2f(xc4, yc4);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc4 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc4 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
	   int ic3;
	   float xc5=0.05;
	   float yc5=0.7;
		glVertex2f(xc5, yc5);
		for(ic3 = 0; ic3 <= 100;ic3++) {
			glVertex2f(
		            xc5 + (0.15 * cos(ic3 *  2.0f*PI/ 100)),
			    yc5 + (0.15 * sin(ic3 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);

	   float xc6=0.2;
	   float yc6=0.7;
		glVertex2f(xc5, yc5);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc6 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc6 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();
glLineWidth(1);
//Background 1
glBegin(GL_QUADS);//Left_Building1
        glColor3ub(45, 90, 143);
        glVertex2f(-0.9,0.6);
        glVertex2f(-1.0,0.7);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.9,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Left_Building2
        glColor3ub(45, 90, 143);
        glVertex2f(-0.7,0.78);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.88,0.78);
        glVertex2f(-0.88,-0.6);
        glVertex2f(-0.7,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.75,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Left_Building3
        glColor3ub(45, 90, 143);
        glVertex2f(-0.4,0.47);
        glVertex2f(-0.4,0.78);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.6,0.78);
        glVertex2f(-0.6,0.47);
        glVertex2f(-0.69,0.4);
        glVertex2f(-0.69,-0.6);
        glVertex2f(-0.3,-0.6);
        glVertex2f(-0.3,0.4);

        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.5,-0.6);
        glEnd();
//background 2
glBegin(GL_POLYGON);//Right_Building1
        glColor3ub(149, 187, 187);
        glVertex2f(-0.1,0.53);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.35,0.53);
        glVertex2f(-0.35,-0.6);
        glVertex2f(-0.1,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.23,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Right_Building2
        glColor3ub(149, 187, 187);
        glVertex2f(-0.39,0.41);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.65,0.41);
        glVertex2f(-0.65,-0.6);
        glVertex2f(-0.39,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.45,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Right_Building3
        glColor3ub(149, 187, 187);
        glVertex2f(-0.67,0.45);
        glVertex2f(-0.8,0.5);
        glVertex2f(-1.0,0.45);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.67,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.8,0.5);
        glVertex2f(-0.8,-0.6);
        glEnd();
//footpath
glBegin(GL_QUADS);
        glColor3ub(201, 201, 201);
        glVertex2f(1.0,-0.6);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-1.0,-0.8);
        glVertex2f(1.0,-0.8);
        glEnd();

//Building row 2
glTranslatef(-1.15,0.1,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(213, 182, 149);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();


glTranslatef(-0.53,0.1,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(239, 200, 31);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(170, 140, 9);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(-0.5,0.3,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(50, 154, 115);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(0.25,0.25,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(109, 135, 156);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(54, 67, 78);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

//trees
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);
        int it;
	   float xt=0.78;
	   float yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt1=0.8;
	   float yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt2=0.82;
	   float yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();

glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//front buildings
glBegin(GL_POLYGON);//Left Building1
        glColor3ub(184, 46, 46);
        glVertex2f(-0.6,-0.1);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.85,-0.13);
        glVertex2f(-0.85,-0.67);
        glVertex2f(-0.8,-0.7);
        glVertex2f(-0.6,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.8,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.0f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.6);
        glVertex2f(-0.78,-0.6);
        glVertex2f(-0.78,-0.7);
        glVertex2f(-0.62,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building2
        glColor3ub(198, 123, 123);
        glVertex2f(-0.3,-0.25);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.6,-0.27);
        glVertex2f(-0.6,-0.67);
        glVertex2f(-0.55,-0.7);
        glVertex2f(-0.3,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.55,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(0.11f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.33,-0.58);
        glVertex2f(-0.52,-0.58);
        glVertex2f(-0.52,-0.7);
        glVertex2f(-0.33,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building3
        glColor3ub(88, 25, 27);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(31, 5, 6);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.02,-0.6);
        glVertex2f(-0.05,-0.6);
        glVertex2f(-0.05,-0.7);
        glVertex2f(0.02,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building4
        glColor3ub(237, 187, 188);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();

glLoadIdentity();

glLoadIdentity();

glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.35,-0.6);
        glVertex2f(0.25,-0.6);
        glVertex2f(0.25,-0.7);
        glVertex2f(0.35,-0.7);
        glEnd();
glTranslatef(-1.73,-0.08,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
//Street Lights
glLineWidth(4);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.675,-0.525);
        glVertex2f(-0.775,-0.75);
        glVertex2f(-0.575,-0.75);
        glEnd();
glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
        glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.675,-0.525);
        glVertex2f(-0.775,-0.75);
        glVertex2f(-0.575,-0.75);
        glEnd();
        glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//road
glBegin(GL_QUADS);
        glColor3ub(158,158,158);
        glVertex2f(1.0,-0.8);
        glVertex2f(-1.0,-0.8);
        glVertex2f(-1.0,-1.0);
        glVertex2f(1.0,-1.0);
        glEnd();
//Road Stripes
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(1.0,-0.89);
        glVertex2f(0.8,-0.89);
        glVertex2f(0.83,-0.91);
        glVertex2f(1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.6,-0.89);
        glVertex2f(0.3,-0.89);
        glVertex2f(0.33,-0.91);
        glVertex2f(0.63,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.12,-0.89);
        glVertex2f(-0.12,-0.89);
        glVertex2f(-0.15,-0.91);
        glVertex2f(0.15,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1.0,-0.89);
        glVertex2f(-0.8,-0.89);
        glVertex2f(-0.83,-0.91);
        glVertex2f(-1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.6,-0.89);
        glVertex2f(-0.3,-0.89);
        glVertex2f(-0.33,-0.91);
        glVertex2f(-0.63,-0.91);
        glEnd();

//left to right
//car
glPushMatrix();
glTranslatef(position,0,0);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(+1.1,0,0);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.5,-0.76);
        glVertex2f(-0.645,-0.81);
        glVertex2f(-0.5,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.88,-0.74);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.876,-0.745);
        glVertex2f(-0.89,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();
//bus
glPushMatrix();
glTranslatef(position,0,0);
glTranslatef(0.4,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.35,-0.675);
        glVertex2f(-0.38,-0.675);
        glVertex2f(-0.38,-0.775);
        glVertex2f(-0.35,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.39,-0.685);
        glVertex2f(-0.89,-0.685);
        glVertex2f(-0.89,-0.765);
        glVertex2f(-0.39,-0.765);

glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.37,-0.84);
        glVertex2f(-0.37,-0.8);
        glVertex2f(-0.35,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.885,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.78);
        glVertex2f(-0.885,-0.78);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.75;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.43;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glPopMatrix();
//right to left
//car
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(0.5,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(1.8,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(1.0,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.72,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.69,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.725,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.7,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glPopMatrix();

//bus
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(1.0,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(-1.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();

glutTimerFunc(5000,demo_night,0);

	glFlush();
}
void demo_evening(int val){

    glutDisplayFunc(evening);

}
void night() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);




//Sky
glBegin(GL_QUADS);
        glColor3ub(21, 22, 55);
        glVertex2f(1.0,1.0);
        glVertex2f(-1.0,1.0);
        glVertex2f(-1.0,-0.6);
        glVertex2f(1.0,-0.6);
        glEnd();
//moon
glPushMatrix();
glTranslatef(moonposition-1,moonposition,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(254, 254, 241);
	   int is;
	   float xs=0.77;
	   float ys=0.75;
		glVertex2f(xs, ys);
		for(is = 0; is <= 100;is++) {
			glVertex2f(
		            xs + (0.2 * cos(is *  2.0f*PI/ 100)),
			    ys + (0.2 * sin(is * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();
//clouds1
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);
	   int ic1;
	   float xc1=0.75;
	   float yc1=0.7;
		glVertex2f(xc1, yc1);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc1 + (0.15 * cos(ic1 *  2.0f*PI/ 100)),
			    yc1 + (0.15 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);

	   float xc2=0.9;
	   float yc2=0.68;
		glVertex2f(xc2, yc2);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc2 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc2 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);
	   int ic2;
	   float xc3=0.45;
	   float yc3=0.4;
		glVertex2f(xc3, yc3);
		for(ic2 = 0; ic2 <= 100;ic2++) {
			glVertex2f(
		            xc3 + (0.15 * cos(ic2 *  2.0f*PI/ 100)),
			    yc3 + (0.15 * sin(ic2 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);

	   float xc4=0.6;
	   float yc4=0.38;
		glVertex2f(xc4, yc4);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc4 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc4 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();
//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);
	   int ic3;
	   float xc5=0.05;
	   float yc5=0.7;
		glVertex2f(xc5, yc5);
		for(ic3 = 0; ic3 <= 100;ic3++) {
			glVertex2f(
		            xc5 + (0.15 * cos(ic3 *  2.0f*PI/ 100)),
			    yc5 + (0.15 * sin(ic3 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);

	   float xc6=0.2;
	   float yc6=0.7;
		glVertex2f(xc5, yc5);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc6 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc6 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//Background 1
glBegin(GL_QUADS);//Left_Building1
        glColor3ub(45, 90, 143);
        glVertex2f(-0.9,0.6);
        glVertex2f(-1.0,0.7);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.9,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Left_Building2
        glColor3ub(45, 90, 143);
        glVertex2f(-0.7,0.78);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.88,0.78);
        glVertex2f(-0.88,-0.6);
        glVertex2f(-0.7,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.75,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Left_Building3
        glColor3ub(45, 90, 143);
        glVertex2f(-0.4,0.47);
        glVertex2f(-0.4,0.78);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.6,0.78);
        glVertex2f(-0.6,0.47);
        glVertex2f(-0.69,0.4);
        glVertex2f(-0.69,-0.6);
        glVertex2f(-0.3,-0.6);
        glVertex2f(-0.3,0.4);

        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.5,-0.6);
        glEnd();
//background 2
glBegin(GL_POLYGON);//Right_Building1
        glColor3ub(149, 187, 187);
        glVertex2f(-0.1,0.53);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.35,0.53);
        glVertex2f(-0.35,-0.6);
        glVertex2f(-0.1,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.23,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Right_Building2
        glColor3ub(149, 187, 187);
        glVertex2f(-0.39,0.41);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.65,0.41);
        glVertex2f(-0.65,-0.6);
        glVertex2f(-0.39,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.45,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Right_Building3
        glColor3ub(149, 187, 187);
        glVertex2f(-0.67,0.45);
        glVertex2f(-0.8,0.5);
        glVertex2f(-1.0,0.45);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.67,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.8,0.5);
        glVertex2f(-0.8,-0.6);
        glEnd();
//footpath
glBegin(GL_QUADS);
        glColor3ub(201, 201, 201);
        glVertex2f(1.0,-0.6);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-1.0,-0.8);
        glVertex2f(1.0,-0.8);
        glEnd();

//Building row 2
glTranslatef(-1.15,0.1,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(213, 182, 149);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();


glTranslatef(-0.53,0.1,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(239, 200, 31);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(170, 140, 9);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(-0.5,0.3,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(50, 154, 115);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(0.25,0.25,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(109, 135, 156);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(54, 67, 78);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

//trees
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);
        int it;
	   float xt=0.78;
	   float yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt1=0.8;
	   float yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt2=0.82;
	   float yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();

glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//front buildings
glBegin(GL_POLYGON);//Left Building1
        glColor3ub(184, 46, 46);
        glVertex2f(-0.6,-0.1);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.85,-0.13);
        glVertex2f(-0.85,-0.67);
        glVertex2f(-0.8,-0.7);
        glVertex2f(-0.6,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.8,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.0f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.62,-0.6);
        glVertex2f(-0.78,-0.6);
        glVertex2f(-0.78,-0.7);
        glVertex2f(-0.62,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building2
        glColor3ub(198, 123, 123);
        glVertex2f(-0.3,-0.25);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.6,-0.27);
        glVertex2f(-0.6,-0.67);
        glVertex2f(-0.55,-0.7);
        glVertex2f(-0.3,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.55,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(0.11f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.33,-0.58);
        glVertex2f(-0.52,-0.58);
        glVertex2f(-0.52,-0.7);
        glVertex2f(-0.33,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building3
        glColor3ub(88, 25, 27);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(31, 5, 6);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.02,-0.6);
        glVertex2f(-0.05,-0.6);
        glVertex2f(-0.05,-0.7);
        glVertex2f(0.02,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building4
        glColor3ub(237, 187, 188);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();

glLoadIdentity();

glLoadIdentity();

glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.35,-0.6);
        glVertex2f(0.25,-0.6);
        glVertex2f(0.25,-0.7);
        glVertex2f(0.35,-0.7);
        glEnd();
glTranslatef(-1.73,-0.08,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
//Street Lights
glLineWidth(4);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();

glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.675,-0.525);
        glVertex2f(-0.775,-0.75);
        glVertex2f(-0.575,-0.75);
        glEnd();

glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.675,-0.525);
        glVertex2f(-0.775,-0.75);
        glVertex2f(-0.575,-0.75);
        glEnd();
glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.675,-0.525);
        glVertex2f(-0.775,-0.75);
        glVertex2f(-0.575,-0.75);
        glEnd();
        glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.675,-0.525);
        glVertex2f(-0.775,-0.75);
        glVertex2f(-0.575,-0.75);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//road
glBegin(GL_QUADS);
        glColor3ub(74, 74, 74);
        glVertex2f(1.0,-0.8);
        glVertex2f(-1.0,-0.8);
        glVertex2f(-1.0,-1.0);
        glVertex2f(1.0,-1.0);
        glEnd();
//Road Stripes
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(1.0,-0.89);
        glVertex2f(0.8,-0.89);
        glVertex2f(0.83,-0.91);
        glVertex2f(1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.6,-0.89);
        glVertex2f(0.3,-0.89);
        glVertex2f(0.33,-0.91);
        glVertex2f(0.63,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.12,-0.89);
        glVertex2f(-0.12,-0.89);
        glVertex2f(-0.15,-0.91);
        glVertex2f(0.15,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1.0,-0.89);
        glVertex2f(-0.8,-0.89);
        glVertex2f(-0.83,-0.91);
        glVertex2f(-1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.6,-0.89);
        glVertex2f(-0.3,-0.89);
        glVertex2f(-0.33,-0.91);
        glVertex2f(-0.63,-0.91);
        glEnd();

//left to right
//car
glPushMatrix();
glTranslatef(position,0,0);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
        glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.5,-0.76);
        glVertex2f(-0.645,-0.81);
        glVertex2f(-0.5,-0.91);
        glEnd();

glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(+1.1,0,0);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.5,-0.76);
        glVertex2f(-0.645,-0.81);
        glVertex2f(-0.5,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.88,-0.74);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.876,-0.745);
        glVertex2f(-0.89,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.5,-0.76);
        glVertex2f(-0.645,-0.81);
        glVertex2f(-0.5,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();
//bus
glPushMatrix();
glTranslatef(position,0,0);
glTranslatef(0.4,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.35,-0.675);
        glVertex2f(-0.38,-0.675);
        glVertex2f(-0.38,-0.775);
        glVertex2f(-0.35,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.39,-0.685);
        glVertex2f(-0.89,-0.685);
        glVertex2f(-0.89,-0.765);
        glVertex2f(-0.39,-0.765);

glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.37,-0.84);
        glVertex2f(-0.37,-0.8);
        glVertex2f(-0.35,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.885,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.78);
        glVertex2f(-0.885,-0.78);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.15,-0.78);
        glVertex2f(-0.35,-0.82);
        glVertex2f(-0.15,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.75;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.43;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glPopMatrix();
//right to left
//car
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(0.5,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-1.05,-0.76);
        glVertex2f(-0.894,-0.81);
        glVertex2f(-1.05,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(1.8,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-1.05,-0.76);
        glVertex2f(-0.894,-0.81);
        glVertex2f(-1.05,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(1.0,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.72,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.69,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.725,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.7,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-1.05,-0.76);
        glVertex2f(-0.894,-0.81);
        glVertex2f(-1.05,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glPopMatrix();

//bus
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(1.0,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-1.05,-0.76);
        glVertex2f(-0.9,-0.81);
        glVertex2f(-1.05,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(-1.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-1.05,-0.76);
        glVertex2f(-0.9,-0.81);
        glVertex2f(-1.05,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();


glutTimerFunc(5000,demo_latenight,0);
	glFlush();
}

void demo_night(int val){

glutDisplayFunc(night);

}

void latenight() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);




//Sky
glBegin(GL_QUADS);
        glColor3ub(21, 22, 55);
        glVertex2f(1.0,1.0);
        glVertex2f(-1.0,1.0);
        glVertex2f(-1.0,-0.6);
        glVertex2f(1.0,-0.6);
        glEnd();
//moon
glPushMatrix();
glTranslatef(0,moonposition2+0.7,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(254, 254, 241);
	   int is;
	   float xs=0.77;
	   float ys=0.75;
		glVertex2f(xs, ys);
		for(is = 0; is <= 100;is++) {
			glVertex2f(
		            xs + (0.2 * cos(is *  2.0f*PI/ 100)),
			    ys + (0.2 * sin(is * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();
//clouds1
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);
	   int ic1;
	   float xc1=0.75;
	   float yc1=0.7;
		glVertex2f(xc1, yc1);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc1 + (0.15 * cos(ic1 *  2.0f*PI/ 100)),
			    yc1 + (0.15 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);

	   float xc2=0.9;
	   float yc2=0.68;
		glVertex2f(xc2, yc2);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc2 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc2 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);
	   int ic2;
	   float xc3=0.45;
	   float yc3=0.4;
		glVertex2f(xc3, yc3);
		for(ic2 = 0; ic2 <= 100;ic2++) {
			glVertex2f(
		            xc3 + (0.15 * cos(ic2 *  2.0f*PI/ 100)),
			    yc3 + (0.15 * sin(ic2 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);

	   float xc4=0.6;
	   float yc4=0.38;
		glVertex2f(xc4, yc4);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc4 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc4 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();
//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);
	   int ic3;
	   float xc5=0.05;
	   float yc5=0.7;
		glVertex2f(xc5, yc5);
		for(ic3 = 0; ic3 <= 100;ic3++) {
			glVertex2f(
		            xc5 + (0.15 * cos(ic3 *  2.0f*PI/ 100)),
			    yc5 + (0.15 * sin(ic3 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);

	   float xc6=0.2;
	   float yc6=0.7;
		glVertex2f(xc5, yc5);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc6 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc6 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//Background 1
glBegin(GL_QUADS);//Left_Building1
        glColor3ub(45, 90, 143);
        glVertex2f(-0.9,0.6);
        glVertex2f(-1.0,0.7);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.9,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Left_Building2
        glColor3ub(45, 90, 143);
        glVertex2f(-0.7,0.78);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.88,0.78);
        glVertex2f(-0.88,-0.6);
        glVertex2f(-0.7,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.75,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Left_Building3
        glColor3ub(45, 90, 143);
        glVertex2f(-0.4,0.47);
        glVertex2f(-0.4,0.78);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.6,0.78);
        glVertex2f(-0.6,0.47);
        glVertex2f(-0.69,0.4);
        glVertex2f(-0.69,-0.6);
        glVertex2f(-0.3,-0.6);
        glVertex2f(-0.3,0.4);

        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.5,-0.6);
        glEnd();
//background 2
glBegin(GL_POLYGON);//Right_Building1
        glColor3ub(149, 187, 187);
        glVertex2f(-0.1,0.53);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.35,0.53);
        glVertex2f(-0.35,-0.6);
        glVertex2f(-0.1,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.23,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Right_Building2
        glColor3ub(149, 187, 187);
        glVertex2f(-0.39,0.41);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.65,0.41);
        glVertex2f(-0.65,-0.6);
        glVertex2f(-0.39,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.45,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Right_Building3
        glColor3ub(149, 187, 187);
        glVertex2f(-0.67,0.45);
        glVertex2f(-0.8,0.5);
        glVertex2f(-1.0,0.45);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.67,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.8,0.5);
        glVertex2f(-0.8,-0.6);
        glEnd();
//footpath
glBegin(GL_QUADS);
        glColor3ub(201, 201, 201);
        glVertex2f(1.0,-0.6);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-1.0,-0.8);
        glVertex2f(1.0,-0.8);
        glEnd();

//Building row 2
glTranslatef(-1.15,0.1,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(213, 182, 149);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(0, 33, 92);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(0, 33, 92);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();


glTranslatef(-0.53,0.1,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(239, 200, 31);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(170, 140, 9);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(-0.5,0.3,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(50, 154, 115);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(0, 33, 92);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(0, 33, 92);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(0.25,0.25,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(109, 135, 156);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(54, 67, 78);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

//trees
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);
        int it;
	   float xt=0.78;
	   float yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt1=0.8;
	   float yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt2=0.82;
	   float yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();

glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//front buildings
glBegin(GL_POLYGON);//Left Building1
        glColor3ub(184, 46, 46);
        glVertex2f(-0.6,-0.1);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.85,-0.13);
        glVertex2f(-0.85,-0.67);
        glVertex2f(-0.8,-0.7);
        glVertex2f(-0.6,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.8,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(20, 33, 92);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.0f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.62,-0.6);
        glVertex2f(-0.78,-0.6);
        glVertex2f(-0.78,-0.7);
        glVertex2f(-0.62,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building2
        glColor3ub(198, 123, 123);
        glVertex2f(-0.3,-0.25);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.6,-0.27);
        glVertex2f(-0.6,-0.67);
        glVertex2f(-0.55,-0.7);
        glVertex2f(-0.3,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.55,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(0.11f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(-0.33,-0.58);
        glVertex2f(-0.52,-0.58);
        glVertex2f(-0.52,-0.7);
        glVertex2f(-0.33,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building3
        glColor3ub(88, 25, 27);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(31, 5, 6);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.02,-0.6);
        glVertex2f(-0.05,-0.6);
        glVertex2f(-0.05,-0.7);
        glVertex2f(0.02,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building4
        glColor3ub(237, 187, 188);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(254, 255, 148);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(0, 33, 92);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(0, 33, 92);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(0, 33, 92);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();

glLoadIdentity();

glLoadIdentity();

glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(0, 33, 92);
        glVertex2f(0.35,-0.6);
        glVertex2f(0.25,-0.6);
        glVertex2f(0.25,-0.7);
        glVertex2f(0.35,-0.7);
        glEnd();
glTranslatef(-1.73,-0.08,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
//Street Lights
glLineWidth(4);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.675,-0.525);
        glVertex2f(-0.775,-0.75);
        glVertex2f(-0.575,-0.75);
        glEnd();
glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.675,-0.525);
        glVertex2f(-0.775,-0.75);
        glVertex2f(-0.575,-0.75);
        glEnd();
glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.675,-0.525);
        glVertex2f(-0.775,-0.75);
        glVertex2f(-0.575,-0.75);
        glEnd();
glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.675,-0.525);
        glVertex2f(-0.775,-0.75);
        glVertex2f(-0.575,-0.75);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//road
glBegin(GL_QUADS);
        glColor3ub(74, 74, 74);
        glVertex2f(1.0,-0.8);
        glVertex2f(-1.0,-0.8);
        glVertex2f(-1.0,-1.0);
        glVertex2f(1.0,-1.0);
        glEnd();
//Road Stripes
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(1.0,-0.89);
        glVertex2f(0.8,-0.89);
        glVertex2f(0.83,-0.91);
        glVertex2f(1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.6,-0.89);
        glVertex2f(0.3,-0.89);
        glVertex2f(0.33,-0.91);
        glVertex2f(0.63,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.12,-0.89);
        glVertex2f(-0.12,-0.89);
        glVertex2f(-0.15,-0.91);
        glVertex2f(0.15,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1.0,-0.89);
        glVertex2f(-0.8,-0.89);
        glVertex2f(-0.83,-0.91);
        glVertex2f(-1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.6,-0.89);
        glVertex2f(-0.3,-0.89);
        glVertex2f(-0.33,-0.91);
        glVertex2f(-0.63,-0.91);
        glEnd();

//left to right
//car
glPushMatrix();
glTranslatef(position,0,0);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.5,-0.76);
        glVertex2f(-0.645,-0.81);
        glVertex2f(-0.5,-0.91);
        glEnd();

glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(+1.1,0,0);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.5,-0.76);
        glVertex2f(-0.645,-0.81);
        glVertex2f(-0.5,-0.91);
        glEnd();

glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.88,-0.74);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.876,-0.745);
        glVertex2f(-0.89,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.5,-0.76);
        glVertex2f(-0.645,-0.81);
        glVertex2f(-0.5,-0.91);
        glEnd();

glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();
//bus
glPushMatrix();
glTranslatef(position,0,0);
glTranslatef(0.4,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.35,-0.675);
        glVertex2f(-0.38,-0.675);
        glVertex2f(-0.38,-0.775);
        glVertex2f(-0.35,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.39,-0.685);
        glVertex2f(-0.89,-0.685);
        glVertex2f(-0.89,-0.765);
        glVertex2f(-0.39,-0.765);

glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.37,-0.84);
        glVertex2f(-0.37,-0.8);
        glVertex2f(-0.35,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.885,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.78);
        glVertex2f(-0.885,-0.78);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-0.15,-0.78);
        glVertex2f(-0.35,-0.82);
        glVertex2f(-0.15,-0.91);
        glEnd();

glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.75;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.43;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glPopMatrix();
//right to left
//car
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(0.5,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-1.05,-0.76);
        glVertex2f(-0.894,-0.81);
        glVertex2f(-1.05,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(1.8,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-1.05,-0.76);
        glVertex2f(-0.894,-0.81);
        glVertex2f(-1.05,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(1.0,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.72,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.69,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.725,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.7,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-1.05,-0.76);
        glVertex2f(-0.894,-0.81);
        glVertex2f(-1.05,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glPopMatrix();

//bus
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(1.0,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-1.05,-0.76);
        glVertex2f(-0.9,-0.81);
        glVertex2f(-1.05,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(-1.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glEnable(GL_BLEND);//Blending Function for opacity
glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
glBegin(GL_TRIANGLES);
        glColor4ub(236, 229, 95, 0.04);
        glVertex2f(-1.05,-0.76);
        glVertex2f(-0.9,-0.81);
        glVertex2f(-1.05,-0.91);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();


glutTimerFunc(5000,demo_back,0);

	glFlush();
}

void demo_latenight(int val){

glutDisplayFunc(latenight);

}

void rain() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);




//Sky
glBegin(GL_QUADS);
        glColor3ub(143, 143, 143);
        glVertex2f(1.0,1.0);
        glVertex2f(-1.0,1.0);
        glVertex2f(-1.0,-0.6);
        glVertex2f(1.0,-0.6);
        glEnd();

	//rain cloud
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);
	   int ic;
	   float xc=0.75;
	   float yc=0.7;
		glVertex2f(xc, yc);
		for(ic = 0; ic <= 100;ic++) {
			glVertex2f(
		            xc + (0.2 * cos(ic *  2.0f*PI/ 100)),
			    yc + (0.2 * sin(ic * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);

	   float x1c=0.9;
	   float y1c=0.68;
		glVertex2f(x1c, y1c);
		for(ic = 0; ic <= 100;ic++) {
			glVertex2f(
		            x1c + (0.15 * cos(ic *  2.0f*PI/ 100)),
			    y1c + (0.15 * sin(ic * 2.0f*PI / 100))
			);
		}
	glEnd();
//clouds1
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);
	   int ic1;
	   float xc1=0.75;
	   float yc1=0.7;
		glVertex2f(xc1, yc1);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc1 + (0.15 * cos(ic1 *  2.0f*PI/ 100)),
			    yc1 + (0.15 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);

	   float xc2=0.9;
	   float yc2=0.68;
		glVertex2f(xc2, yc2);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc2 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc2 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();

//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);
	   int ic2;
	   float xc3=0.45;
	   float yc3=0.4;
		glVertex2f(xc3, yc3);
		for(ic2 = 0; ic2 <= 100;ic2++) {
			glVertex2f(
		            xc3 + (0.15 * cos(ic2 *  2.0f*PI/ 100)),
			    yc3 + (0.15 * sin(ic2 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);

	   float xc4=0.6;
	   float yc4=0.38;
		glVertex2f(xc4, yc4);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc4 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc4 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();
//clouds2
glPushMatrix();
glTranslatef(position2,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);
	   int ic3;
	   float xc5=0.05;
	   float yc5=0.7;
		glVertex2f(xc5, yc5);
		for(ic3 = 0; ic3 <= 100;ic3++) {
			glVertex2f(
		            xc5 + (0.15 * cos(ic3 *  2.0f*PI/ 100)),
			    yc5 + (0.15 * sin(ic3 * 2.0f*PI / 100))
			);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 77, 77);

	   float xc6=0.2;
	   float yc6=0.7;
		glVertex2f(xc5, yc5);
		for(ic1 = 0; ic1 <= 100;ic1++) {
			glVertex2f(
		            xc6 + (0.1 * cos(ic1 *  2.0f*PI/ 100)),
			    yc6 + (0.1 * sin(ic1 * 2.0f*PI / 100))
			);
		}
	glEnd();
glPopMatrix();



//Background 1
glBegin(GL_QUADS);//Left_Building1
        glColor3ub(45, 90, 143);
        glVertex2f(-0.9,0.6);
        glVertex2f(-1.0,0.7);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.9,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Left_Building2
        glColor3ub(45, 90, 143);
        glVertex2f(-0.7,0.78);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.88,0.78);
        glVertex2f(-0.88,-0.6);
        glVertex2f(-0.7,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.75,0.85);
        glVertex2f(-0.75,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Left_Building3
        glColor3ub(45, 90, 143);
        glVertex2f(-0.4,0.47);
        glVertex2f(-0.4,0.78);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.6,0.78);
        glVertex2f(-0.6,0.47);
        glVertex2f(-0.69,0.4);
        glVertex2f(-0.69,-0.6);
        glVertex2f(-0.3,-0.6);
        glVertex2f(-0.3,0.4);

        glEnd();
glBegin(GL_LINES);
        glColor3ub(176, 176, 176);
        glVertex2f(-0.5,0.85);
        glVertex2f(-0.5,-0.6);
        glEnd();
//background 2
glBegin(GL_POLYGON);//Right_Building1
        glColor3ub(149, 187, 187);
        glVertex2f(-0.1,0.53);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.35,0.53);
        glVertex2f(-0.35,-0.6);
        glVertex2f(-0.1,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.23,0.58);
        glVertex2f(-0.23,-0.6);
        glEnd();

glBegin(GL_POLYGON);//Right_Building2
        glColor3ub(149, 187, 187);
        glVertex2f(-0.39,0.41);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.65,0.41);
        glVertex2f(-0.65,-0.6);
        glVertex2f(-0.39,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.45,0.46);
        glVertex2f(-0.45,-0.6);
        glEnd();
glBegin(GL_POLYGON);//Right_Building3
        glColor3ub(149, 187, 187);
        glVertex2f(-0.67,0.45);
        glVertex2f(-0.8,0.5);
        glVertex2f(-1.0,0.45);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-0.67,-0.6);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(145, 161, 161);
        glVertex2f(-0.8,0.5);
        glVertex2f(-0.8,-0.6);
        glEnd();
//footpath
glBegin(GL_QUADS);
        glColor3ub(201, 201, 201);
        glVertex2f(1.0,-0.6);
        glVertex2f(-1.0,-0.6);
        glVertex2f(-1.0,-0.8);
        glVertex2f(1.0,-0.8);
        glEnd();

//Building row 2
glTranslatef(-1.15,0.1,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(213, 182, 149);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();


glTranslatef(-0.53,0.1,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(239, 200, 31);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(170, 140, 9);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(-0.5,0.3,0);
glBegin(GL_POLYGON);//Left Building4
        glColor3ub(50, 154, 115);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(19, 124, 85);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glTranslatef(0.25,0.25,0.0);
glBegin(GL_POLYGON);//Left Building3
        glColor3ub(109, 135, 156);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(54, 67, 78);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

//trees
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);
        int it;
	   float xt=0.78;
	   float yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt1=0.8;
	   float yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	   float xt2=0.82;
	   float yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();

glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(-0.15,0,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//front buildings
glBegin(GL_POLYGON);//Left Building1
        glColor3ub(184, 46, 46);
        glVertex2f(-0.6,-0.1);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.85,-0.13);
        glVertex2f(-0.85,-0.67);
        glVertex2f(-0.8,-0.7);
        glVertex2f(-0.6,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(-0.8,-0.1);
        glVertex2f(-0.8,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.0f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(-0.1f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glTranslatef(0.1f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.15);
        glVertex2f(-0.68,-0.15);
        glVertex2f(-0.68,-0.25);
        glVertex2f(-0.62,-0.25);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.62,-0.6);
        glVertex2f(-0.78,-0.6);
        glVertex2f(-0.78,-0.7);
        glVertex2f(-0.62,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building2
        glColor3ub(198, 123, 123);
        glVertex2f(-0.3,-0.25);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.6,-0.27);
        glVertex2f(-0.6,-0.67);
        glVertex2f(-0.55,-0.7);
        glVertex2f(-0.3,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(-0.55,-0.25);
        glVertex2f(-0.55,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.29);
        glVertex2f(-0.42,-0.29);
        glVertex2f(-0.42,-0.39);
        glVertex2f(-0.32,-0.39);
        glEnd();
glTranslatef(0.11f, -0.15f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glTranslatef(-0.11f, 0.0f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.32,-0.27);
        glVertex2f(-0.42,-0.27);
        glVertex2f(-0.42,-0.37);
        glVertex2f(-0.32,-0.37);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(-0.33,-0.58);
        glVertex2f(-0.52,-0.58);
        glVertex2f(-0.52,-0.7);
        glVertex2f(-0.33,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building3
        glColor3ub(88, 25, 27);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.3,0.07);
        glVertex2f(-0.3,-0.67);
        glVertex2f(-0.25,-0.7);
        glVertex2f(0.1,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(31, 5, 6);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,-0.7);
        glEnd();

glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.08,0.08);
        glVertex2f(-0.23,0.08);
        glVertex2f(-0.23,-0.02);
        glVertex2f(0.08,-0.02);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.02,-0.6);
        glVertex2f(-0.05,-0.6);
        glVertex2f(-0.05,-0.7);
        glVertex2f(0.02,-0.7);
        glEnd();


glBegin(GL_POLYGON);//Left Building4
        glColor3ub(237, 187, 188);
        glVertex2f(0.4,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.07);
        glVertex2f(0.1,-0.67);
        glVertex2f(0.15,-0.7);
        glVertex2f(0.4,-0.7);
        glEnd();
glBegin(GL_LINES);
        glColor3ub(174, 76, 81);
        glVertex2f(0.15,0.1);
        glVertex2f(0.15,-0.7);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glTranslatef(0.0f, -0.13f, 0.0f);
glBegin(GL_QUADS);
       glColor3ub(154, 224, 222);
        glVertex2f(0.37,0.08);
        glVertex2f(0.18,0.08);
        glVertex2f(0.18,-0.02);
        glVertex2f(0.37,-0.02);
        glEnd();
glLoadIdentity();

glLoadIdentity();

glLoadIdentity();

glLoadIdentity();
glBegin(GL_QUADS);
        glColor3ub(154, 224, 222);
        glVertex2f(0.35,-0.6);
        glVertex2f(0.25,-0.6);
        glVertex2f(0.25,-0.7);
        glVertex2f(0.35,-0.7);
        glEnd();
glTranslatef(-1.73,-0.08,0);
glLineWidth(4);
glBegin(GL_LINES);
        glColor3ub(78, 19, 22);
        glVertex2f(0.8,-0.4);
        glVertex2f(0.8,-0.65);
        glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt=0.78;
	    yt=-0.5;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.05 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.05 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt1=0.8;
	    yt1=-0.45;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt1 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt1 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 181, 54);

	    xt2=0.82;
	    yt2=-0.5;
		glVertex2f(xt1, yt1);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt2 + (0.06 * cos(it *  2.0f*PI/ 100)),
			    yt2 + (0.06 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
//Street Lights
glLineWidth(4);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();

glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
        glTranslatef(+0.5f, 0.0f, 0.0f);
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.8,-0.75);
glVertex2f(-0.8,-0.5);
glEnd();
glBegin(GL_LINES);
glColor3ub(10,10,10);
glVertex2f(-0.805,-0.5);
glVertex2f(-0.65,-0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3ub(236, 229, 95);
        glVertex2f(-0.65,-0.5);
        glVertex2f(-0.70,-0.5);
        glVertex2f(-0.70,-0.53);
        glVertex2f(-0.65,-0.53);
        glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glLineWidth(1);
//road
glBegin(GL_QUADS);
        glColor3ub(158,158,158);
        glVertex2f(1.0,-0.8);
        glVertex2f(-1.0,-0.8);
        glVertex2f(-1.0,-1.0);
        glVertex2f(1.0,-1.0);
        glEnd();
//Road Stripes
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(1.0,-0.89);
        glVertex2f(0.8,-0.89);
        glVertex2f(0.83,-0.91);
        glVertex2f(1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.6,-0.89);
        glVertex2f(0.3,-0.89);
        glVertex2f(0.33,-0.91);
        glVertex2f(0.63,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.12,-0.89);
        glVertex2f(-0.12,-0.89);
        glVertex2f(-0.15,-0.91);
        glVertex2f(0.15,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1.0,-0.89);
        glVertex2f(-0.8,-0.89);
        glVertex2f(-0.83,-0.91);
        glVertex2f(-1.0,-0.91);
        glEnd();
glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.6,-0.89);
        glVertex2f(-0.3,-0.89);
        glVertex2f(-0.33,-0.91);
        glVertex2f(-0.63,-0.91);
        glEnd();

//left to right
//car
glPushMatrix();
glTranslatef(position,0,0);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(+1.1,0,0);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(163, 179, 5);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(0.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(4, 14, 139);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.88,-0.74);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.876,-0.745);
        glVertex2f(-0.89,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();
//bus
glPushMatrix();
glTranslatef(position,0,0);
glTranslatef(0.4,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.35,-0.675);
        glVertex2f(-0.38,-0.675);
        glVertex2f(-0.38,-0.775);
        glVertex2f(-0.35,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.39,-0.685);
        glVertex2f(-0.89,-0.685);
        glVertex2f(-0.89,-0.765);
        glVertex2f(-0.39,-0.765);

glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.37,-0.84);
        glVertex2f(-0.37,-0.8);
        glVertex2f(-0.35,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.885,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.78);
        glVertex2f(-0.885,-0.78);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.75;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.43;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glPopMatrix();
//right to left
//car
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(0.5,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(101, 32, 32);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(1.8,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.67,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.675,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.657,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glTranslatef(1.0,0,0);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.65,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.89,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(245, 239, 239);
        glVertex2f(-0.72,-0.74);
        glVertex2f(-0.8,-0.74);
        glVertex2f(-0.842,-0.79);
        glVertex2f(-0.69,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.725,-0.745);
        glVertex2f(-0.795,-0.745);
        glVertex2f(-0.83,-0.785);
        glVertex2f(-0.7,-0.785);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.65,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.65,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.87,-0.82);
        glVertex2f(-0.895,-0.82);
        glVertex2f(-0.893,-0.8);
        glVertex2f(-0.87,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.84;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.71;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.03 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.03 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glLoadIdentity();

glPopMatrix();

//bus
glPushMatrix();
glTranslatef(position2,0,0);
glTranslatef(1.0,-0.1,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();

glTranslatef(-1.5,0,0);
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.87,-0.675);
        glVertex2f(-0.9,-0.675);
        glVertex2f(-0.9,-0.775);
        glVertex2f(-0.87,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.78,-0.685);
        glVertex2f(-0.86,-0.685);
        glVertex2f(-0.86,-0.85);
        glVertex2f(-0.78,-0.85);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.365,-0.84);
        glVertex2f(-0.365,-0.78);
        glVertex2f(-0.35,-0.78);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.83;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.5;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);

	    xt=-0.41;
	    yt=-0.845;
		glVertex2f(xt, yt);
		for(it = 0; it<= 100;it++) {
			glVertex2f(
		            xt + (0.04 * cos(it *  2.0f*PI/ 100)),
			    yt + (0.04 * sin(it * 2.0f*PI / 100))
			);
		}
	glEnd();
glLoadIdentity();
glLoadIdentity();
glPopMatrix();

glPushMatrix();

glTranslatef(position3,position3,0);
GLfloat x= -1.05;
GLfloat y = 2.05;
glBegin(GL_LINES);
glColor3ub(158, 253, 255);
for(int i=0;i<=205;i++){

glVertex2f(x,y);
glVertex2f(x-.02,y-.04);

x += .02;
}
glEnd();


for(int j=0;j<=200;j++)
{
x = -1.05;
y= y-.05;
glBegin(GL_LINES);
for(int i=0;i<=205;i++){

glVertex2f(x,y);
glVertex2f(x-.02,y-.04);
x += .02;
}
glEnd();
}
glPopMatrix();


glutTimerFunc(5000,demo_evening,0);
	glFlush();
}

void demo_rain(int val){

glutDisplayFunc(rain);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("Urban Life"); // Create a window with the given title
	glutInitWindowSize(640, 640);   // Set the window's initial width & height
    glutTimerFunc(0,sound,0);
    glutTimerFunc(10000,sound2,0);
    glutTimerFunc(15000,sound,0);
	glutDisplayFunc(demo_morning); // Register display callback handler for window re-paint

	glutIdleFunc(Idle);
    glutTimerFunc(100, moonupdate, 0);
    glutTimerFunc(100, moonupdate2, 0);
    glutTimerFunc(100, sunupdate2, 0);
    glutTimerFunc(100, update, 0);
	glutTimerFunc(100, update1, 0);
	glutTimerFunc(100, update2, 0);
	glutTimerFunc(100, update3, 0);


	glutMainLoop();           // Enter the event-processing loop




	return 0;
}
