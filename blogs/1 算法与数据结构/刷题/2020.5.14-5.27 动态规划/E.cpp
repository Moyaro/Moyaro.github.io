//参考文章：https://www.cnblogs.com/longdouhzt/archive/2011/07/06/2098959.html
#include <iostream>
using namespace std;

const int MAXM = 2000 + 5;
const int MAXN = 26 + 5;

int n, m;
char str[MAXM] = {};
int cost[1000][2] = {};
int d[MAXM][MAXM] = {};

int main(){
	cin >> n >> m >> str;// 字符种类n，给定字符串的长度m，给定的字符串str
	for(int i=0; i<n; i++){//保存每种字符及其对应的增加和删除的代价
		char tmp;
		cin >> tmp;
		cin >> cost[tmp][0] >> cost[tmp][1];
	}
		//cout<<"1正常"<<endl;
		
	//dp[i][j]为i...j要变成回文串的最小代价,dp[i][j]=max(dp[i+1][j]+对最左边那个字符串进行操作的最小代价，dp[i][j-1]+对最右边那个字符串进行操作的最小代价)
	for(int gap=1; gap<m; gap++){//从2个长度开始遍历各种长度的字符串
		for(int s=0; s<m; s++){//遍历当前长度下不同字符开头的字符串的位置
			int e = s + gap;//e表示每种每种字符串最右边那个字符的位置
			if(e < m){//将串的范围限制下来
				if(str[s] == str[e]){//如果开头和末尾的字符相等
					d[s][e] = d[s+1][e-1];
					cout<<"d["<<s<<"]["<<e<<"]="<<d[s][e]<<endl;	//头铁~~！！！！明年你就升华了！大三大四多半人都不会，面试遇见都白瞎！				
				}else{
					
					int imin1 = ( cost[str[s]][0] < cost[str[s]][1] ? cost[str[s]][0] : cost[str[s]][1] );//选择删掉和增加最左边那个字符代价最小的那个，但到底是在左边删还是右边增加不需要考虑
					d[s][e] = d[s+1][e] + imin1;//对最左边的字符进行修改
					cout<<"d["<<s<<"]["<<e<<"]="<<d[s][e]<<endl;
					int imin2 = ( cost[str[e]][0] < cost[str[e]][1] ? cost[str[e]][0] : cost[str[e]][1] );//选择删掉和增加最右边那个字符代价最小的那个，但到底是在左边增加还是右边删不需要考虑										
					if(d[s][e] > d[s][e-1] + imin2)//如果对右边字符操作代价最小，那就操作右边的字符
						d[s][e] = d[s][e-1] + imin2;
					cout<<"d["<<s<<"]["<<e<<"]="<<d[s][e]<<endl;
				}				
			}
			//cout<<"间隔数为"<<gap<<" 被检字符串为前"<<s+1<<"情况下已经结束"<<endl;
		}
		//cout<<"··········间隔数为"<<gap<<"情况下已结束············"<<endl;
	}

	cout << d[0][m-1] << endl;

	return 0;
}
