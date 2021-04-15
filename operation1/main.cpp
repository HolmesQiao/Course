#include <GLUT/glut.h>
#include <cstdio>

#define FOR(i, r) for((i) = 0; (i) < (r); (i)++)
#define draw(type, obj, num) do{\
    glBegin(type);\
	int i;\
    	FOR(i, num) glVertex2fv(obj[i]);\
    glEnd();\
}while(0)
float scaled_time = 1.4;
GLfloat angle = 0;

typedef GLfloat vertex2 [2];

const float TIMES = 50.0f;
const GLfloat width = 200, height = 200;

vertex2 poly_face_1[7] = {
    {1.28, -0.91}, {2.29, -1.13}, {2.91, -0.7}, {2.77, 0.11},
    {2.31, 0.43}, {1.39, 0.04}, {1.17, -0.31}
};
vertex2 poly_face_2[5] = {
    {2.91, -0.7}, {3.16, -0.73}, {3.4, -0.33},
    {3.19, -0.05}, {2.77, 0.11}
};
vertex2 poly_face_3[5] = {
    {1.17, -0.31}, {1, -0.81}, {0.98, -1.37},
    {1.95, -3.16}, {1.28, -0.92}
};
vertex2 poly_face_4[3] = {
    {1.28, -0.91}, {1.95, -3.16}, {1.83, -1.71}
};
vertex2 poly_face_5[3] = {
    {1.83, -1.71}, {1.95, -3.16}, {2.65, -2.12}
};
vertex2 poly_face_6[4] = {
    {2.65, -2.12}, {1.95, -3.16}, {3.15, -2.61}, {3.46, -2.13}
};
vertex2 poly_face_7[3] = {
    {1.95, -3.16}, {2.92, -3.18}, {3.15, -2.61}
};
vertex2 poly_face_8[6] = {
    {1.28, -0.91}, {1.83, -1.71}, {2.65, -2.12}, {3.46, -2.13}, {2.96, -1.52}, {2.29, -1.13}
};
vertex2 poly_face_9[3] = {
    {2.29, -1.13}, {2.96, -1.52}, {2.91, -0.7}
};
vertex2 poly_face_10[4] = {
    {2.91, -0.7}, {2.96, -1.52}, {3.66, -1.2}, {3.16, -0.73}
};
vertex2 poly_face_11[3] = {
    {2.96, -1.52}, {3.47, -1.73}, {3.66, -1.2}
};
vertex2 poly_face_12[3] = {
    {2.96, -1.52}, {3.46, -2.13}, {3.47, -1.73}
};
vertex2 jiao_1[4] = {
    {-2.17, 0.19}, {-1, -1}, {-0.46, -0.04}, {-1.51, 3.01}
};
vertex2 jiao_2[3] = {
    {-1, -1}, {3.24, -5.08}, {-0.46, -0.04}
};
vertex2 jiao_3[6] = {
    {-1.51, 3.01}, {-0.46, -0.04}, {3.24, -5.08}, 
    {1.95, -3.16}, {0.98, -1.37}, {0.33, 0.47}
};
vertex2 kui_1[4] = {
    {0, 2}, {0.33, 0.47}, {0.98, -1.37}, {0.72, 3.18}
};
vertex2 kui_2[5] = {
    {0, 2}, {0.33, 0.47}, {1.39, 0.04}, {2.31, 0.43}, {0.72, 3.18}
};
vertex2 kui_3[3] = {
    {2.31, 0.43}, {3.4, -0.33}, {2.92, 1.3}
};
vertex2 hair_1[3] = {
    {0, -2}, {-0.03, -4.82}, {0.82, -2.71}
};
vertex2 hair_2[3] = {
    {-1, -1}, {-1.02, -4.17}, {0, -2}
};

vertex2 line_jian[9] = {
    {-1, -1}, {-1.02, -4.17}, {-2.63, -5.98},  {-3.28, -7.96}, {1.61, -9.69},
    {4.7, -8.18}, {3.18, -6.73}, {1.43, -4.35}, {1.37, -3.56}
};

vertex2 point[8] = {
    {-1.29, -4.44}, {1.08, -5.96}, {2.72, 6.95}, {2.66, -5.53},
    {-1.29, -4.}, {1.08, -5.}, {2.72, 6.}, {2.66, -5}
};

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(-1.4, 4, 0);
    glRotatef(angle, 0, 1, 0);
    glScaled(scaled_time, scaled_time, 0);
    glColor3f(0.82, 0.63, 0.55);
    draw(GL_POLYGON, poly_face_1, 7);
    draw(GL_POLYGON, poly_face_2, 5);
    glColor3f(0.82, 0.56, 0.4);
    draw(GL_POLYGON, poly_face_3, 5);
    draw(GL_POLYGON, poly_face_4, 3);
    draw(GL_POLYGON, poly_face_4, 3);
    draw(GL_POLYGON, poly_face_5, 3);
    draw(GL_POLYGON, poly_face_6, 4);
    draw(GL_POLYGON, poly_face_7, 3);
    draw(GL_POLYGON, poly_face_11, 3);
    glColor3f(0.87, 0.847, 0.87);
    draw(GL_POLYGON, poly_face_8, 6);
    draw(GL_POLYGON, poly_face_9, 3);
    draw(GL_POLYGON, poly_face_10, 4);
    draw(GL_POLYGON, poly_face_12, 3);
    glColor3f(0.2, 0.125, 0.07);
    draw(GL_POLYGON, jiao_1, 4);
    draw(GL_POLYGON, jiao_2, 3);
    glColor3f(0.45, 0.4, 0.3);
    draw(GL_POLYGON, jiao_3, 6);
    glColor3f(0.675, 0.57, 0.52);
    draw(GL_POLYGON, kui_1, 4);
    draw(GL_POLYGON, kui_2, 5);
    draw(GL_POLYGON, kui_3, 3);
    glColor3f(1, 0, 0);
    draw(GL_LINE_LOOP, line_jian, 9);
    glColor3f(0.675, 0.34, 0.004);
    draw(GL_POLYGON, hair_1, 3);
    draw(GL_POLYGON, hair_2, 3);
    glColor3f(0, 0, 0);
    draw(GL_POINTS, point, 8);

    //angle++;
    glFlush();
    //glutPostRedisplay();
}

void reshape(GLsizei w, GLsizei h){
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glLoadIdentity();
    if(w <= h){
        glOrtho(-10, 10, -10 * h / w, 10 * h / w, 1.0f, -1.0f);
    }else{
        glOrtho(-10 * w / h, 10 * w / h, -10, 10, 1.0f, -1.0f);
    }

    glMatrixMode(GL_MODELVIEW);
}

void spin(void){ glutPostRedisplay(); }

void init(){
    glClearColor(1, 1, 1, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, 1, -1);
    //glOrtho(-8, 8, -8, 8, 1, -1);

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
    glutIdleFunc(spin);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
