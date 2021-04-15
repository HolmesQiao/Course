#include <GLUT/glut.h>
#include <iostream>
#include <cstdio>
#include <string>
//#include <vector>

extern GLfloat window_width, window_height;
extern GLfloat mouse_pos_x, mouse_pos_y;
extern GLfloat mouse_pos_x_pass, mouse_pos_y_pass;
extern bool mouse_button;
extern bool mouse_moution;
extern enum Draw_type{point_type, line_type, circle_type, rectangle_type, oval_type, Bezier_type, fill_type} draw_type;
extern int button_num;
extern GLubyte paper[1050][1680][3];
//control
void init_gl(void);
void reshape(GLsizei w, GLsizei h);
void spinMap(void);
void keyboard(unsigned char key, int x, int y);
void mouseButton(int button, int state, int x, int y);

//main
void run_gl(void);

//draw
void display(void);
void mouseMotion(int x, int y);
void draw_point(void); //draw class 
void draw_control_point(int x, int y);
void change_color(GLint c_1, GLint c_2, GLint c_3);
void draw_line(void);
void draw_circle(void);
void draw_rectangle(void);
void draw_circle(void);
void draw_bezier(void);
void draw_oval(void);
void draw_fill(void);
void bound_fill(int x, int y);
//
void swap_int(int *a, int *b);

extern int status;
