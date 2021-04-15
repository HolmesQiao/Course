//#include "data.h"
#include "control.h"
#include "draw.h"

GLfloat mouse_pos_x(0), mouse_pos_y(0);
GLfloat mouse_pos_x_pass(0), mouse_pos_y_pass(0);
bool mouse_button(false);
bool mouse_moution(false);
Draw_type draw_type(point_type);
int status(0);

void spinMap(void){glutPostRedisplay();}
void keyboard(unsigned char key, int x, int y){
    switch(key){
	case 'q': exit(0); break;
    }
    glutPostRedisplay();
}
void main_menu_func(int id){
    switch(id){
	case 1: draw_type = point_type; status = 0; break;
	case 2: draw_type = line_type; button_num = -1; status = 0; break;
	case 3: draw_type = circle_type; status = 0; break;
	case 4: draw_type = rectangle_type; status = 0; break;
	case 5: draw_type = oval_type; status = 0; break;
	case 6: draw_type = Bezier_type; break;
	case 7: draw_type = fill_type; break;
	case 8: exit(0);
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
    glutInitWindowPosition(300, 200);
    glutCreateWindow("Maze");

    glutCreateMenu(main_menu_func);
    for (int i = 0; i < menu_num; i++)	
	glutAddMenuEntry(main_menu_char[i].cmd, main_menu_char[i].id);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glMatrixMode(GL_MODELVIEW);
    glClearColor(0, 0, 0, 0.0);
    
    glViewport(0, 0, window_width, window_height);
}

void mouseButton(int button, int state, int x, int y){
    //printf("mouse x y:%d %d\n", x, y);
    if (mouse_moution){
	mouse_moution = false;
	return;
    }
    //printf("button\n");
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
	printf("button\n");
	mouse_pos_x_pass = mouse_pos_x;
	mouse_pos_y_pass = mouse_pos_y;
	mouse_pos_x =  (x - window_width / 2);
	mouse_pos_y = -(y - window_height / 2);
	mouse_button = true;
	button_num = (button_num + 1) % 2;
    }
}

void mouseMotion(int x, int y){
    printf("motion\n");
    x =  x - window_width / 2;
    y = -(y - window_height / 2);
    button_num = (button_num + 1) % 2;
    for (int i = 0; i < point_vector.size(); i++)
	if (x > point_vector[i].x - 20 && x < point_vector[i].x + POINT_WIDTH + 20 && 
		y > point_vector[i].y - 20 && y < point_vector[i].y + POINT_HEIGHT + 20){
	    point_vector[i].change_pos((GLint)x, (GLint)y);
	    button_num = (button_num + 1) % 2;
	    mouse_button = false;
	    mouse_moution = true;
	}
    /*for (int i = 0; i < fill_vector.size(); i++)
	if (x > fill_vector[i].x - 20 && x < fill_vector[i].x + POINT_WIDTH + 20 && 
		y > fill_vector[i].y - 20 && y < fill_vector[i].y + POINT_HEIGHT + 20){
	    fill_vector[i].change_pos((GLint)x, (GLint)y);
	    button_num++;
	    mouse_button = false;
	    mouse_moution = true;
	}*/
    for (int i = 0; i < line_vector.size(); i++){
	GLint began_x = line_vector[i].began.x, began_y = line_vector[i].began.y;
	GLint end_x = line_vector[i].end.x, end_y = line_vector[i].end.y;
	if (x > began_x - 20 && x < began_x + POINT_WIDTH + 20 && 
		y > began_y - 20 && y < began_y + POINT_HEIGHT + 20){
	    line_vector[i].began.change_pos((GLint)x, (GLint)y);
	    line_vector[i].renew_k();
	    button_num = (button_num + 1) % 2;
	    mouse_button = false;
	    mouse_moution = true;
	}
	if (x > end_x - 20 && x < end_x + POINT_WIDTH + 20 && 
		y > end_y - 20 && y < end_y + POINT_HEIGHT + 20){
	    line_vector[i].end.change_pos((GLint)x, (GLint)y);
	    line_vector[i].renew_k();
	    button_num = (button_num + 1) % 2;
	    mouse_button = false;
	    mouse_moution = true;
	}
    }
    for (int i = 0; i < rectangle_vector.size(); i++){
	GLint began_x = rectangle_vector[i].began_x, began_y = rectangle_vector[i].began_y;
	GLint end_x = rectangle_vector[i].end_x, end_y = rectangle_vector[i].end_y;
	if (x > began_x - 20 && x < began_x + POINT_WIDTH + 20 && 
		y > began_y - 20 && y < began_y + POINT_HEIGHT + 20){
	    rectangle_vector[i].update_began((GLint)x, (GLint)y);
	    button_num = (button_num + 1) % 2;
	    mouse_button = false;
	    mouse_moution = true;
	}
	if (x > end_x - 20 && x < end_x + POINT_WIDTH + 20 && 
		y > end_y - 20 && y < end_y + POINT_HEIGHT + 20){
	    rectangle_vector[i].update_end((GLint)x, (GLint)y);
	    button_num = (button_num + 1) % 2;
	    mouse_button = false;
	    mouse_moution = true;
	}
    }
    for (int i = 0; i < circle_vector.size(); i++){
	GLint began_x = circle_vector[i].began_x, began_y = circle_vector[i].began_y;
	GLint end_x = circle_vector[i].end_x, end_y = circle_vector[i].end_y;
	if (x > began_x - 20 && x < began_x + POINT_WIDTH + 20 && 
		y > began_y - 20 && y < began_y + POINT_HEIGHT + 20){
	    circle_vector[i].update_began((GLint)x, (GLint)y);
	    button_num = (button_num + 1) % 2;
	    mouse_button = false;
	    mouse_moution = true;
	}
	if (x > end_x - 20 && x < end_x + POINT_WIDTH + 20 && 
		y > end_y - 20 && y < end_y + POINT_HEIGHT + 20){
	    circle_vector[i].update_end((GLint)x, (GLint)y);
	    button_num = (button_num + 1) % 2;
	    mouse_button = false;
	    mouse_moution = true;
	}
    }
    for (int i = 0; i < bezier_vector.size(); i++){
	for (int j = 0; j < bezier_vector[i].x_vector.size(); j++){
	    GLint began_x = bezier_vector[i].x_vector[j], began_y = bezier_vector[i].y_vector[j];
	    if (x > began_x - 20 && x < began_x + POINT_WIDTH + 20 && 
		    y > began_y - 20 && y < began_y + POINT_HEIGHT + 20){
		bezier_vector[i].x_vector[j] = x, bezier_vector[i].y_vector[j] = y;
		button_num = (button_num + 1) % 2;
		mouse_button = false;
		mouse_moution = true;
	    }
	}
    }
    for (int i = 0; i < oval_vector.size(); i++){
	for (int j = 0; j < oval_vector[i].x_vector.size(); j++){
	    GLint began_x = oval_vector[i].x_vector[j], began_y = oval_vector[i].y_vector[j];
	    if (x > began_x - 20 && x < began_x + POINT_WIDTH + 20 && 
		    y > began_y - 20 && y < began_y + POINT_HEIGHT + 20){
		oval_vector[i].x_vector[j] = x, oval_vector[i].y_vector[j] = y;
		oval_vector[i].update();
		button_num = (button_num + 1) % 2;
		mouse_button = false;
		mouse_moution = true;
	    }
	}
    }
    glutPostRedisplay();
}
