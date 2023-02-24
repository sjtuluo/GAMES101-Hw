## GAMES101-Homework
本项目是**GAMES101：现代计算机图形学入门**的课程作业，非常感谢闫令琪老师的课程分享，使我有机会领略计算机图形学的精彩。  
  
课程主页：[GAMES101：现代计算机图形学入门](https://games-cn.org/intro-graphics/)  
课程链接（Bilibili地址）：[GAMES101-现代计算机图形学入门-闫令琪](https://www.bilibili.com/video/BV1X7411F744?spm_id_from=333.1007.top_right_bar_window_view_later.content.click)


- **Homework 0: Basis**  
环境配置与Eigen库基础。  
课程作业使用虚拟机环境，本项目在Windows环境下使用Visual Studio + Eigen + OpenCV完成。  
  
  
- **Homework 1: Transformation**  
线性变换基础。主要内容包括透视投影矩阵与MVP变换。  
作业要求绘制三角形，并通过键盘控制三角形旋转，如下图所示：  
![Hw1](https://github.com/sjtuluo/GAMES101-Hw/blob/master/Hw1/Hw1.jpg)
  

- **Homework 2: Rastzerization**  
光栅化基础。主要内容包括判断像素点与三角形位置，信号分析与反走样，Z-buffer深度缓存。  
作业要求绘制两个三角形并着色，通过深度缓存判断前后关系，如下图所示：  
![Hw2](https://github.com/sjtuluo/GAMES101-Hw/blob/master/Hw2/Hw2.jpg)  
  

- **Homework 3: Shading**  
渲染基础。主要内容包括Blinn-Phone光照模型，重心坐标，双线性插值，纹理映射。  
作业要求绘制指定模型并进行纹理贴图，首先使用光照模型计算光线对物体的照射，接下来通过重心坐标插值提高渲染精度，最后对应纹理贴图绘制纹理。  
第一部分作业如下图所示：  
![Hw3_p1](https://github.com/sjtuluo/GAMES101-Hw/blob/master/Hw3/Hw3_p1.jpg)
Shading的最后一部分是凹凸贴图（Bump Mapping）与距离贴图（Displacement Mapping），前者通过对局部位置施加扰动而不改变物体几何模型实现“虚拟”的距离改变，而后者通过对精细模型几何网格顶点施加距离改变实现理想效果。  
第二部分作业如下图所示：
![Hw3_p2](https://github.com/sjtuluo/GAMES101-Hw/blob/master/Hw3/Hw3_p2.jpg)
  
  
- **Homework 4: Geometry**  
几何基础。主要内容包括几何模型隐式与显式表达，贝塞尔曲线与曲面，网格细分与网格简化。  
作业要求绘制人为设置四个控制点的贝塞尔曲线，如下图所示：  
![Hw4](https://github.com/sjtuluo/GAMES101-Hw/blob/master/Hw4/Hw4.jpg)  

- **Homework 5: Ray Tracing**  
光线追踪基础。主要内容包括Whitted光线追踪，光线与三角形面求交点的MT算法。  
作业要求完成光线与三角形面相交判断并得到Whitted光线追踪渲染结果，如下图所示：  
![Hw5](https://github.com/sjtuluo/GAMES101-Hw/blob/master/Hw5/Hw5.jpg)  

- **Homework 6: BVH**  
光线追踪基础。主要内容包括建立包围盒，空间划分与物体划分。  
作业要求实现BVH算法完成光线与物体相交判断，如下图所示：  
![Hw6](https://github.com/sjtuluo/GAMES101-Hw/blob/master/Hw6/Hw6.jpg)  

- **Homework 7: Path Tracing**  
路径追踪基础。主要内容包括辐射度量学，蒙特卡洛积分与路径追踪算法。  
作业要求实现路径追踪算法，渲染模型Cornell Box，作业整体按照文档中伪代码思路完成，整体效果尚不完美，如下图所示：  
![Hw7](https://github.com/sjtuluo/GAMES101-Hw/blob/master/Hw7/Hw7.jpg)  