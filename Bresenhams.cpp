#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

double X1,Y1,X2,Y2;

void lineF()
{

    double dx=(X2-X1);
    double dy = (Y2-Y1);

    float x=X1,y=Y1;
    float d,de,dne;
    d=2*dy-dx;
    de=2*dy;
    dne=2*(dy-dx);

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);
    glVertex2d(x,y);

    while(x<X2)
    {
        if(d<=0)
            d=d+de;
        else
        {
           d=d+dne;
           y=y+1;

        }
        x=x+1;
        glVertex3d(x,y,0);

    }

    glEnd();

    glutSwapBuffers();

}
void init()
{

    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,1.0,1.0);
    gluOrtho2D(-640,640,0,480);

}

void reshape(int w, int h)
{
 glViewport(0.0, 0.0, w, h);
}

int main(int argc, char **argv)
{

    X1 = 100;
    Y1 = 100;
    X2 = 500;
    Y2 = 500;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
 glutInitWindowPosition(0, 0);
     glutCreateWindow("mid point line drawing");
    init();
    glutDisplayFunc(lineF);
    glutIdleFunc(lineF);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
