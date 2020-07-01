//https://blog.csdn.net/xyc1719/article/details/80042739
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int f[100100],cnt;//f[i]表示面值为i能否达到
int g[100100];
int a[110],c[110];//记录单个面值和数量
int main()
{
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	while(n!=0||m!=0)//如果n,m都等于0则跳出循环
		{
		cnt=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		memset(f,0,sizeof(f));//先都赋值为达不到
		memset(g,0,sizeof(g));//先默认不需要使用
		f[0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=m;j++)
				if(f[j]&&f[j+a[i]]==0&&j+a[i]<=m&&g[j]<c[i])//f[j]->只有当前状态成立，转移的状态才会成立
				{//f[j+a[i]]==0->减少更新，以使g[i]尽可能小，能到达更多的状态；
					f[j+a[i]]=1;
					g[j+a[i]]=g[j]+1;//此处可以用g[j][i]表示到状态j使用i物品最少个数，因为只与当前第i种物品有关，所以可以用滚动数组保存，以省一维空间。
				}
		for(int i=1;i<=m;i++)
			if(f[i])cnt++;//如果面值可以达到则可能数++
		cout<<cnt<<endl;
		scanf("%d%d",&n,&m);
	}
	return 0;
}