#include "draw.h"

void point_draw(int x, int y){
    int tmp_x = x + window_width / 2, tmp_y = y + window_height / 2;
    int m = tmp_y * window_width + tmp_x;

    paper[m / 1680][m % 1680][0] = paper[m / 1680][m % 1680][1] = paper[m / 1680][m % 1680][2] = 0;
}

Point::Point() {
    x = 0; 
    y = 0;
    INIT_COLOR(POINT_WIDTH, POINT_HEIGHT);
}
Point::Point(GLint x, GLint y, GLint color[3]) {
    this->x = x;
    this->y = y; 
    CHANGE_COLOR(POINT_WIDTH, POINT_HEIGHT, color);
}
void Point::change_x(GLint x){
	this->x = x;
}
void Point::change_y(GLint y){
    this->y = y; 
}
void Point::change_color(GLint color[3]){
    CHANGE_COLOR(POINT_WIDTH, POINT_HEIGHT, color);
}
void Point::change_pos(GLint x, GLint y){
    this->x = x;
    this->y = y;
}

void draw_point(void){
    for (int i = 0; i < point_vector.size(); i++){
	int x = point_vector[i].x + window_width / 2, y = point_vector[i].y + window_height / 2;
	for (int j = x - 2; j <= x + 2; j++){
	    for (int k = y - 2; k <= y + 2; k++){
		int m = k * window_width + j;
		paper[m / 1680][m % 1680][0] = paper[m / 1680][m % 1680][1] = paper[m / 1680][m % 1680][2] = 0;
	    }
	}
    }
}
