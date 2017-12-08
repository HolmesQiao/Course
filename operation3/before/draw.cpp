#include "draw.h"

GLint tmp_color[3] = {255, 255, 255};
std::vector<Point> point_vector;
std::vector<Line> line_vector;
GLubyte paper[1050][1680][3];

void flush_paper(void){
    int k = 0;
    for (int i = 0; i < 1050; i++){
	for (int j = 0; j < 1680; j++){
	    for (int m = 0; m < 3; m++){
		if (k >= window_width * window_height) break;
		paper[i][j][m] = (GLubyte)255;
	    }
	}
    }
}

void mouseMotion(int x, int y){
    x =  x - window_width / 2;
    y = -y - window_height / 2;
    for (int i = 0; i < point_vector.size(); i++)
	if (x > point_vector[i].x - 20 && x < point_vector[i].x + POINT_WIDTH + 20 && 
		y > point_vector[i].y - 20 && y < point_vector[i].y + POINT_HEIGHT + 20){
	    point_vector[i].change_pos((GLint)x, (GLint)y);
	    mouse_button = false;
	}
    for (int i = 0; i < line_vector.size(); i++){
	GLint began_x = line_vector[i].began.x, began_y = line_vector[i].began.y;
	GLint end_x = line_vector[i].end.x, end_y = line_vector[i].end.y;
	if (x > began_x - 20 && x < began_x + POINT_WIDTH + 20 && 
		y > began_y - 20 && y < began_y + POINT_HEIGHT + 20){
	    line_vector[i].began.change_pos((GLint)x, (GLint)y);
	    line_vector[i].renew_k();
	    mouse_button = false;
	}
	if (x > end_x - 20 && x < end_x + POINT_WIDTH + 20 && 
		y > end_y - 20 && y < end_y + POINT_HEIGHT + 20){
	    line_vector[i].end.change_pos((GLint)x, (GLint)y);
	    line_vector[i].renew_k();
	    mouse_button = false;
	}
    }
    std::cout << "motion: " << x << " " << y << std::endl;
    glutPostRedisplay();
}

void display(void){
    flush_paper();
    if (mouse_button){
	if (draw_type == point_type){
	    Point new_point(mouse_pos_x, mouse_pos_y, tmp_color);
	    point_vector.push_back(new_point);
	}else if(draw_type == line_type && button_num){
	    Line new_line(mouse_pos_x_pass, mouse_pos_y_pass, mouse_pos_x, mouse_pos_y, tmp_color);
	    line_vector.push_back(new_line);
	}
	mouse_button = false;
    }
    draw_point();
    draw_line();
    
    glRasterPos2f(-1, -1);
    glDrawPixels(window_width, window_height, GL_RGB, GL_UNSIGNED_BYTE, paper);

    glFlush();
    glutPostRedisplay();
}
