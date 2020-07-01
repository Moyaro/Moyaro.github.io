#include"iostream"
#include"stdio.h"
#include"queue"
#include"algorithm"
using namespace std;
const int MAXN=50005;
//https://blog.csdn.net/weixin_34347651/article/details/93299983
//https://www.cnblogs.com/huangzzz/p/8847794.html
//https://www.cnblogs.com/acm-jing/p/9795226.html
struct Node
{
	int s,e,pos;
	friend bool operator<(Node a,Node b)
	{
		if(a.e==b.e) return a.s<b.s;
		return a.e>b.e;
	}
};
 
bool Cmp(Node a,Node b)//优先判断a的开始时间小于b的，当开始时间相等返回结束时间是否小于b
{
	if(a.s!=b.s)
		return a.s<b.s;//返回a的开始时间是否小于b的开始时间
	else
		return a.e<b.e;//但ab相等返回a是否小于b的结束时间
}
 
Node cows[MAXN];
priority_queue<Node>que;
int order[MAXN];//目标数组
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&cows[i].s,&cows[i].e);
			cows[i].pos=i;
		}
		sort(cows,cows+n,Cmp);
		que.push(cows[0]);
		order[cows[0].pos]=1;//order数组保存的是每个区间对应的数轴的序号
		for(int i=1;i<n;i++)
		{
			if(cows[i].s>que.top().e)//第一次运行时，优先队列中只有第一个区间，如果第二个区间的开始时间大于优先队列中的第一个区间的结束时间，此时可以放到同一个数轴
			{
				order[cows[i].pos]=order[que.top().pos];//order[1]=order[0]=1，这里直接对第二个区间在哪个数轴进行赋值
				que.pop();//把第一个区间出队列
				que.push(cows[i]);//把第二个区间入优先队列
			}
			else//放到两个数轴
			{
				que.push(cows[i]);//把第二个区间入优先队列
				order[cows[i].pos]=que.size();//order[1]=2
			}
		}
		cout<<que.size()<<endl;//用优先队列的最大规模作为数轴个数的最大值
		for(int i=0;i<n;i++)
		{
			cout<<order[i]<<endl;//依次输出每个区间所在的数轴
		}
	}
	return 0;
}