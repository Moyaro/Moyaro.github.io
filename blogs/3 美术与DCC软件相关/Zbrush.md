# Zbrush
[zbrush官方中文教程](https://wenku.baidu.com/view/9512ce3fa32d7375a4178039.html?sxts=1583327634776)
[ZBrush基础入门详解教程(中文字幕)](https://www.bilibili.com/video/av17027700?from=search&seid=13844308174781350360)
1、介绍
ZB保存时是一个画面，要保持三维物体的可编辑性必须保存为笔刷。
2、物体的变换
创建物体后按“T”进入编辑模式。
旋转视图：鼠标在空白处拖动，shift+LMB可以角度锁定90度。
平移视图：Alt+LMB
缩放视图：Alt+LMB、保持按下LMB时放开Alt然后上下拖动鼠标左键 Alt+click：物体适中
移动W：空白处拖动鼠标——在垂直于画布方向移动，往上即向里移动。在交叉点上拖动锁定方向，在圈内移动则使物体在画布上移动
旋转E：圈内随意转
缩放R：圈内等比缩放
3、画布
平移(Scroll)：按住空格键拖动鼠标
缩放(Zoom)：+ -
适中(Actual)：0
半大（AAHalf）：Ctrl+0
Ctrl+N：清空画布
4、物体编辑
创建新物体后，原物体不再能编辑，而是作为画面中的一个元素


对于新手学习有困难可以加扣：8135124进行交流获取免费听课权限一对一在线指导学习。


导入模型（作为笔刷编辑）：tool/import
保存笔刷（可在ZB中继续编辑）：tool/save as
导出物体：tool/export
注：在从max导入obj之前在preferen.../importexport里选择iFlipY、iFlipZ就是正的了。
5、界面
Tab：隐藏工具面板
下拉菜单可以拖动到两边的空白处
常用按钮可以按CTRL同时拖动到画布边的空白处，Ctrl+click可以取消快捷按钮。
鼠标放在工具上按Ctrl可以显示说明。
6、模型细分
Tool/Divide(Ctrl+D)可以对模型细分
SDiv改变细分级别，或者使用Lower Res(Shift+D)、Higher Res(D)进行切换 一般先在低精度调整大型，描绘越细致精度越高，不要一开始就在最高精度下工作，那样交互速度和工作效率都不会很高的。
7、多边形的隐藏、显示
隐藏多边形可以加快操作速度，也可以避免对不需要编辑的部分误操作。 方法：
(1)Ctrl+Shift+LMB拖动框选，出现绿框，松开鼠标，框外的就被隐藏。
(2)Ctrl+Shift+LMB拖动框选，出现绿框，先放开Shift（变红框）再松开鼠标，框内的就被隐藏。
(3)Ctrl+Shift同时点击模型，原来被隐藏的被显示，原来显示的被隐藏
(4)Ctrl+Shift同时点击空白处，显示所有部分
(5)模型显示部分多边形状态下，点击tool/polygroups/Group Visible会将当前显示的多边形作为一个显示的组。以后只要Ctrl+Shift同时点击这个组的任何一个部分就会隐藏其他组。
(6)默认情况下，选择框要包含整个多变形才能起作用，如果按下AAHalf下面的PtSel按钮(Ctrl+Shift+P)，只要选择框和多边形相交即可。
8、蒙板
Ctrl+LMB拖动出蒙板区域，蒙板内变深灰色，不再被编辑。
Ctrl+LMB拖动出蒙板区域，蒙板内变深灰色，再按下Alt，区域变白，可以减少蒙板区域。
Ctrl+click画布空白处，蒙板反转
Ctrl+LMB在画布空白处拖动，选择框不接触物体，可以取消蒙板
Ctrl+LMB在模型上可绘制蒙板
Alpha菜单里可以改变蒙板的类型。
9、上色和造型
物体原来是浅灰色，如果在调色板里改变颜色，物体的颜色同时改变。选择Color/FillObject，可以对物体填充当前色。
画布上方按钮说明：
Mrgb：赋予当前材质和颜色
Rgb：赋予颜色
M：赋予当前材质
Rgb Intensity：透明度
Zadd：增加厚度
Zsub：降低厚度
Z Intensity：笔刷强度
Focal Shift：柔化值
Draw Size：笔刷大小
以上按钮在画布上点右键或按空格键均可出现
10、利用规尺
stencil/stencil on可以显示规尺，浅色区域不能编辑。在规尺上按下右键或空格键出现操纵工具，然后可以选择相应的按钮。
Invr：反相
Stretch：扩大到画布大小
Actual：实际大小
Horiz：宽度匹配画布
Vert：高度匹配画布
Wrap mode：包裹模式，规尺贴在模型表面
Alpha菜单下选择一个alpha图案，点击make st可以将当前图案定义为规尺。我们可以制作黑白图像，保存成psd、jpg、bmp、tif等格式作为规尺使用。 注意jpg要24bit才能使用。
11、对称
Trans...菜单中，按下>x<、>y<、>z<，即可进行相应轴向上的镜像操作，如果>