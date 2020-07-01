#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long my_pow(long long a, long long n) {
    long long ans = 1;
    while(n) {
        if(n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
long long fact[2000001];
long long ifact[2000001];
long long C(long long n, long long m) {
    return (fact[n] * ifact[n - m] % mod) * ifact[m] % mod;
}
int main() {
    fact[0] = 1;
    ifact[0] = 1;
    for(int i = 1; i <= 2000000; i++) {
        fact[i] = fact[i - 1] * i % mod;
        ifact[i] = my_pow(fact[i], mod - 2);
    }
    int T;
    cin >> T;
    int a, b;
    while(T--) {
        cin >> a >> b;
        cout << C(a + b - 2, a - 1) << endl;
    }
    return 0;
}