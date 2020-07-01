/*
链接：https://ac.nowcoder.com/acm/contest/5929/J
来源：牛客网

有一天，老师交给多多一个简单的任务，比较两个十进制非负整数的大小。
由于两个数的位数过多，多多不确定自己的答案是否正确，请你给出正确的答案。
两个十进制非负整数分别是 a，b，如果 a > b 输出">"，a < b 输出"<"，a = b 输出"="。
输入描述:
输入包含两行，第一行输入a，第二行输入b (0 ≤ a ≤ 1010000，0 ≤ b ≤ 1010000)
输出描述:
输出一个字符 '>'、'<' 或者 '='，表示比较的结果
100
200
输出
<
*/
//位运算：https://www.cnblogs.com/yrjns/p/11246163.html
//https://blog.csdn.net/u011352234/article/details/51957940?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int a,b,c;
	scanf("%d",&a);
	scanf("%d",&b);
	c=a&b;//结果比大的小，比小的>=
	if(c<a) printf(">");
	if(c=a) printf("=");
	if(c>a) printf("<");
	return 0;
}