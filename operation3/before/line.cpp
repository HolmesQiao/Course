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

inline void swap_int(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void draw_line(void){
    for (int i = 0; i < line_vector.size(); i++){
	int began_x, began_y, end_x, end_y, delta_x, delta_y, type = 0;
	began_x = line_vector[i].began.x, end_x = line_vector[i].end.x;
	began_y = line_vector[i].began.y, end_y = line_vector[i].end.y;
	delta_x = abs(end_x - began_x), delta_y = abs(end_y - began_y);
	if (delta_x < delta_y){
	    type = 1;
	    swap_int(&began_x, &began_y);
	    swap_int(&end_x, &end_y);
	    swap_int(&delta_x, &delta_y);
	}
	int ix = (end_x - began_x) > 0 ? 1 : -1, iy = (end_y - began_y) > 0 ? 1 : -1;
	int two_times_d_y = 2 * delta_y, two_times_d_xy = (delta_y - delta_x) * 2;
	int d = delta_y * 2 - delta_x;
	int tmp_x = began_x, tmp_y = began_y;
	for (; tmp_x != end_x; i += ix){
	    if (d < 0) d+= 2 * two_times_d_y;
	    else{
		tmp_y += iy;
		d += two_times_d_xy;
	    }
	    if (type) DRAW_POINT(tmp_y, tmp_x);
	    else DRAW_POINT(tmp_x, tmp_y);
	}
    }
}
