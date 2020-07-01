#include <iostream>
//大数不行
using namespace std;
int sign(int n) {
	//返回n的符号，如果n为正/0，返回1；
	//n为负返回0——利用这个判断谁大谁小
	int t1 = n >> 31;
	int t2 = t1 & 1;
	int t3 = t2^1;//如果t2为1，t3为0；如果t2为0，t3为1；
	return t3;
}
 
int main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	int c = a - b;
	int sca = sign(c);
	int scb = sca^1; //如果sca为1，scb为0；如果sca为0，scb为1
	int m=a * sca + b * scb;
	if(m==a&&m==b) cout<<"=";
	if(m==a) cout<<">";
	if(m==b) cout<<"<";
	
	return 0;
}