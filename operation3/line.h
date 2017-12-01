// 交换整数 a 、b 的值
inline void swap_int(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// Bresenham's line algorithm
void draw_line(IMAGE *img, int x1, int y1, int x2, int y2, unsigned long c) {
    // 参数 c 为颜色值
    int dx = abs(x2 - x1),
    dy = abs(y2 - y1),
    yy = 0;
    
    if (dx < dy) {
        yy = 1;
        swap_int(&x1, &y1);
        swap_int(&x2, &y2);
        swap_int(&dx, &dy);
    }
    
    int ix = (x2 - x1) > 0 ? 1 : -1,
    iy = (y2 - y1) > 0 ? 1 : -1,
    cx = x1,
    cy = y1,
    n2dy = dy * 2,
    n2dydx = (dy - dx) * 2,
    d = dy * 2 - dx;
    
    if (yy) { // 如果直线与 x 轴的夹角大于 45 度
        while (cx != x2) {
            if (d < 0) {
                d += n2dy;
            } else {
                cy += iy;
                d += n2dydx;
            }
            putpixel(img, cy, cx, c);
            cx += ix;
        }
    } else { // 如果直线与 x 轴的夹角小于 45 度
        while (cx != x2) {
            if (d < 0) {
                d += n2dy;
            } else {
                cy += iy;
                d += n2dydx;
            }
            putpixel(img, cx, cy, c);
            cx += ix;
        }
    }
}
