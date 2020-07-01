#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define ME0(x) memset(x,0,sizeof(x))
//https://www.cnblogs.com/sky-stars/p/11057539.html
using namespace std;
pair<int,int> a[25];//硬币面值，数量
int use[25];//这个面值的硬币已经使用了多少
int n,c;//硬币种类，每周最少给多少钱
int main()
{
	cin>>n>>c;
	for(int i=1; i<=n; i++)
		cin>>a[i].first>>a[i].second;
	sort(a+1,a+1+n);
	int ans=0;//答案
	while(true)
	{
		ME0(use);//每次都归零
		int rest=c;//还有这么多钱没给奶牛
		for(int i=n; i>=1; i--)//从大到小
		{
			int tmp=min(rest/a[i].first,a[i].second);//这种类型的硬币能拿几个
			rest-=tmp*a[i].first;//还有多少钱没给奶牛
			use[i]=tmp;//这种硬币用了几个
		}
		if(rest)//还有钱没有发完
		{
			for(int i=1; i<=n; i++)//从小到大
			{
				if(a[i].second&&a[i].first>=rest)//这种硬币没有花完并且这种硬币的价值大于没有发完的钱
				{
					use[i]++;//这种硬币用了一个
					rest=0;//钱全部发给奶牛了
					break;
				}
			}
		}
		if(rest)//钱还没发完，即钱不够了，退出循环
			break;
		int minx=INF;
		for(int i=1; i<=n; i++)//从小到大
		{
			if(use[i])//这种硬币一周要用几个，可以算出剩余的硬币可以用多少周
				minx=min(minx,a[i].second/use[i]);
		}
		ans+=minx;
		for(int i=1; i<=n; i++)//把硬币的数量更新
		{
			if(use[i])
				a[i].second-=use[i]*minx;
		}
	}
	cout<<ans<<endl;
}