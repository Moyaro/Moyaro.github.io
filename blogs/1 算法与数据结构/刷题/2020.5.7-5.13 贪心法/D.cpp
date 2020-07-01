#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
 
using namespace std;
//https://www.cnblogs.com/songcf/p/3763650.html	
//https://blog.csdn.net/zhengnanlee/article/details/9613161
//B做在A右左=》B在A圆内，之后先判断下一个是否在上一个的圆内
struct point
{
	double left, right;
}p[2010], temp;
 
bool operator < (point a, point b)
{
	return a.left < b.left;
}
 
int main()
{
	int n;
	double r;
	int kase = 0;
	while (cin >> n >> r && (n || r))
	{
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			double a, b;
			cin >> a >> b;
			if (fabs(b) > r)//fabs()求浮点数的绝对值
			{
				flag = true;
			}
			else
			{
				p[i].left = a * 1.0 - sqrt(r * r - b * b);
				p[i].right = a * 1.0 + sqrt(r * r - b * b);
			}
		}
		cout << "Case " << ++kase << ": ";
		if (flag)
		{
			cout << -1 << endl;
		}
		else
		{
			int countt = 1;
			sort(p, p + n);
			temp = p[0];
			
			for (int i = 1; i < n; i++)
			{
				if (p[i].left > temp.right)
				{
					countt++;
					temp = p[i];
				}
				else if (p[i].right < temp.right)
				{
					temp = p[i];
				}
			}
			cout << countt << endl;
		}
	}
}