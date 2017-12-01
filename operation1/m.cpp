#include <GLUT/glut.h>
#include <cstdio>

#define FOR(i, r) for((i) = 0; (i) < (r); (i)++)
#define draw(type, obj, num) do{\
    glBegin(type);\
	int i;\
    	FOR(i, num) glVertex2fv(obj[i]);\
    glEnd();\
}while(0)

typedef GLfloat vertex2 [2];

const float TIMES = 50.0f;
const GLfloat width = 300, height = 300;

vertex2 poly_face_1[7] = { 
    {1.52, 1.61}, {2, 1.3}, {2.09, 0.47}, 
    {1.54, 0.06}, {0.55, 0.27}, {0.45, 0.84}, {0.64, 1.21}
};
vertex2 poly_face_2[4] = {
    {2, 1.3}, {2.62, 0.86}, {2.43, 0.45}, {2.09, 0.49}
};
vertex2 poly_face_3[10] = {
    {0.45, 0.84}, {0.55, 0.27}, {1.12, -0.54}, {2, -1},
    {2.68, -0.91}, {2.39, -1.38}, {1.13, -.195}, {0.47, -0.7},
    {0.26, -0.16}, {0.22, 0.44}
};
vertex2 poly_face_4[4] = {
    {2.93, -1.38}, {2.28, -1.87}, {2, -2}, {1.13, -1.95}
};


void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.82, 0.63, 0.55);
    draw(GL_POLYGON, poly_face_1, 7);
    draw(GL_POLYGON, poly_face_2, 4);
    glColor3f(0.82, 0.56, 0.4);
    draw(GL_POLYGON, poly_face_3, 10);
    draw(GL_POLYGON, poly_face_4, 10);

    glFlush();
}

void reshape(GLsizei w, GLsizei h){
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(w <= h){
        glOrtho(-13.89, 13.89, -10 * h / w, 10 * h / w, 1.0f, -1.0f);
    }else{
        glOrtho(-13.89 * w / h, 13.89 * w / h, -10, 10, 1.0f, -1.0f);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init(){
    glClearColor(1, 1, 1, 0.0);

    glMatrixMode(GL_PROJECTION);
    glOrtho(-13.89, 13.89, -10, 10, 1, -1);

    glViewport(0, 0, width, height);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Experiment 1");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    //glutDisplayFunc(renderScene);

    glutMainLoop();

    return 0;
}
