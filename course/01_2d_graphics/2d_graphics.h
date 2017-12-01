void init(){
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 400);
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);

    //draw a point
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    	glVertex2i(300, 10);
    glEnd();
    //draw a line loop
    glColor3f(0, 1, 0);
    glBegin(GL_LINE_LOOP); //GL_LINES    GL_LINE_STRIP
    	glVertex2i(10, 100);
	glVertex2i(400, 300);
	glVertex2i(200, 300);
    glEnd();
    //draw a square
    glRecti(200, 100, 50, 250);//draw from (x1, y1) to (x2, y1) to (x2, y2) to (x1, y2)
    //draw a polygon
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    	glVertex2i(0, 0);
	glVertex2i(400, 100);
	glVertex2i(300, 200);
	glVertex2i(400, 300);
    glEnd();

    glFlush();
}
