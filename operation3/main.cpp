#include "data.h"

GLfloat window_width = 1000.f, window_height = 700.f;

int main(int argc, char** argv){
    glutInit(&argc, argv);
    run_gl();

    return 0;
}

void run_gl(void){
    init_gl();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutIdleFunc(spinMap);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);
    
    glutMainLoop();
}
