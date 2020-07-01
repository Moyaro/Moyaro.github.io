#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define maxn 100005
//https://www.cnblogs.com/kkrisen/p/3208797.html
using namespace std;
struct cow{
	int time;
	int des;
}node[maxn];
bool cmp(cow a,cow b)
{
	double t1=a.des*1.0/(a.time*1.0);
	double t2=b.des*1.0/(b.time*1.0);
	if (t1>t2)
	return true;

	return  false;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		__int64 now=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d %d",&node[i].time,&node[i].des);
			now+=node[i].des;
		}
		sort(node,node+n,cmp);
		__int64 ans=0;
		//cout<<endl;
		for (int j=0;j<n-1;j++)
		{
			now-=node[j].des;
			ans+=now*node[j].time*2;
			   // cout<<node[j].time<<" "<<node[k].des<<endl;
		   // cout<<ans<<endl<<endl;
		}

		printf("%I64d\n",ans);
	}
	return 0;
}