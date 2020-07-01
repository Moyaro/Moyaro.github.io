#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
#include <functional>

//要做的事情就是不断取出最小的两个点，好的那就涉及到题目所说的优先队列
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	priority_queue <int, vector<int>, greater<int> > q;//优先队列https://www.cnblogs.com/huashanqingzhu/p/11040390.html
	//https://blog.csdn.net/Annfan123/article/details/52201703?utm_source=blogxgwz6
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		q.push(a);//把数据入队列
	}
	long long res = 0;
	while (!q.empty()) {
		int tmp1 = q.top();
		q.pop();
		int tmp2 = q.top();
		q.pop();//将队列头两个出队列
		res = res + tmp1 + tmp2;//累计
		if (!q.empty()) q.push(tmp1 + tmp2);//队列非空时重新入队列
	}
	cout << res << endl;
	return 0;
}