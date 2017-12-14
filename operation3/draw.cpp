#include "draw.h"

GLint tmp_color[3] = {255, 255, 255};
std::vector<Point> point_vector;
std::vector<Point> fill_vector;
std::vector<Line> line_vector;
std::vector<Rectangle> rectangle_vector;
std::vector<Circle> circle_vector;
std::vector<Bezier> bezier_vector;
std::vector<Oval> oval_vector;
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

void change_color(GLint c_1, GLint c_2, GLint c_3){
    tmp_color[0] = c_1;
    tmp_color[1] = c_2;
    tmp_color[2] = c_3;
}

void display(void){
    flush_paper();
    if (mouse_button){
	if (draw_type == point_type){
	    Point new_point(mouse_pos_x, mouse_pos_y, tmp_color);
	    point_vector.push_back(new_point);
	    button_num = 1;
	}else if(draw_type == line_type/* && button_num*/){
	    Line new_line(mouse_pos_x_pass, mouse_pos_y_pass, mouse_pos_x, mouse_pos_y, tmp_color);
	    line_vector.push_back(new_line);
	    button_num = 1;
	}else if(draw_type == rectangle_type && button_num){
	    Rectangle new_rectangle(mouse_pos_x_pass, mouse_pos_y_pass, mouse_pos_x, mouse_pos_y, tmp_color);
	    rectangle_vector.push_back(new_rectangle);
	    button_num = 1;
	}else if(draw_type == circle_type && button_num){
	    Circle new_circle(mouse_pos_x_pass, mouse_pos_y_pass, mouse_pos_x, mouse_pos_y, tmp_color);
	    circle_vector.push_back(new_circle);
	    button_num = 1;
	}else if(draw_type == oval_type){
	    if (oval_vector.size() == 0 || (oval_vector.size() != 0 && oval_vector[oval_vector.size() - 1].x_vector.size() == 2)){
		Oval new_oval(mouse_pos_x, mouse_pos_y, tmp_color);
		oval_vector.push_back(new_oval);
	    }else{
		oval_vector[oval_vector.size() - 1].push_point(mouse_pos_x, mouse_pos_y);
	    }
	    button_num = 1;
	}else if(draw_type == Bezier_type){
	    if (status && bezier_vector.size() != 0){
		bezier_vector[bezier_vector.size() - 1].push_point(mouse_pos_x, mouse_pos_y);
	    }else{
		status = 1;
		Bezier new_bezier(mouse_pos_x, mouse_pos_y, tmp_color);
		bezier_vector.push_back(new_bezier);
	    }
	    button_num = 1;
	}else if (draw_type == fill_type){
	    Point new_point(mouse_pos_x, mouse_pos_y, tmp_color);
	    fill_vector.push_back(new_point);
	    button_num = 1;
	}
	mouse_button = false;
    }
    draw_point();
    draw_line();
    draw_rectangle();
    draw_circle();
    draw_bezier();
    draw_oval();
    draw_fill();
    
    glRasterPos2f(-1, -1);
    glDrawPixels(window_width, window_height, GL_RGB, GL_UNSIGNED_BYTE, paper);

    glFlush();
    glutPostRedisplay();
}

void draw_control_point(int x, int y){
    int r = 5;
    int tmp_x(0), tmp_y(r), p(5 / 4 - r);
    DRAW_POINT(x, r + y);
    DRAW_POINT(x, -r + y);
    DRAW_POINT(r + x, y);
    DRAW_POINT(-r + x, y);
    while(tmp_x < tmp_y){
	tmp_x++;
	if (p < 0)
	    p = p + 2 * tmp_x + 1;
	else{
	    p = p + 2 * tmp_x - 1 - 2 * tmp_y;
	    tmp_y--;
	}
	DRAW_POINT(tmp_x + x, tmp_y + y);
	DRAW_POINT(tmp_x + x, -tmp_y + y);
	DRAW_POINT(-tmp_x + x, tmp_y + y);
	DRAW_POINT(-tmp_x + x, -tmp_y + y);
	DRAW_POINT(tmp_y + x, tmp_x + y);
	DRAW_POINT(-tmp_y + x, tmp_x + y);
	DRAW_POINT(tmp_y + x, -tmp_x + y);
	DRAW_POINT(-tmp_y + x, -tmp_x + y);
    }
}
