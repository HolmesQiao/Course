#include <iostream>
#include <GLUT/glut.h>
#include "point.h"

#define DRAW(type, obj, num) do{\
    glBegin(type);\
    	for (int i = 0; i < num; i++) glVertex3fv(obj[i]);\
    glEnd();\
}while(0)

using namespace std;

typedef GLfloat vertex3[3];

GLfloat width = 300;
GLfloat high = 300;
GLfloat r = 45;
vertex3 plan1_1[4] = {J_1, I_1, V, F_1};
vertex3 plan1_2[4] = {I_1, R, L, V};
vertex3 plan1_3[4] = {V, L, I, A};
vertex3 plan1_4[4] = {F_1, V, A, B};
vertex3 plan2_1[4] = {V_1, D_2, P_1, D_1};
vertex3 plan2_2[4] = {D_2, E_2, Q_1, P_1};
vertex3 plan2_3[4] = {P_1, Q_1, M_1, A_1};
vertex3 plan2_4[4] = {D_1, P_1, A_1, Z};
vertex3 plan3_1[4] = {V_1, D_2, G_2, A_2};
vertex3 plan3_2[4] = {D_2, E_2, F_2, G_2};
vertex3 plan3_3[4] = {G_2, F_2, R, I_1};
vertex3 plan3_4[4] = {A_2, G_2, I_1, J_1};
vertex3 plan4_1[4] = {Z, A_1, J, C};
vertex3 plan4_2[4] = {A_1, M_1, N_1, J};
vertex3 plan4_3[4] = {J, N_1, I, A};
vertex3 plan4_4[4] = {C, J, A, B};
vertex3 plan5_1[4] = {E_2, F_2, B_2, Q_1};
vertex3 plan5_2[4] = {F_2, R, L, B_2};
vertex3 plan5_3[4] = {B_2, L, I, N_1};
vertex3 plan5_4[4] = {Q_1, B_2, N_1, M_1};
vertex3 plan6_1[4] = {V_1, A_2, G_1, D_1};
vertex3 plan6_2[4] = {A_2, J_1, F_1, G_1};
vertex3 plan6_3[4] = {G_1, F_1, B, C};
vertex3 plan6_4[4] = {D_1, G_1, C, Z};

vertex3 line_loop_1[4] = {J_1, R, I, B};
vertex3 line_cross_1[4] = {L, F_1, I_1, A};
vertex3 line_loop_2[4] = {V_1, E_2, M_1, Z};
vertex3 line_cross_2[4] = {Q_1, D_1, D_2, A_1};
vertex3 line_loop_3[4] = {V_1, E_2, R, J_1};
vertex3 line_cross_3[4] = {F_2, A_2, D_2, I_1};
vertex3 line_loop_4[4] = {Z, M_1, I, B};
vertex3 line_cross_4[4] = {N_1, C, A_1, A};
vertex3 line_loop_5[4] = {E_2, R, I, M_1};
vertex3 line_cross_5[4] = {L, Q_1, F_2, N_1};
vertex3 line_loop_6[4] = {V_1, J_1, B, Z};
vertex3 line_cross_6[4] = {A_2, C, F_1, D_1};

void init(void); 
void display(void);
void spin(void){
    glutPostRedisplay();
}
void rotatef(void);
//glScaled(x, y, z); //在xyz方向上放大xyz倍
void reshape(GLsizei w, GLsizei h){
    width = w, high = h;
    //glLoadIdentity();
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glLoadIdentity();
    if(w <= h){
        glOrtho(-2, 2, -2 * h / w, 2 * h / w, 2, -2);
    }else{
        glOrtho(-2 * w / h, 2 * w / h, -2, 2, 2, -2);
    }

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, high);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Experiment 2");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(spin);
    
    glutMainLoop();

    return 0;
}

void init(void){
    glClearColor(0, 0, 0, 0.0);
    
    //glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    glOrtho(-2, 2, -2, 2, 2, -2);
    glViewport(0, 0, width, high);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glTranslatef(-1, 0, 0);
    glColor3f(0, 1, 0);
    	DRAW(GL_QUADS, plan1_1, 4);
    	DRAW(GL_QUADS, plan1_2, 4);
    	DRAW(GL_QUADS, plan1_3, 4);
    	DRAW(GL_QUADS, plan1_4, 4);
    glColor3f(1, 0.5, 0);
    	DRAW(GL_QUADS, plan2_1, 4);
	DRAW(GL_QUADS, plan2_2, 4);
	DRAW(GL_QUADS, plan2_3, 4);
	DRAW(GL_QUADS, plan2_4, 4);
    glColor3f(1, 0, 0);
    	DRAW(GL_QUADS, plan3_1, 4);
    	DRAW(GL_QUADS, plan3_2, 4);
    	DRAW(GL_QUADS, plan3_3, 4);
    	DRAW(GL_QUADS, plan3_4, 4);
    glColor3f(1, 1, 0);
    	DRAW(GL_QUADS, plan3_1, 4);
    	DRAW(GL_QUADS, plan3_2, 4);
    	DRAW(GL_QUADS, plan3_3, 4);
    	DRAW(GL_QUADS, plan3_4, 4);
    glColor3f(0, 0, 1);
    	DRAW(GL_QUADS, plan4_1, 4);
    	DRAW(GL_QUADS, plan4_2, 4);
    	DRAW(GL_QUADS, plan4_3, 4);
    	DRAW(GL_QUADS, plan4_4, 4);
    glColor3f(1, 0, 1);
    	DRAW(GL_QUADS, plan5_1, 4);
    	DRAW(GL_QUADS, plan5_2, 4);
    	DRAW(GL_QUADS, plan5_3, 4);
    	DRAW(GL_QUADS, plan5_4, 4);
    glColor3f(0, 0.5, 1);
    	DRAW(GL_QUADS, plan6_1, 4);
    	DRAW(GL_QUADS, plan6_2, 4);
    	DRAW(GL_QUADS, plan6_3, 4);
    	DRAW(GL_QUADS, plan6_4, 4);

    glColor3f(1, 1, 1);
    	DRAW(GL_LINE_LOOP, line_loop_1, 4);
	DRAW(GL_LINES, line_cross_1, 4);
    	DRAW(GL_LINE_LOOP, line_loop_2, 4);
	DRAW(GL_LINES, line_cross_2, 4);
    	DRAW(GL_LINE_LOOP, line_loop_3, 4);
	DRAW(GL_LINES, line_cross_3, 4);
    	DRAW(GL_LINE_LOOP, line_loop_4, 4);
	DRAW(GL_LINES, line_cross_4, 4);
    	DRAW(GL_LINE_LOOP, line_loop_5, 4);
	DRAW(GL_LINES, line_cross_5, 4);
    	DRAW(GL_LINE_LOOP, line_loop_6, 4);
	DRAW(GL_LINES, line_cross_6, 4);

    glLoadIdentity();
    glRotatef(r, 1, 1, 0);
    r += 0.2;
    glFlush();
    glutSwapBuffers();
}

void rotatef(void){
}
