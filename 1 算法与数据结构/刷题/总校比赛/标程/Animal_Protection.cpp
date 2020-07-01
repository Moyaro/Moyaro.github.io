#include <bits/stdc++.h>
using namespace std;

long long n, m, ans;
const long long mod = 1000000007;
char mp[1005][1005];
long long f[3005];
long long a[3005];
long long s[3005], top = -1;

int main() {
    cin >> n >> m;
    a[m + 1] = -1;
    f[m + 1] = 0;
    for (long long i = 1; i <= n; i++) {
        cin >> &mp[i][1];
    }
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            if (mp[i][j] == 'O') {
                a[j] += 1;
            } else a[j] = 0;
        }
        top = -1;
        s[++top] = m + 1;
        for (long long j = m; j >= 1; j--) {
            while (a[s[top]] >= a[j]) top--;
            f[j] = ((s[top] - j) * a[j] + f[s[top]]) % mod;
            s[++top] = j;
            ans = (ans + f[j]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}