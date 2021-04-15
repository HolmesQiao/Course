#include <iostream>
#include <GLUT/glut.h>

using namespace std;
//glScaled(x, y, z); //在xyz方向上放大xyz倍

typedef GLfloat vertex3[3];

const GLint width = 300, high = 300;
GLfloat r = 90;


void init(void){
    glClearColor(1, 1, 1, 0.0);
    
    glMatrixMode(GL_PROJECTION);
    //glMatrixMode(GL_MODELVIEW);
    glOrtho(-1, 1, -1, 1, 1, -1);
    glViewport(0, 0, width, high);
}
void display_2d(void){
    glLoadIdentity(); //重置观察矩阵
    //glTranslatef(-1.5, 0.0, 0);
    glRotatef(r, 0, 0, 1);
    
    r += 10;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    	glColor3f(1, 0, 0);
		glVertex2f(0, 1);
	glColor3f(0, 1, 0);
		glVertex2f(-1, -1);
	glColor3f(0, 0, 1);
		glVertex2f(1, -1);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void display_3d(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //glRotatef(45, 0, 1 ,0);
    //glTranslatef(0, 0, -3);
    glBegin(GL_TRIANGLES);
    	glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
	glColor3f(0, 1, 0);
		glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);

    	glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
	glColor3f(0, 1, 0);
		glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);

    	glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
	glColor3f(0, 1, 0);
		glVertex3f(1, -1, -1);
	glColor3f(0, 0, 1);
		glVertex3f(-1, -1, -1);

    	glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
	glColor3f(0, 1, 0);
		glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
		glVertex3f(-1, -1, 1);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, high);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Experiment 2");

    init();
    glutDisplayFunc(display_3d);
    
    glutMainLoop();

    return 0;
}
