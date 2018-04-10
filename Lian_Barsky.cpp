#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

GLfloat Xmin=0,Xmax=10,Ymin=0,Ymax=10;
GLfloat X1,Y1,X2,Y2;
GLfloat xc1,xc2,yc1,yc2;
GLint choice=1;

void clip_line()
{
    float dx=X2-X1;
    float dy=Y2-Y1;

    float p[5],q[5],t1=0,t2=1,t[5];

    p[1]=-dx;
    p[2]=dx;
    p[3]=-dy;
    p[4]=dy;

    q[1]=X1-Xmin;
    q[2]=Xmax-X1;
    q[3]=Y1-Ymin;
    q[4]=Ymax-Y1;


    if(p[1]==0 || p[3]==0)
    {
        if(p[1]==0)
        {   xc1=X1;
            xc2=X2;
            if(Y1<Ymin)
                yc1=Ymin;
            else
                yc1=Y1;
            if(Y2>Ymax)
                yc2=Ymax;
            else
                yc2=Y2;
        }
        if(p[3]==0)
        {
            yc1=Y1;
            yc2=Y2;
            if(X1<Xmin)
                xc1=Xmin;
            else
                xc1=X1;
            if(X2>Xmax)
                xc2=Xmax;
            else
                xc2=X2;
        }
    }

    else if(q[1]<0 && q[2]<0 && q[3]<0 && q[4]<0)
    {
        xc1=0;
        xc2=0;
        yc1=0;
        yc2=0;
    }

    else
    {
        for(int i=1;i<5;i++)
        {
            t[i]=q[i]/p[i];
            if(p[i]<0)
                if(t[i]>t1)
                    t1=t[i];
            if(p[i]>0)
                if(t[i]<t2)
                    t2=t[i];
        }

        if(t1<t2)
        {
            xc1=X1+t1*dx;
            xc2=X1+t2*dx;

            yc1=Y1+t1*dy;
            yc2=Y1+t2*dy;
        }

    }
}

void lian_barsky()
{

    //printf("\nXmin:  %f\nXmax:  %f\nYmin:  %f\nYmax:  %f\n",Xmin,Xmax,Ymin,Ymax);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);

    glColor3f(0,0,1);

    glVertex3f(0,0,0);
    glVertex3f(10,0,0);
    glVertex3f(10,10,0);
    glVertex3f(0,10,0);

    glEnd();

    if(choice==1)
    {
        glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(X1,Y1,0);
        glVertex3f(X2,Y2,0);

        glEnd();
    }

    else
    {
        clip_line();
        glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(xc1,yc1,0);
        glVertex3f(xc2,yc2,0);

        glEnd();
    }

    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();

}

void Mykeyboardfunc(unsigned char key,int x,int y)
{
    if(key=='c')
     {
         if(choice==1)
            choice=2;
        else
            choice=1;
     }
    glutPostRedisplay();
}
void init()
{

    glClearColor(0.9,1,0.1,0);    //white
    gluOrtho2D(-20,20,-20,20);

}

void reshape(int w, int h)
{
 glViewport(0.0, 0.0, w, h);
}

int main(int argc, char **argv)
{
    X1=-5;
    Y1=3;
    X2=15;
    Y2=9;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lian_Barsky");
    init();
    glutKeyboardFunc(Mykeyboardfunc);
    glutDisplayFunc(lian_barsky);
    glutIdleFunc(lian_barsky);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
