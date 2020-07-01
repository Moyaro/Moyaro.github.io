# vtk和二维轮廓等值线
[二维轮廓线提取](http://blog.sina.com.cn/s/blog_84181a7901017ts9.html)
[VTK修炼之道55：图形基本操作进阶_表面重建技术（等值面提取）](https://blog.csdn.net/shenziheng1/article/details/54866291?utm_source=blogxgwz6)
[VTK选择actor并添加外部轮廓](https://blog.csdn.net/douzi949389/article/details/99717065)
[VTK 三维轮廓等值面的提取](https://blog.csdn.net/Jane_yuhui/article/details/51983716?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)
[浅析基于二维轮廓线重构表面算法](https://blog.csdn.net/u013339596/article/details/19167037)
子算法一：判断折线圈是否为逆时针 子算法二： 两层轮廓线编织算法 好刺激！！子算法三：Mesh合并方法简述
在了解了这些子算法的过程之后，可以总结出轮廓线算法的总体步骤如下：
> 为输入轮廓线排序，确保按Z升序排列
    调整输入轮廓线，确保为均逆时针
    平移所有轮廓线，使其几何中心重合
    对所有连续两相邻轮廓线，执行编织算法(子算法二)
    合并子算法二生成的Mesh
    使用子算法四三角化顶面和地面，并将三角片与上一步的Mesh合并
    将轮廓线平移回原来位置。
    
[Visual Studio 2017 RC CMake 支持功能试用](https://fzheng.me/2016/11/22/vs2017_cmake_trial/)
[cmake+vs2017](https://blog.csdn.net/dongchongyang/article/details/80054456?utm_source=blogxgwz4)
[VTK的源代码](https://www.kutu66.com//GitHub/article_78426)
# ActiViz
[ActiViz](https://my.oschina.net/u/3245207?tab=newest&catalogId=5915858)
[备选](https://blog.csdn.net/annjeff/article/details/88597051?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)
# 三维轮廓等值面
[基于等值面点的快速三维表面重建算法 ](http://xueshu.baidu.com/usercenter/paper/show?paperid=bbbe9cbacf1094ef505854bfc94db59d&site=xueshu_se)

意义所在看图片：[三维等值面提取算法（Dual Contouring）](https://www.cnblogs.com/shushen/p/5607833.html)

# 用ActiViz实现三维等值面
1.确定输入和输出
2.算法改写
3.代码环境匹配