#include "draw.h"
#include <math.h>

Line::Line(GLint x_began, GLint y_began, GLint x_end, GLint y_end, GLint color[3]){
    began.change_color(color);
    end.change_color(color);
    began.change_pos(x_began, y_began);
    began.change_color(color);
    end.change_pos(x_end, y_end);
    end.change_color(color);
    k = (GLfloat)(end.y - began.y) / (GLfloat)(end.x - began.x);
    for (int i = 0; i < 3; i++) this->color[i] = (GLubyte)color[i];
}
void Line::renew_k(){k = (GLfloat)(end.y - began.y) / (GLfloat)(end.x - began.x);}

void swap_int(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void draw_line(void){
    for (int i = 0; i < line_vector.size(); i++){
	int began_x, began_y, end_x, end_y, delta_x, delta_y, type = 0;
	began_x = line_vector[i].began.x, end_x = line_vector[i].end.x;
	began_y = line_vector[i].began.y, end_y = line_vector[i].end.y;
	draw_control_point(began_x, began_y);
	draw_control_point(end_x, end_y);
	DRAW_LINE(began_x, began_y, end_x, end_y);
    }
}
