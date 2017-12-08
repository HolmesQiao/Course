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
    int tmp_x = x + window_width / 2, tmp_y = y + window_height / 2;\
    int m = tmp_y * window_width + tmp_x;\
    paper[m / 1680][m % 1680][0] = paper[m / 1680][m % 1680][1] = paper[m / 1680][m % 1680][2] = 0;\
}while(0)

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
extern std::vector<Line> line_vector;
