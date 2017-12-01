#include <GLUT/glut.h>

//Rect.cpp

void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);   //清空颜色缓冲池
    glColor3f(1.0f, 0.0f, 0.0f);    //设置绘图颜色
    glRectf(100.0f, 100.0f, 200.0f, 200.0f);    //绘制矩形
    glFlush();  //执行OpenGL指令列表中的指令
}

void changeSize(GLsizei w, GLsizei h)
{
    if(h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(w <= h)
    {
        glOrtho(0.0f, 300.0f, 0.0f, 300.0f * h/w, 1.0f, -1.0f);
    }else
    {
        glOrtho(0.0f, 300.0f * w/h, 0.0f, 300.0f, 1.0f, -1.0f);
    }
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    //设置显示模式
    glutInitWindowSize(300, 300); //设置窗口大小
    glutInitWindowPosition(200, 200);   //设置窗口在屏幕上的位置
    glutCreateWindow("矩形"); //创建窗口并给出标题
    glutDisplayFunc(renderScene);   //注册显示窗口时回调函数renderScene
    glOrtho(0.0f, 300.0f, 0.0f, 300.0f, 1.0, -1.0);
    glutReshapeFunc(changeSize);    //注册窗口大小改变时回调函数
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);   //使用蓝色清空背景底
    glutMainLoop();     //消息循环（处理操作系统等的消息，例如键盘、鼠标事件等）

    return 0;
}
