//#include <iostream>
//题目：奶牛Bessie在0~N时间段产奶。农夫约翰有M个时间段可以挤奶，时间段[s,e]内Bessie能挤到的牛奶量gollon 奶牛产奶后需要休息R小时才能继续下一次产奶，求Bessie最大的挤奶量
/*样例输入
12 4 2 一共N个时间，其中M个时间段可挤奶，每头奶牛挤奶后需要休息R分钟
1 2 8 每个可挤奶的时间段的开始时间 结束时间 每次产奶的加仑数
10 12 19
3 6 24
7 10 31
输出 42

dp[i]=max(dp[i-1],dp[i-1]+T[i].gollon);//前i个时间段能够挤奶的最大值	？
}*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_M = 1005;

int N, M, R;

int dp[MAX_M];

struct times {
	int start;
	int end;
	int gollon;
} T[MAX_M];

bool cmp(times a, times b) {//比较方式
	return a.end < b.end;
}

int main() {
	int maxGollons = 0;
	scanf("%d %d %d", &N, &M, &R);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &T[i].start, &T[i].end, &T[i].gollon);
		T[i].end += R;
	}
	sort(T, T + M, cmp);//sort使用方法 https://www.cnblogs.com/junbaobei/p/10776066.html
	for (int i = 0; i < M; i++) {//对每个时间段进行遍历
		dp[i] = T[i].gollon;//默认这个时间段挤奶
		for (int j = 0; j < i; j++) {//遍历这个时间段之前的所有时间段
			if (T[j].end <= T[i].start) {//当之前那个时间段和当前时间段并行时，进行不断进行更新直至更新出当前区间挤奶的状态下最大的挤奶量
				dp[i] = max(dp[i], dp[j] + T[i].gollon);
			}
		}
		//maxGollons = max(maxGollons, dp[i]);//按顺序对每个时间段处理最后更新最大加仑数
	}
	
	printf("%d\n", maxGollons);
	return 0;
} 