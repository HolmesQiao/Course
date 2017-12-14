#include "draw.h"
#include <math.h>

#define FILL_POINT() do{\
    paper[t][m % 1680][0] = 120;\
    paper[t][m % 1680][1] = 168;\
    paper[t][m % 1680][2] = 207;\
}while(0)

int direction_8[][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int direction_4[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void bound_fill(int x, int y){
    int tmp_xx = (x) + window_width / 2, tmp_yy = (y) + window_height / 2;
    int m = tmp_yy * window_width + tmp_xx, t = m / 1680;
    m = abs(m);
    if (t >= 1050) t = 1049;
    if (t <= 0) t = 0;
    if (paper[t][m % 1680][0] != 120 && paper[t][m % 1680][0] != 0 && 
	    paper[t][m % 1680][1] != 168 && paper[t][m % 1680][1] != 0 && 
	    paper[t][m % 1680][2] != 207 && paper[t][m % 1680][2] != 0){
	FILL_POINT();
	for (int i = 0; i < 4; i++)
	    bound_fill(x + direction_4[i][0], y + direction_4[i][1]);
    }
}

void draw_fill(void){
    for (int i = 0; i < fill_vector.size(); i++)
	bound_fill(fill_vector[i].x, fill_vector[i].y);
}
