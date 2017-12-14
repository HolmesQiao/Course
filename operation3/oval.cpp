#include "draw.h"
#include <math.h>

void Oval::push_point(int x, int y){
    x_vector.push_back(x);
    y_vector.push_back(y);
    r_x = abs(x_vector[1] - x_vector[0]);
    r_y = abs(y_vector[1] - y_vector[0]);
    centre_x = x_vector[0];
    centre_y = y_vector[1];
}

void Oval::update(void){
    r_x = abs(x_vector[1] - x_vector[0]);
    r_y = abs(y_vector[1] - y_vector[0]);
    centre_x = x_vector[0];
    centre_y = y_vector[1];
}

Oval::Oval(int x, int y, GLint color[3]){
    for (int i = 0; i < 3; i++) this->color[i] = (GLubyte)color[i];
    push_point(x, y);
}

void Oval::draw(void){
    for (int i = 0; i < x_vector.size(); i++)
	draw_control_point(x_vector[i], y_vector[i]);
    if (x_vector.size() == 1) return;
    float p = pow(r_y, 2) - pow(r_x, 2) * r_y + 1 / 4 * pow(r_x, 2);
    int tmp_x = 0, tmp_y = r_y;
    int two_x = pow(r_x, 2), two_y = pow(r_y, 2);
    DRAW_POINT(tmp_x + centre_x, tmp_y + centre_y);
    DRAW_POINT(tmp_x + centre_x, -tmp_y + centre_y);
    while(2 * two_y * tmp_x < 2 * two_x * tmp_y){
	tmp_x++;
	if (p < 0){
	    p = p + 2 * two_y * tmp_x + two_y;
	}else{
	    tmp_y--;
	    p = p + 2 * two_y * tmp_x - 2 * two_x * tmp_y + two_y;
	}
	DRAW_POINT(tmp_x + centre_x, tmp_y + centre_y);
	DRAW_POINT(tmp_x + centre_x, -tmp_y + centre_y);
	DRAW_POINT(-tmp_x + centre_x, tmp_y + centre_y);
	DRAW_POINT(-tmp_x + centre_x, -tmp_y + centre_y);
    }
    p = two_y * pow(tmp_x + 1/2, 2) + two_x * pow(tmp_y - 1, 2) - two_x * two_y;
    while(tmp_y >= 0){
	tmp_y--;
	if (p > 0){
	    p = p - 2 * two_x * tmp_y + two_x;
	}else{
	    tmp_x++;
	    p = p + 2 * two_y * tmp_x - 2 * two_x * tmp_y + two_x;
	}
	DRAW_POINT(tmp_x + centre_x, tmp_y + centre_y);
	DRAW_POINT(tmp_x + centre_x, -tmp_y + centre_y);
	DRAW_POINT(-tmp_x + centre_x, tmp_y + centre_y);
	DRAW_POINT(-tmp_x + centre_x, -tmp_y + centre_y);
    }
}

void draw_oval(void){
    for (int i = 0; i < oval_vector.size(); i++){
	oval_vector[i].draw();
    }
}
