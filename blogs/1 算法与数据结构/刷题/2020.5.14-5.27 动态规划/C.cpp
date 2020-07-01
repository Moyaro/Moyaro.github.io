#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int a[1010];
int dp[1010][40];
int main(int argc, char *argv[]) {
	/*int a[2][2]={1,2,3,4};
	printf("%d\n",a[-2][2]);
	printf("%d",a[1][3]);*/
	int t,w;
	cin>>t>>w;
	//int a[t];
	memset(a,0,sizeof(a));
	for(int m=0;m<t;m++)
	{
		cin>>a[m];
	}
	//int dp[t+1][w+2];	
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=t;i++)
	{
		dp[i][0]=0;
	}
	for(int j=0;j<=w+1;j++)
	{
		dp[0][j]=0;
	}	
	for(int i=1;i<=t;i++){
		for(int j=1;j<=w+2;j++){
			//if(i==1&&j==0&&a[0]==1) dp[1][0]
			
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);//判断的是前i-1棵树不超过j次时能够收集的最多的苹果,dp[1][0]的时候有bug应该再加一列护城河
			if(a[i-1]%2==(j%2)) dp[i][j]++;//如果这次选择对了，最优值++
			//c=!c;
			//if(j)
		}
	}
	//printf("%d",dp[3][1]);
	printf("%d",dp[t][w+1]);
	//dp[i][j]=max{dp[i-1][j],dp[i-1][j-1]};
}