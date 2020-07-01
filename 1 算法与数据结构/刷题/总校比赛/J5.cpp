#include <iostream>

using namespace std;
int compare(uint32_t a, uint32_t b) {
	uint32_t diff = a ^ b;
	if (!diff) return 0;
	
	// 001xxxxx -> 00100000
	diff |= diff >> 1;
	diff |= diff >> 2;
	diff |= diff >> 4;
	diff |= diff >> 8;
	diff |= diff >> 16;
	diff ^= diff >> 1;
	
	return a & diff ? 1 : -1;
}

int main(int argc, char *argv[]) {
	int x,y,a;
	scanf("%d",&x);
	scanf("%d",&y);

	a=compare(x,y);
	if(a==0) cout<<"=";
	if(a==-1) cout<<"<";
	if(a==1)	cout<<">";

	return 0;
}