#include <iostream>
//>=都是0
using namespace std;
int main(int argc, char *argv[]) {
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	int res = x + (~y + 1);
	int flag1 = x & (~y);
	int flag2 = (~(x ^ y)) & res;
	int m=(flag1 | flag2) >> 31 & 1;
	//if(m==0) printf(">");
	//if(m==) printf("=");
	//if(m==1) printf("<");
	printf("%d",m);
	return 0;
}