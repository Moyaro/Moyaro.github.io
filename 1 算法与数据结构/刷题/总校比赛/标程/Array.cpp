#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    while (cin >> x >> y) {
        if (!x && !y) {
            cout << 0 << endl;
        } else if (x > y || (x & 1) != (y & 1)) {
            cout << -1 << endl;
        } else if (x == y) {
            cout << 1 << endl;
        } else {
            if (x & ((y - x) / 2)) {
                cout << 3 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }
    return 0;
}