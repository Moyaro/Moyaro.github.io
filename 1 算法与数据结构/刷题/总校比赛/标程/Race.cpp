#include<bits/stdc++.h>
using namespace std;

int main() {
    int v1, v2, t, s, l;
    cin >> v1 >> v2 >> t >> s >> l;
    int sum1 = 0, sum2 = 0;
    int time = 0;
    while(sum1 < l && sum2 < l) {
        if(sum1 - sum2 >= t) {
            sum2 += s * v2;
            time += s;
        } else {
            time++;
            sum1 += v1;
            sum2 += v2;
        }
    }
    if (sum1 == sum2) {
        printf("Tie %d\n", time);
    } else if (sum1 > sum2) {
        printf("Ming %d\n", time);
    } else {
        printf("Hong %d\n", l / v2);
    }
    return 0;
}