#include "data.h"

GLfloat window_width = 500.f, window_height = 500.f;

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
