#include "data.h"
#include "control.h"
//#include "draw.h"

GLfloat mouse_pos_x(0), mouse_pos_y(0);
GLfloat mouse_pos_x_pass(0), mouse_pos_y_pass(0);
//GLint tmp_color[3] = {255, 255, 255};//tmp
bool mouse_button(false);
Draw_type draw_type(point_type);

void spinMap(void){glutPostRedisplay();}
void keyboard(unsigned char key, int x, int y){
    switch(key){
	case 'q': exit(0); break;
    }
    glutPostRedisplay();
}
void main_menu_func(int id){
    switch(id){
	case 1: draw_type = point_type; break;
	case 2: draw_type = line_type; button_num = -1; break;
	case 3: draw_type = circle_type; break;
	case 4: exit(0);
    }
}

void reshape(GLsizei w, GLsizei h){
    window_width = w, window_height = h;
    glLoadIdentity();
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}

void init_gl(void){
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Maze");
    //glEnable(GL_DEPTH_TEST);
    /*glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);*/
    //glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glutCreateMenu(main_menu_func);
    for (int i = 0; i < menu_num; i++)	
	glutAddMenuEntry(main_menu_char[i].cmd, main_menu_char[i].id);
    //glutAddMenuEntry("quit", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glMatrixMode(GL_MODELVIEW);
    glClearColor(0, 0, 0, 0.0);
    
    glViewport(0, 0, window_width, window_height);
}

void mouseButton(int button, int state, int x, int y){
    printf("mouse x y:%d %d\n", x, y);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
	mouse_pos_x_pass = mouse_pos_x;
	mouse_pos_y_pass = mouse_pos_y;
	mouse_pos_x =  (x - window_width / 2);
	mouse_pos_y = -(y - window_height / 2);
	mouse_button = true;
	button_num = (button_num + 1) % 2;
	printf("x: %f y: %f\n", mouse_pos_x, mouse_pos_y);
    }
}
