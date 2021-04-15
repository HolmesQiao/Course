#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

GLint points[8][3] = {{0, 0, 0}, {0, 1, 0}, {1, 0, 0}, {1, 1, 0},
    		      {0, 0, 1}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1}};

void init();
void quad(GLint n1, GLint n2, GLint n3, GLint n4);
void draw();

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(400, 400);
    glutCreateWindow("3d graphics test");

    init();
    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}

void init(){
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 400);
}

void quad(GLint n1, GLint n2, GLint n3, GLint n4){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    	glVertex3iv(points[n1]);
	glVertex3iv(points[n2]);
	glVertex3iv(points[n3]);
	glVertex3iv(points[n4]);
    glEnd();
}

void draw(){
    quad(6, 2, 3, 7);
    quad(5, 1, 0, 4);
    quad(7, 3, 1, 5);
    quad(4, 0, 2, 6);
    quad(2, 0, 1, 3);
    quad(7, 5, 4, 6);
}
