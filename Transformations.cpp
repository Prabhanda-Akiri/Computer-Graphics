#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

float x1 = 0.4, y= 0.4, x2 = 0.6, y2 = 0.4,x3=0.4,y3=0.6, X1=0, Y1=1, X2=0, Y2=0,X3=0,Y3=1;
float pi = 3.14;

void p_rotate(float x,float y,float angle,int i)
{
    float X=x*cos(angle)-y*sin(angle);
    float Y=x*sin(angle)+y*cos(angle);
    switch(i)
    {
        case 1:X1=X;Y1=Y;
                break;
        case 2:X2=X;Y2=Y;
                break;
        case 3:X3=X;Y3=Y;
                break;
        /*case 4:x4=X;y4=Y;
                break;  */
    }
    printf("\nAfter Rotation of vertex %d:\n",i);
    cout<<X1<<" "<<Y1<<endl;
    cout<<X2<<" "<<Y2<<endl;
    cout<<X3<<" "<<Y3<<endl;
    //cout<<X4<<" "<<Y4<<endl;
}
void translate(float x,float y,float tx,float ty,int i)
{
    float X=x+tx;
    float Y=y+ty;
    printf("%f %f",X,Y);
    switch(i)
    {
        case 1:X1=X;Y1=Y;
                break;
        case 2:X2=X;Y2=Y;
                break;
        case 3:X3=X;Y3=Y;
                break;
        /*case 4:x4=X;y4=Y;
                break;  */
    }
    printf("\nAfter Translation of vertex %d:\n",i);
    cout<<X1<<" "<<Y1<<endl;
    cout<<X2<<" "<<Y2<<endl;
    cout<<X3<<" "<<Y3<<endl;
    //cout<<X4<<" "<<Y4<<endl;
}
void scale(float x,float y,float sx,float sy,int i)
{
    float X=x*sx;
    float Y=y*sy;
    switch(i)
    {
        case 1:X1=X;Y1=Y;
                break;
        case 2:X2=X;Y2=Y;
                break;
        case 3:X3=X;Y3=Y;
                break;
        /*case 4:x4=X;y4=Y;
                break;  */
    }
    printf("\nAfter Scaling of vertex %d:\n",i);
    cout<<X1<<" "<<Y1<<endl;
    cout<<X2<<" "<<Y2<<endl;
    cout<<X3<<" "<<Y3<<endl;
    //cout<<X4<<" "<<Y4<<endl;
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f(X1, Y1, 0.0f);
glVertex3f(X2, Y2, 0.0f);
glVertex3f(X3, Y3, 0.0f);
//glVertex3f(0.0, 0.0, 0.0);
glEnd();
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f(x1, y, 0.0f);
glVertex3f(x2, y2, 0.0f);
glVertex3f(x3, y3, 0.0f);
//glVertex3f(0.0, 0.0, 0.0);
glEnd();
glutSwapBuffers();
}
void intiopenGL()
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glColor3f(1.0,0.0,0.0);
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(640, 500);
glutInitWindowPosition(100,100);
glutCreateWindow("Transformation");

translate( x1,y,-0.4,-0.4,1);
translate( x2,y2,0,-0.4,2);
translate( x3,y3,-0.4,0,3);
/*
translate( x1,y,0,0,1);
translate( x2,y2,0,0,2);
translate( x3,y3,0,0,3);
*/

scale(X1,Y1,1.5,1.5,1);
scale(X2,Y2,1.5,1.5,2);
scale(X3,Y3,1.5,1.5,3);
/*
scale(X1,Y1,1,1,1);
scale(X2,Y2,1,1,2);
scale(X3,Y3,1,1,3);
*/
p_rotate( X1,Y1,90 * pi/180,1);
p_rotate( X2,Y2,90 * pi/180,2);
p_rotate( X3,Y3,90 * pi/180,3);
/*
p_rotate( X1,Y1,0 * pi/180,1);
p_rotate( X2,Y2,0 * pi/180,2);
p_rotate( X3,Y3,0 * pi/180,3);
*/
intiopenGL();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
