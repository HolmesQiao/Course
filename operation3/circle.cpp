#include "draw.h"
#include <math.h>

void draw_circle(void){
    for (int i = 0; i < circle_vector.size(); i++){
	circle_vector[i].draw();
    }
}

inline bool f(int x, int y, int r){
    return pow(x + 1, 2) + pow(y - 0.5, 2) - pow(r, 2) <= 0;
}

Circle::Circle(GLint began_x, GLint began_y, GLint end_x, GLint end_y, GLint color[3]){
    for (int i = 0; i < 3; i++) this->color[i] = (GLubyte)color[i];
    this-> began_x = began_x;
    this-> began_y = began_y;
    this-> end_x = end_x;
    this-> end_y = end_y;
    r = sqrt(pow(began_x - end_x, 2) + pow(began_y - end_y, 2));
}

void Circle::draw(void){
    draw_control_point(began_x, began_y);
    draw_control_point(end_x, end_y);
    int x(0), y(r), p(5 / 4 - r);
    DRAW_POINT(began_x, r + began_y);
    DRAW_POINT(began_x, -r + began_y);
    DRAW_POINT(r + began_x, began_y);
    DRAW_POINT(-r + began_x, began_y);
    while(x < y){
	x++;
	if (p < 0)
	    p = p + 2 * x + 1;
	else{
	    p = p + 2 * x - 1 - 2 * y;
	    y--;
	}
	DRAW_POINT(x + began_x, y + began_y);
	DRAW_POINT(x + began_x, -y + began_y);
	DRAW_POINT(-x + began_x, y + began_y);
	DRAW_POINT(-x + began_x, -y + began_y);
	DRAW_POINT(y + began_x, x + began_y);
	DRAW_POINT(-y + began_x, x + began_y);
	DRAW_POINT(y + began_x, -x + began_y);
	DRAW_POINT(-y + began_x, -x + began_y);
    }
}

void Circle::update_began(GLint began_x, GLint began_y){
    this-> began_x = began_x;
    this-> began_y = began_y;
    r = sqrt(pow(began_x - end_x, 2) + pow(began_y - end_y, 2));
}

void Circle::update_end(GLint end_x, GLint end_y){
    this-> end_x = end_x;
    this-> end_y = end_y;
    r = sqrt(pow(began_x - end_x, 2) + pow(began_y - end_y, 2));
}
