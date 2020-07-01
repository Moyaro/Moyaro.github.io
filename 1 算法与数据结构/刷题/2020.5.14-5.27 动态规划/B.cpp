#include <iostream>

using namespace std;
int dp[1000001];
int main(int argc, char *argv[]) {
	int a;
	cin>>a;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=a;i++){
	if(i&1){//a为奇数
		dp[i]=dp[i-1];
	}else{
		dp[i]=dp[i-1]+dp[i/2]%1000000000;
	}}
	cout<<dp[a];
}