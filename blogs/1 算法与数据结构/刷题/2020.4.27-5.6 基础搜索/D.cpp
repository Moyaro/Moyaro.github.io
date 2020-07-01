#include <iostream>
//#include <stdio.h>//c中int getchar()//从标准输入设备写入一个字符int putchar()//向标准输出设备读出一个字符
	//int scanf(char*format[,argument…])//从标准输入设备读入格式化后的数据
	//int printf(char*format[,argument…])//向标准输出设备输出格式化字符串
	//char* gets(char*string)//从标准输入设备读入一个字符串
	//int puts(char*string)//向标准输出设备输出一个字符串
	//int sprintf(char*string,char*format[,…])//把格式化的数据写入某个字符串缓冲区
//#include <algorithm>//algorithm意为"算法",是C++的标准模版库（STL）中最重要的头文件之一，提供了大量基于迭代器的非成员模板函，https://blog.csdn.net/jiachang98/article/details/79170419
//#include <stdlib.h>//常用的函数如malloc()、calloc()、realloc()、free()、system()、atoi()、atol()、rand()、srand()、exit()等等，https://baike.baidu.com/item/stdlib.h/10370777?fr=aladdin

using namespace std;
int k,x;
bool judge(int n)
{
	if(n>x)
		return false;//递增函数，超过22后都不可能了
	if(n==x)
		return true;
	if(judge(2*n+1)||judge(3*n+1))//两种递归只要一种能为22，就符合情况
		return true;
	return false;
}
int main()
{
	char c;
	cin>>k>>c>>x;
	int n=k;
	bool f=judge(n);
	if(f==true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}


