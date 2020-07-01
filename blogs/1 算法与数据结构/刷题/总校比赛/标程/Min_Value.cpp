#include <bits/stdc++.h>
using namespace std;

struct Data {
    int val, num;
} a[100001];

unordered_map<int, int> v;

bool flag1 = false, flag2 = false;

bool cmp(Data x, Data y) {
    if (abs(x.val) == abs(y.val)) {
        return x.num < y.num;
    }
    return abs(x.val) < abs(y.val);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].val;
        if (a[i].val > 0) flag1 = true;
        else if (a[i].val < 0) flag2 = true;
        a[i].num = i + 1;
        if (v.find(a[i].val) == v.end()) {
            v[a[i].val] = i + 1;
        }
    }
    sort(a, a + n, cmp);
    if (!flag2) {
        cout << abs(a[0].val + a[1].val) << " " << a[0].num + a[1].num << endl;
    } else if (!flag1) {
        cout << abs(a[0].val + a[1].val) << " " << a[0].num + a[1].num << endl;
    } else {
        int mmin = 1 << 30;
        int sum = 0;
        for (int i = 1; i < n; i++) {
            if (abs(a[i].val + a[i - 1].val) < mmin) {
                mmin = abs(a[i].val + a[i - 1].val);
                sum = v[a[i].val] + v[a[i - 1].val];
            } else if (abs(a[i].val + a[i - 1].val) == mmin) {
                sum = min(sum, v[a[i].val] + v[a[i - 1].val]);
            }
        }
        cout << mmin << " " << sum << endl;
    }
    return 0;
}