## COMPUTER GRAPHICS

这个项目是大二计算机图形学的课程设计，包括了三个OpenGL项目：

* 用OpenGL绘制二维图形:

<img src="http://118.24.109.65/photo_db/233_Markdown_IMG_1.png" style="width:40%">

---

* 3D迷宫

  * 利用并查集生成随机迷宫，思想如下：
    * 将迷宫的点进行分类，图的点，图的边，不会被打通的点；
    * 随机一条没有被打通的边，如果边两边的点之间没有通路(通过并查集来判断)，那么我们就将这条边以及它两头点点打通，并用并查集将打通的点合并；
    * 如此不断的随机打点，直到所有的点之间都有且只有一条通路的时候终止算法。

  <img src="http://118.24.109.65/photo_db/233_Markdown_IMG_2.png" style="width:30%">

  * OpenGL GLUT绘制3D迷宫，绘制部分在gl.cpp中；

  <img src="http://118.24.109.65/photo_db/233_Markdown_IMG_4.png" style="width:40%">

  * 采用BFS对迷宫寻路
    * 按下'R'键显示迷宫通路

  <img src="http://118.24.109.65/photo_db/233_Markdown_IMG_3.png" style="width:75%">

  * 光照为单光源GL_LIGHT0

  ---

* 矢量绘图软件

  * 矩形，多边形，圆，椭圆，Bezier曲线
    * Bresnham画线算法
    * 中点画圆算法
    * 中点椭圆算法
    * 样条逼近Bezier曲线
    * OpenGl I/O
    * OpenGl像素处理
    * OpenGL坐标系统
  * 洪范填充
    * 4向递推BFS(递归可能爆栈)

  <img src="http://118.24.109.65/photo_db/233_Markdown_IMG_5.png" style="width:50%">

  <img src="http://118.24.109.65/photo_db/233_Markdown_IMG_6.png" style="width:50%">