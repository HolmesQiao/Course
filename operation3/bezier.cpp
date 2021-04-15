#include "draw.h"
#include <math.h>

void Bezier::push_point(int x, int y){
    x_vector.push_back(x);
    y_vector.push_back(y);
}

Bezier::Bezier(int x, int y, GLint color[3]){
    for (int i = 0; i < 3; i++) this->color[i] = (GLubyte)color[i];
    push_point(x, y);
}

void Bezier::BEZ(double u){
    const int n = x_vector.size() - 1;
    double C[n + 1], B[n + 1], x(0), y(0);
    C[0] = 1, B[0] = C[0] * pow(1 - u, n);
    for (int i = 1; i < n + 1; i++){
	C[i] = double(n - i + 1) / i * C[i - 1];
	B[i] = C[i] * pow(u, i) * pow(1 - u, n - i);
    }
    for (int i = 0; i < n + 1; i++){
	x += (double)x_vector[i] * B[i];
	y += (double)y_vector[i] * B[i];
    }
    draw_x = x, draw_y = y;
}

void Bezier::draw(void){
    const int n = x_vector.size() - 1;
    for (int i = 0; i < n + 1; i++)
	draw_control_point(x_vector[i], y_vector[i]);
    for (double u(0); u <= 1; u += 0.0001){
	BEZ(u);
	DRAW_POINT(draw_x, draw_y);
    }
}

void draw_bezier(void){
    for (int i = 0; i < bezier_vector.size(); i++){
	bezier_vector[i].draw();
    }
}
