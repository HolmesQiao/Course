#include "draw.h"
#include <math.h>

void draw_rectangle(void){
    for (int i = 0; i < rectangle_vector.size(); i++){
	rectangle_vector[i].draw();
    }
}

Rectangle::Rectangle(GLint began_x, GLint began_y, GLint end_x, GLint end_y, GLint color[3]){
    for (int i = 0; i < 3; i++) this->color[i] = (GLubyte)color[i];
    this-> began_x = began_x;
    this-> began_y = began_y;
    this-> end_x = end_x;
    this-> end_y = end_y;
}

void Rectangle::draw(void){
    draw_control_point(began_x, began_y);
    draw_control_point(end_x, end_y);
    DRAW_LINE(began_x, began_y, end_x, began_y);
    DRAW_LINE(began_x, end_y, end_x, end_y);
    int delta_x = abs(end_x - began_x), delta_y = abs(end_y - began_y), type(0);
    int iy = (end_y - began_y) > 0 ? 1 : -1;
    for (int i = began_y; i != end_y; i += iy){
	DRAW_POINT(began_x, i);
	DRAW_POINT(end_x, i);
    }
}

void Rectangle::update_began(GLint began_x, GLint began_y){
    this-> began_x = began_x;
    this-> began_y = began_y;
}

void Rectangle::update_end(GLint end_x, GLint end_y){
    this-> end_x = end_x;
    this-> end_y = end_y;
}
