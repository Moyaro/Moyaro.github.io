#include <bits/stdc++.h>
using namespace std;

int a[100], num;

int main() {
    long long n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
    } else {
        while (n) {
            a[num++] = n % 2;
            n /= 2;
        }
        cout << (1LL << num) - 1 << endl;
    }
    return 0;
}