//https://blog.csdn.net/Hanpi_learnc/article/details/104838566
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct P{
	int left,right; //左右 
	
	bool operator<(const P &p){  //按左端点升序，右端点降序
		if(left!=p.left )  return left<p.left;
		if(right!=p.right)  return right>p.right;
		else return 1;
	}
};

P p[1000];
int N,T;
int al;//选取区间个数
int ii;//用来剪枝的
int a;

int F(int aa)   //找到p[ii] 后面第一个left大于aa的区间
{
	for(int i = ii ;i<N;i++)
	{
		if(p[i].left > aa)
		return i;
	}
	return N-1;
}

/*
void sortp(int x,int y)
{
	for(int i=x;i<y+1;i++)
	{
	for(int j=i;j<y;j++)
		{
			if(p[j].left > p[j+1].left)
			{
				P a = p[j];
				p[j] = p[j+1];
				p[j+1]  = a;
			}
			else if(p[j].left == p[j+1].left &&p[j].right<p[j+1].right)
			{
				P a = p[j];
				p[j] = p[j+1];
				p[j+1]  = a;
		//		cout<<"1"<<endl;
			}
		}
	}
}
*/

int find( int f )  //输入起点，返回下一个起点
{
	for(int i=0;i<N;i++)
	{
		if( f == p[i].left)
		{
			al++;
			ii =i;  //找到这个区间的索引 
	//		cout<<"选第"<<i<<endl;
			return p[i].right+1;
		}
	}
	return -1;
}

void cut( int l)   //剪断操作
{
	for(int i=ii;i<N;i++)
	{
		if(p[i].right > l && p[i].left < l)
		{
			p[i].left = l;
		}
	}
//	for(int i=0;i<N;i++)
//		cout<<p[i].left<<" "<<p[i].right<<" "<<endl;
	int c = F(a);
	//cout<<a<<"*"<<c<<endl;
//	cout<< "sort("<<ii<<","<<c<<")"<<endl;
	sort(p+ii,p+c+1);
//	for(int i=0;i<N;i++)
//		cout<<p[i].left<<" "<<p[i].right<<" "<<endl;
}


int main()
{
	while( scanf("%d %d",&N,&T) !=EOF){
	al=0;ii=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&p[i].left,&p[i].right);
	}
	sort(p,p+N);
//	for(int i=0;i<N;i++)
//		cout<<p[i].left<<" "<<p[i].right<<endl;
	if(p[0].left > 1)  {printf("-1\n");return 0;}
	a = find(1);
	cut(a);
	//cout<< a<<" * "<<ii<<endl;
	while(a != -1 )
	{
		if(a>T)  break;
		a = find(a);
	//	cout<<a<<endl;
		cut(a);
	//	cout<< a<<" ** "<<ii<<endl;
	}
	if( a == -1) {printf("-1\n");return 0;}
	else printf("%d\n", al);
	}
	return 0;
 } 
