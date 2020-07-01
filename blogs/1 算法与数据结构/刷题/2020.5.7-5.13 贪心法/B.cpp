//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[1010];
//简单的贪心，将点进行排序后然后从头开始找，当找到一个点i大于r后在从i-1开始寻找另一半r范围。不断地循环下去，直到i==n-1。题目中会出现重复的点，需要去除掉。
//正确理解输入输出示例
int main(){
	ios::sync_with_stdio(false);
	int r,n;
	while(cin>>r>>n&&r>=0&&n>=0){
		memset(a,0,sizeof(a));
		//# include <string.h> 
		//void *memset(void *s, int c, unsigned long n); http://c.biancheng.net/view/231.html
		//函数的功能是：将指针变量 s 所指向的前 n 字节的内存单元用一个“整数” c 替换，注意 c 是 int 型。s 是 void* 型的指针变量，所以它可以为任何类型的数据进行初始化。不用使用for进行定义了
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);//排序
		int temp=0,ans=0;
		while(temp<n){//从头遍历
			int s=a[temp++];//s保存当前变量的值，然后temp右移
			while(temp<n&&a[temp]<=s+r){
				temp++;//temp的最终结果是中心右边一个
			}
			//cout<<"::"<<ans<<endl;
			int cnt=a[temp-1];//cnt保存中心的值			
			while(temp<n&&a[temp]<=cnt+r){
				temp++;//temp的最终结果是中心右边一个
			}
			ans++;
			cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
