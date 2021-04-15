#include <vector>
#include "data.h"

#define POINT_WIDTH 5 
#define POINT_HEIGHT 5 
#define CHANGE_COLOR(w, h, color) do{\
for(int i = 0; i < w; i++)\
    for (int j = 0; j < h; j++)\
	for (int k = 0; k < 3; k++)\
		this->color[i][j][k] = (GLubyte)color[k];\
}while(0)
#define INIT_COLOR(w, h) do{\
for(int i = 0; i < w; i++)\
    for (int j = 0; j < h; j++)\
	for (int k = 0; k < 3; k++)\
		this->color[i][j][k] = (GLubyte)0;\
}while(0)
#define DRAW_POINT(x, y) do{\
    int tmp_xx = (x) + window_width / 2, tmp_yy = (y) + window_height / 2;\
    int m = tmp_yy * window_width + tmp_xx, t = m / 1680;\
    m = abs(m);\
    if (t >= 1050) t = 1049;\
    if (t <= 0) t = 0;\
    paper[t][m % 1680][0] = paper[t][m % 1680][1] = paper[t][m % 1680][2] = 0;\
}while(0)
#define DRAW_LINE(began_x, began_y, end_x, end_y) do{\
    int delta_x = abs(end_x - began_x), delta_y = abs(end_y - began_y), type(0);\
    if (delta_x < delta_y){\
	type = 1;\
	swap_int(&began_x, &began_y);\
	swap_int(&end_x, &end_y);\
	swap_int(&delta_x, &delta_y);\
    }\
    int ix = (end_x - began_x) > 0 ? 1 : -1, iy = (end_y - began_y) > 0 ? 1 : -1;\
    int two_times_d_y = 2 * delta_y, two_times_d_xy = (delta_y - delta_x) * 2;\
    int d = delta_y * 2 - delta_x;\
    int tmp_x = began_x, tmp_y = began_y;\
    for (; tmp_x != end_x; tmp_x += ix){\
	if (d < 0) d += two_times_d_y;\
	else{\
	    tmp_y += iy;\
	    d += two_times_d_xy;\
	}\
	if (type) DRAW_POINT(tmp_y, tmp_x);\
	else DRAW_POINT(tmp_x, tmp_y);\
    }\
} while(0)

#define MAX_POINT_NUM 100
/*************class point*************/
class Point{
    public:
	GLint x, y;
	GLubyte color[POINT_WIDTH][POINT_HEIGHT][3];

	Point();
	Point(GLint x, GLint y, GLint color[3]);
	void change_x(GLint x);
	void change_y(GLint y);
	void change_pos(GLint x, GLint y);
	void change_color(GLint color[3]);
};

/**************class line*************/
class Line{
    public:
	GLint x_began, y_began, x_end, y_end;
	GLfloat k;
	Point began, end;
	GLubyte color[3];

	Line(GLint x_began, GLint y_began, GLint x_end, GLint y_end, GLint color[3]);
	void renew_k();
};

/**************class rectangle*************/
class Rectangle{
    public:
	Rectangle(GLint began_x, GLint began_y, GLint end_x, GLint end_y, GLint color[3]);
	GLint began_x, began_y, end_x, end_y;
	GLubyte color[3];
	//Line l_1, l_2, l_3, l_4;
	void draw();
	void update_began(GLint began_x, GLint began_y);
	void update_end(GLint end_x, GLint end_y);
};

class Circle{
    public:
	Circle(GLint began_x, GLint began_y, GLint end_x, GLint end_y, GLint color[3]);
	GLint began_x, began_y, end_x, end_y, r;
	GLubyte color[3];
	void draw();
	void update_began(GLint began_x, GLint began_y);
	void update_end(GLint end_x, GLint end_y);
};

class Bezier{
    public:
	Bezier(int x, int y, GLint color[3]);
	std::vector<int> x_vector;
	std::vector<int> y_vector;
	GLubyte color[3];
	GLint draw_x, draw_y;
	void BEZ(double u);
	//int Y_BEZ(float u);

	void draw();
	void push_point(int x, int y);
};

class Oval{
    public:
	Oval(int centre_x, int centre_y, GLint color[3]);
	std::vector<int> x_vector;
	std::vector<int> y_vector;
	GLubyte color[3];
	GLint r_x, r_y, centre_x, centre_y;
	void push_point(int x, int y);
	void update();
	void draw();
};

/*************Layers**************/
/*
class Layers: public Point, public Line{
};

class Canvas: public Layers{
};
*/


/************vector************/
extern std::vector<Point> point_vector;
extern std::vector<Point> fill_vector;
extern std::vector<Line> line_vector;
extern std::vector<Rectangle> rectangle_vector;
extern std::vector<Circle> circle_vector;
extern std::vector<Bezier> bezier_vector;
extern std::vector<Oval> oval_vector;
