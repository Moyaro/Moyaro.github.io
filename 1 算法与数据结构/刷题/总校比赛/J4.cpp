#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	if(!(x^y)) cout<<"=";
	else{
			int res = x + (~y + 1);
			int flag1 = x & (~y);
			int flag2 = (~(x ^ y)) & res;
			int m=(flag1 | flag2) >> 31 & 1;
			if(m==0) cout<<">";
			if(m==1) cout<<"<";
	}
	return 0;
}