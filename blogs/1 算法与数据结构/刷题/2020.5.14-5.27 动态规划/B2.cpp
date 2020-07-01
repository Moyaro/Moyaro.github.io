#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#define INF 0x3f3f3f
#define eps 1e-8
#define MAXN (1000000+1)
#define MAXM (100000)
#define Ri(a) scanf("%d", &a)
#define Rl(a) scanf("%lld", &a)
#define Rf(a) scanf("%lf", &a)
#define Rs(a) scanf("%s", a)
#define Pi(a) printf("%d\n", (a))
#define Pf(a) printf("%.2lf\n", (a))
#define Pl(a) printf("%lld\n", (a))
#define Ps(a) printf("%s\n", (a))
#define W(a) while(a--)
#define CLR(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define LL long long
#define lson o<<1, l, mid
#define rson o<<1|1, mid+1, r
#define ll o<<1
#define rr o<<1|1
using namespace std;
LL dp[MAXN];
void getdp()
{
	dp[0] = 1;
	for(int i = 1; i < MAXN; i++)
	{
		if(i & 1)
			dp[i] = dp[i-1];
		else
			dp[i] = (dp[i-1] + dp[i >> 1]) % 1000000000;
	}
}
int main()
{
	getdp();
	int n; Ri(n); Pl(dp[n]);
	return 0;
}