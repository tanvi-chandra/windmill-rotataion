#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<Gl/glut.h>
static GLfloat spin=360.0;
static GLfloat u=0.45;
static GLfloat v=0.45;
static GLfloat w=0.45;
static GLfloat b=0.45;
static GLfloat c=0.00;
static GLfloat d=0.00;
static GLfloat e=0.00;
static GLfloat a=-40;
static int z=0;
GLfloat x=0;
GLfloat y=0;
int m,n;
const double PI = 3.141592654;
void init(void)
{
glClearColor(1.0,1.0,1.0,1.0);
glShadeModel(GL_FLAT);
}

void background()
{
glColor3f(0.0,0.1,0.0);
glBegin(GL_POLYGON);
glVertex2i(-250.0,-250.0);
glVertex2i(250.0,-250.0);
glVertex2i(250.0,0.0);
glVertex2i(-250.0,0.0);
glEnd();
glColor3f(0.0 ,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2i(-250.0,0.0);
glVertex2i(-250.0,250.0);
glVertex2i(250.0,250.0);
glVertex2i(250.0,0.0);
glEnd();
}
void fan1()
{
glPushMatrix();
glLoadIdentity();
glColor3f(1,1,1);
glTranslatef (-8.0,20.0, 2.0);
glRotatef(spin,0.0,0.0,1.0);
glTranslatef (8.0,-20.0, -2.0);
glBegin(GL_TRIANGLES);
glVertex3f(-8.0,20.0,2.0);
glVertex3f(-12.0,16.0,3.0);
glVertex3f(-12.0,18.0,4.0);
glVertex3f(-8.0,20.0,2.0);
glVertex3f(-4.0,24.0,3.0);
glVertex3f(-4.0,22.0,4.0);
glEnd();
glPopMatrix();
}
void fan2()
{
glPushMatrix();
glLoadIdentity();
glTranslatef (-20.0, 20.0, 2.0);
glRotatef(spin,0.0,0.0,1.0);
glTranslatef (20.0, -20.0,-2.0);
glColor3f(1,1,1);
glBegin(GL_TRIANGLES);
glVertex3f(-20.0,20.0,2.0);
glVertex3f(-25.0,17.0,3.0);
glVertex3f(-25.0,19.0,4.0);
glVertex3f(-20.0,20.0,2.0);
glVertex3f(-15.0,23.0,3.0);
glVertex3f(-15.0,21.0,4.0);
glEnd();
glPopMatrix();
}
void fan3()
{
glPushMatrix();
glLoadIdentity();
glTranslatef (-32.0, 20.0, 2.0);
glRotatef(spin,0.0,0.0,1.0);
glTranslatef (32.0, -20.0, -2.0);
glColor3f(1,1,1);
glBegin(GL_TRIANGLES);
glVertex3f(-32.0,20.0,2.0);
glVertex3f(-36.0,16.0,3.0);
glVertex3f(-36.0,18.0,4.0);
glVertex3f(-32.0,20.0,2.0);
glVertex3f(-28.0,24.0,3.0);
glVertex3f(-28.0,22.0,4.0);
glEnd();
glPopMatrix();
}

void powerhouse()
{
glColor3f(1.0,0.25,0.1);
glBegin(GL_POLYGON);
glVertex2i(1.5,8);
glVertex2i(-0.5,6);
glVertex2i(-0.5,0);
glVertex2i(3.5,0);
glVertex2i(3.5,6);
glEnd();
glColor3f(0.7,0.5,0.3);
glBegin(GL_POLYGON);
glVertex2i(1.5,11);
glVertex2i(-1.5,5);
glVertex2i(4.5,5);
glEnd();
glColor3f(v,v,w);
glBegin(GL_POLYGON);
glVertex2i(0.5,3);
glVertex2i(0.5,0);
glVertex2i(2.5,0);
glVertex2i(2.5,3);
glEnd();
}
void clouds()
{
glPushMatrix();
glColor3f (1.0, 1.0,1.0);
glLoadIdentity ();
glTranslatef(a+1, 40.0, -9.0);
glScalef (2.0, 1.0, 1.0);
glutSolidSphere (2.0,50,56);
glLoadIdentity();
glTranslatef(a-2.0,40.0, -9.0);
glScalef (2.0, 1.0, 1.0);
glutSolidSphere (2.0,50,56);
glLoadIdentity();
glTranslatef(a+7.0,40.0, -9.0);
glScalef (2, 1.0, 1.0);
glutSolidSphere (2.0,50,56);
glLoadIdentity();
glTranslatef(a-7.0,40.0, -9.0);
glScalef (2, 1.0, 1.0);
glutSolidSphere (2.0,50,56);
glLoadIdentity();
glTranslatef(a+18.0,40.0, -9.0);
glScalef (2, 1.0, 1.0);
glutSolidSphere (2.0,50,56);
glLoadIdentity();
glTranslatef(a+25.0,40.0, -9.0);
glScalef (2, 1.0, 1.0);
glutSolidSphere (2.0,50,56);
glLoadIdentity();
glTranslatef(a+36.0,40.0, -9.0);
glScalef (3.0, 1.0, 1.0);
glutSolidSphere (2.0,50,56);
glLoadIdentity();
glTranslatef(a+50.0,40.0, -9.0);
glScalef (2, 1.0, 1.0);
glutSolidSphere (2.0,50,56);
glLoadIdentity();
glTranslatef(a+56.0,40.0, -9.0);
glScalef (2, 1.0, 1.0);
glutSolidSphere (2.0,50,56);
glPopMatrix();
}
void roof(GLint rux,GLint ruy,GLint rdx,GLint rdy)
{
glPushMatrix();
glColor3f(1,0.25,0.1);
glBegin(GL_LINE_STRIP);
glVertex2i(rux,ruy);
glVertex2i(rdx,rdy);
glEnd();
glPopMatrix();
}
void hut(GLint rux,GLint ruy,GLint rdx,GLint rdy)
{
GLint blx=rdx,bly=rdy-9,brx=rdx+10,bry=rdy-9,kx=rdx-8,ky=rdy+1;
GLfloat i;
for(i=0;i<440;i=i+1)
roof(rux+i/40,ruy,rdx+i/40,rdy);
glColor3f(0.3,0.25,0.1);
glBegin(GL_POLYGON);
glVertex2i(rdx,rdy);
glVertex2i(rdx+10,rdy);
glVertex2i(brx,bry);
glVertex2i(blx,bly);
glEnd();
glColor3f(0.3,0.15,0.1);
glBegin(GL_POLYGON);
glVertex2i(rux,ruy);
glVertex2i(kx,ky);
glVertex2i(kx,ky-6);
glVertex2i(blx,bly);
glVertex2i(rdx,rdy);
glEnd();
glColor3f(v,v,w);
glBegin(GL_POLYGON);
glVertex2i(kx+2,ky-2.5);
glVertex2i(kx+2,ky-5.5);
glVertex2i(blx-3,bly+3.5);
glVertex2i(blx-3,bly+6.9);
glEnd();
glColor3f(v,v,w);
glBegin(GL_POLYGON);
glVertex2i(blx+3.5,bly+5);
glVertex2i(blx+3.5,bly);
glVertex2i(brx-3.5,bry);
glVertex2i(brx-3.5,bry+5);
glEnd();
}
void fanpole1()
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLE_STRIP);
glVertex2f(-8.1,20.0);
glVertex2f(-7.9,20.0);
glVertex2f(-8.5,0.0);
glVertex2f(-7.5,0.0);
glEnd();
}
void fanpole2()
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLE_STRIP);
glVertex2f(-20.1,20.0);
glVertex2f(-19.9,20.0);
glVertex2f(-20.5,0.0);
glVertex2f(-19.5,0.0);
glEnd();
}
void fanpole3()
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLE_STRIP);
glVertex2f(-32.1,20.0);
glVertex2f(-31.9,20.0);
glVertex2f(-32.5,0.0);
glVertex2f(-31.5,0.0);
glEnd();
}

void display()
{
int b=0;
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
background();
hut(-29,-23,-24,-33);
hut(0,-11,5,-21);
hut(-21,-1,-14,-11);
clouds();
powerhouse();
fanpole1();
fanpole2();
fanpole3();
fan1();
fan2();
fan3();
glutSwapBuffers();
glFlush();

}
void spinclockwise(void)
{
w=0.3;u=0;v=1;b=0.5;c=1;d=1;e=0;
a=a+0.04;
if(a>40)
a-=100.0;
spin=spin-2.0;
if(spin<0)
spin=spin+360.0;
glutPostRedisplay();
}
void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-35.0, 35.0, -45.0, 45.0, -20.0, 20.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void menu(int id )
{
switch(id)
{
case 1: glutIdleFunc(spinclockwise);
break;
case 2:glutIdleFunc(display);
break;
case 3: exit(0);
}
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("WINDMILL ROTATION");
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutCreateMenu(menu);
glutAddMenuEntry("..............ROTATE WINDMILL.............",1);
glutAddMenuEntry(".................STOP......................",2);
glutAddMenuEntry("............QUIT.........................",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
return 0;
}
