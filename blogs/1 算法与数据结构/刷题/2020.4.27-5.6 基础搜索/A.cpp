#include <iostream>//https://zhuanlan.zhihu.com/p/107441957 C++标准库
#include <math.h>//https://blog.csdn.net/yuleidnf/article/details/81541736
using namespace std;

int main(){
	int m,n,s=0;
	cin>>m>>n;
	if(m<n)
	{
		int k=0;
		k=m;
		m=n;
		n=k;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<min(i,n);j++){
			s++;
		}
	}
	printf("%d",s);
	return 0;
} 
