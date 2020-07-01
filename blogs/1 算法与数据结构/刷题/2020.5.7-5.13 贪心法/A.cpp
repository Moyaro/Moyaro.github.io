/* POJ3617 Best Cow Line */

#include <iostream>
 
using namespace std;
 
 
const int LEFT = 1;
const int RIGHT = 2;
 
const int MAXN = 2000;
char a[MAXN+1];
 
int test(char s[], int start, int end)
{
	while(start < end) {
		if(s[start] < s[end])
			return LEFT;
		else if(s[start] > s[end])
			return RIGHT;
 
		start++;
		end--;
	}
 
	return LEFT;
}
 
int main()
{
	int n;
 
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];//cin既不读取回车也不读取空格，不管个数都是等价的
	a[n] = '\0';
//如果你把代码夹在#ifdef DEBUG 和对应的 #endif 中间，那么这段代码只有在调试（DEBUG）下才会被编译。也就是说，如果你在RELEASE模式下，这些代码根本就不会存在于你的最终代码里头。
#ifdef DEBUG
	cout << a << endl;
#endif
 
	int start=0, end=n-1, count=0;
	for(int i=0; i<n; i++) {
		if(test(a, start, end) == LEFT)
			cout << a[start++];
		else
			cout << a[end--];
 
		if(++count == 80) {
			count = 0;
			cout << endl;
		}
	}
 
	return 0;
}