//#include<bits/stdc++.h>//万能头文件
#include "stdio.h"
#include<iostream>
using namespace std;
const int maxn=2000+5;
int n;
char c[maxn];
 
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>c[i];
	int l=0,r=n-1;
 
	while(l<=r)
	{
		bool left=false;
		for(int i=0;i+l<r;i++)
		{
			if(c[l+i]<c[r-i])
			{
				left=true;
				break;
			}
			else if(c[l+i]>c[r-i])
			{
				left=false;
				break;
			}
			//这种设计隐含了左右字符相等的情况
		}
		if(left)putchar(c[l++]);//putchar(ch) 将之前赋给ch的值作为字符打印出来
			else putchar(c[r--]);
	}
	//没考虑每行最多输出80个字符的情况
	cout<<endl;
}