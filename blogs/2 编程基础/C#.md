.exe文件和编译过程中链接的dll文件是必须的
dll动态链接库，当程序使用dll时，使用较少的资源，当多个程序使用同一个函数库时，DLL 可以减少在磁盘和物理内存中加载的代码的重复量。
Program.cs 是程序的入口:就是一个程序运行时，最先运行的地方，这里包含Main函数，不管是Winform程序还是控制台，都有这个。
Form.cs 是用户对窗体的代码操作，里面通常有窗体事件。在这里写窗体的操作代码。
Form.Designer.cs 是Visual Studio对窗体的操作代码，最好不要来这里写代码，里面有窗体的系统规划代码。
partial关键字表示这个类被分到了不同的文件中，可以实现物理不同的但逻辑相同。

委托是一个对象，它知道如何调用一个方法
委托类型：定义了方法的返回类型和参数类型
委托实例：把方法赋值给委托变量时就定义了委托实例 
例如：main函数委托给Transformer委托类型的t委托实例来调用Square方法
作用：编写插件式方法：方法是在运行时才赋值给委托变量的
使用：可以直接将方法传递给委托，来实现委托的实例化！！！
多播委托
实例方法目标和静态方法目标 


System.Threading.Thread.Sleep(2000);当前休眠2秒
suspen()挂起当前线程。也可以指定挂起时间。
close() 关闭当前线程。

https://www.bilibili.com/video/av10044534?from=search&seid=10202333685977871429
https://www.baidu.com/s?ie=UTF-8&wd=%E5%8D%A1%E9%A9%AC%E5%85%8B%E7%9A%84%E5%A6%BB%E5%AD%90
https://blog.csdn.net/wkx18330698534/article/details/50879272
https://blog.csdn.net/WKX18330698534/article/details/50887804
https://www.bilibili.com/video/av59733329?p=2

foreach循环：https://www.cnblogs.com/mayhh/p/10523964.html