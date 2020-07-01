#include <bits/stdc++.h>
using namespace std;

char s[2000001];
int a[2000001];
int num = 0;
int n, m;
int len;
int temp;
bitset<805> t[20];

int main() {
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < m; i++) {
        cin >> len;
        for (int j = 0; j < len; j++) {
            cin >> temp;
            t[temp][i] = 1;
        }
    }
    bool flag = true;
    bitset<805> p;
    for (int i = 0; i < n; i++) {
        p <<= 1;
        p[0] = 1;
        p &= t[(s[i] - '0')];
        if (p[m - 1]) {
            a[num++] = i - m + 2;
            flag = false;
        }
    }
    if (flag) {
        cout << "Failed to win the prize" << endl;
    } else {
        int ans = 0;
        int i = 0;
        while (i < num) {
            ans++;
            int tt = a[i] + m;
            while (i < num && a[i] < tt) i++;
        }
        cout << ans << endl;
    }
    return 0;
}
