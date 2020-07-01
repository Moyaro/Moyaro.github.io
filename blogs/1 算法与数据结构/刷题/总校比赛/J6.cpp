#include <iostream>

int cmp(unsigned int a, unsigned int b)	// a>b?1:0
{
#define _M (1 << 31)
	return (a^b) && 
		!(((a&_M) ^ (b&_M)) && (b&_M)) &&
		(((a&_M) ^ (b&_M) && a&_M) || cmp(a<<1, b<<1));
#undef _M
}

using namespace std;
int main(int argc, char *argv[]) {
	int x,y,a;
		scanf("%d",&x);
		scanf("%d",&y);
		if(x/y==1) cout<<"=";
		//if(!(x^y)) cout<<"=";
		else{
			a=cmp(x,y);
					//if(a==0) cout<<"=";
					if(a==0) cout<<"<";
					if(a==1)	cout<<">";
		}
}