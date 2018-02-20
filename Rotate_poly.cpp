#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

void display()
{
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1,1,1);
glBegin(GL_POLYGON);

glColor3f(0,0,1);

glVertex3f(-1,1,0);
glColor3f(1,0,0);
glVertex3f(0,1,0);
glVertex3f(1,0,0);
glColor3f(0,1,0);
glVertex3f(0,-1,0);
glColor3f(0,0,1);
glVertex3f(-1,-1,0);

glEnd();

//glRotatef(-5,0,1,0);
glutSwapBuffers();
}

void reshape(int w, int h)
{
 glViewport(0.0, 0.0, w, h);
}
void intiopenGL()
{
 glClearColor(0, 0.0, 0.0, 1.0);
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("OpenGL Test");
 intiopenGL();
 glutDisplayFunc(display);
 glutIdleFunc(display);
 glutReshapeFunc(reshape);
 glutMainLoop();
 return 0;
}
