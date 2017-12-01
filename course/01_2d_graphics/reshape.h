const GLdouble TWO_PI = 6.2831853
GLzisei winWidth = 400, winHeight = 400;
GLuint regHex;
class screenPt{
    private:
	GLint x, y;
    public:
	ScreenPt(){ x = y = 0;}
	void setCoords(GLint xCoord, GLint yCoord){
	    x = xCoord;
	    y = yCoord;
	}
	GLint getx() const{
	    return x;
	}
	GLint gety() const{
	    return y;
	}

};


static void init(){
    screenPt hexVertex, cirCtr;
    GLdouble theta;

    glClearColor(1, 1, 1, 0);
    regHex = glGenLists(1);
    gLNewList(reHex, GL_COMPILE);
    	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
		for(GLint k = 0; k < 6; k++){
		    theta = TWO_PI * k / 6.0f;
		    hexVertex.setCoords(cirCtr.getx() + 150 * cos(theta), 
			    circCtr.gety() + 150 * sin(theta));
		}
	glEnd();
    glEndList();
}

void regHexmagon(){
    glClear(GL_COLOR_BUFFER_BIT);
    glCallList(regHex);
    glFlush();
}

void winReshapeFcn(int newWidth, int newHeight){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble) newWidth, 0, (GLdouble) newHeight);

    glClear(GL_COLOR_BUFFER_BIT);
}


