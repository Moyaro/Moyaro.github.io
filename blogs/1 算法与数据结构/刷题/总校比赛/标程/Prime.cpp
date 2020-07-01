#include <bits/stdc++.h>
using namespace std;

long long prime[10000001];
bool is_prime[10000001];
long long sum[10000001];
int num = 0;

int main() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 10000000; i++) {
        if (is_prime[i]) {
            prime[num++] = i;
        }
        for (int j = 0; j < num; j++) {
            if (prime[j] * i > 10000000) break;
            is_prime[prime[j] * i] = false;
            if (i % prime[j] == 0) break;
        }
    }

    for (int i = 1; i <= 10000000; i++) {
        sum[i] += sum[i - 1];
        if (is_prime[i]) sum[i] += 1;
    }

    int T, a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << endl;
    }
    return 0;
}
