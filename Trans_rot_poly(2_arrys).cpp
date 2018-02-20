#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

GLfloat vertices1[]={-0.5,0.5,0,
                    0.5,0.5,0,
                    0.5,-0.5,0};
 GLfloat vertices2[]={0.5,-0.5,0,
                    -0.5,-0.5,0,
                    -0.5,0.5,0};
                    
GLfloat colours1[]={1,0,0,
                    0,1,0,
                    1,0,0,};
GLfloat colours2[]={1,0,0,
                    0,0,1,
                    1,0,0};

void display()
{
glClear(GL_COLOR_BUFFER_BIT);

glEnableClientState(GL_VERTEX_ARRAY);
glEnableClientState(GL_COLOR_ARRAY);
glColor3f(0,0,0);
glMatrixMode(GL_POLYGON);
glLoadIdentity();
glTranslatef(0,-0.25,0);
glRotatef(40,0,0,1);

glVertexPointer(3,GL_FLOAT,0,vertices1);
glColorPointer(3,GL_FLOAT,0,colours1);
glColor3f(0,0,1);
glDrawArrays(GL_POLYGON,0,3);

glDisableClientState(GL_COLOR_ARRAY);
glDisableClientState(GL_VERTEX_ARRAY);
glEnableClientState(GL_VERTEX_ARRAY);
glEnableClientState(GL_COLOR_ARRAY);
glColor3f(0,0,0);
glMatrixMode(GL_POLYGON);
glLoadIdentity();
glTranslatef(0,-0.25,0);
glRotatef(40,0,0,1);
glVertexPointer(3,GL_FLOAT,0,vertices2);
glColorPointer(3,GL_FLOAT,0,colours2);
glColor3f(0,0,1);
glDrawArrays(GL_POLYGON,0,3);

glDisableClientState(GL_COLOR_ARRAY);
glDisableClientState(GL_VERTEX_ARRAY);

glEnd();

glutSwapBuffers();
//glRotatef(-5,0,1,0);

}

void reshape(int w, int h)
{
 glViewport(0.0, 0.0, w, h);
}
void intiopenGL()
{
 glClearColor(0, 0.0, 0.0, 1.0);
    //gluOrtho2D(0,640,0,480);
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
