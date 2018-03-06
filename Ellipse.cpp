#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

double a,b;

void EllipseF()
{

double d2;
int X = 0;
int Y = b;
int sa = a*a;
int sb = b*b;
double d1 = sb-(sa*b) + (0.5*sa) ;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);

glVertex2d(X,Y);
glVertex2d(X,-Y);
glVertex2d(-X,-Y);
glVertex2d(-X,Y);

while ( sa*(Y - 0.5) > sb*(X + 1))
/*Region R1 */
{
    if (d1 < 0)
    d1 += sb*3+sb*2*X;

    else /*Select SE */
    { d1 += sb*3+sb*2*X + 2*sa -2*sa*Y;
      Y-- ;
    }
    X++ ;
    glVertex2d(X,Y);
    glVertex2d(X,-Y);
    glVertex2d(-X,-Y);
    glVertex2d(-X,Y);

}

    d2 = sb*(X + 0.5)*(X + 0.5) +sa*(Y - 1)*(Y - 1) - sa*sb;

    while ( Y > 0) /*Region R2 */
    {
        if (d2 < 0) /*Select SE */
        {
            d2 += sb*((2*X) + 2) +sa*(-(2*Y) + 3);
            X++;
        }

        else /*Select S */
            d2 += sa*(-(2*Y) + 3);

        Y-- ;
        glVertex2d(X,Y);
        glVertex2d(X,-Y);
        glVertex2d(-X,-Y);
        glVertex2d(-X,Y);

    }

    glEnd();
    glutSwapBuffers();
}

void init()
{

    glClearColor(0.0,1.0,1.0,0);
    glColor3f(0.0,1.0,0.0);
    gluOrtho2D(-400,400,-400,400);

}

void reshape(int w, int h)
{
 glViewport(0.0, 0.0, w, h);
}

int main(int argc, char **argv)
{

    a=200;
    b=100;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
     glutCreateWindow("Ellipse drawing");
    init();
    glutDisplayFunc(EllipseF);
    glutIdleFunc(EllipseF);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
