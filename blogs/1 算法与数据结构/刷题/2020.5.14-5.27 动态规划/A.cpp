#include <iostream>
#include <algorithm>
using namespace std;

int a[360][360];
int dp[360][360];
int main(int argc, char *argv[]) {
	int t;
	int ans=0;
	cin>>t;
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<t;i++){
		for(int j=0;j<=i;j++){
			cin>>a[i][j];
		}
	}
	dp[0][0]=a[0][0];
	for(int i=1;i<t;i++){
		for(int j=0;j<=i;j++){
			if(j==0) dp[i][j]=dp[i-1][j]+a[i][j];
			if(0<j<i) dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i-1][j]+a[i][j]);
			if(j==i) dp[i][j]=dp[i-1][j-1]+a[i][j];
		}
	}
	for(int j=0;j<=t-1;j++) {
		ans=max(ans,dp[t-1][j]);
	}
	cout<<ans;
}