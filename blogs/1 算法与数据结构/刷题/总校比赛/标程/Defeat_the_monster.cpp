#include <bits/stdc++.h>
using namespace std;

int a[200001];
int n;
int ans = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int i = 0, j = 0;
    while (i <= j) {
        while (j < n && a[j] - a[i] <= 5) {
            j++;
        }
        j--;
        ans = max(ans, j - i + 1);
        if (j == n - 1) break;
        if (i == j) j++;
        i++;
    }
    cout << ans << endl;
    return 0;
}