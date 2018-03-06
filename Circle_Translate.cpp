#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

double R;
int mx,my;

void CircleF()
{

    double x=0;
    mx=60;
    my=50;
    double y=R,h=1-R;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_POINTS);

    glVertex2d(x+mx,y+my);
    glVertex2d(y+mx,x+my);
    glVertex2d(y+mx,-x+my);
    glVertex2d(x+mx,-y+my);
    glVertex2d(-x+mx,-y+my);
    glVertex2d(-y+mx,-x+my);
    glVertex2d(-y+mx,x+my);
    glVertex2d(-x+mx,y+my);


    while(y>x)
    {
        if(h<0)
        h=h+2*x+3;
        else
        {
            h=h+2*(x-y)+5;
            y=y-1;

        }
        x=x+1;

   glVertex2d(x+mx,y+my);
    glVertex2d(y+mx,x+my);
    glVertex2d(y+mx,-x+my);
    glVertex2d(x+mx,-y+my);
    glVertex2d(-x+mx,-y+my);
    glVertex2d(-y+mx,-x+my);
    glVertex2d(-y+mx,x+my);
    glVertex2d(-x+mx,y+my);
    }

    glEnd();
    glutSwapBuffers();

}
void init()
{

    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,1.0,0.0);
    gluOrtho2D(-200,200,-200,200);

}

void reshape(int w, int h)
{
 glViewport(0.0, 0.0, w, h);
}

int main(int argc, char **argv)
{

    R = 100;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
     glutCreateWindow("Circle drawing");
    init();
    glutDisplayFunc(CircleF);
    glutIdleFunc(CircleF);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
