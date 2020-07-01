#include<cstdio>
//https://www.cnblogs.com/CSLaker/p/7295047.html
int a[7];

int ans;

void solve() {
	ans += (a[4] + a[5] + a[6]);
	a[1] -= a[5] * 11;
	a[2] -= a[4] * 5;
	if (a[2] < 0) {
		a[1] += a[2] * 4;
	}
	ans += (a[3] / 4 + 1);
	switch (a[3] % 4) {
		case 0: {
			ans --;
			break;
		}
		case 1: {
			if (a[2] > 0) {
				a[2] -= 5;
				if (a[2] < 0) {
					a[1] += a[2] * 4;
				}
				a[1] -= 7;
			} else {
				a[1] -= 27;
			}
			break;
		} 
		case 2: {
			if (a[2] > 0) {
				a[2] -= 3;
				if (a[2] < 0) {
					a[1] += a[2] * 4;
				}
				a[1] -= 6;
			} else {
				a[1] -= 18;
			}
			break;
		}
		case 3: {
			if (a[2] > 0) {
				a[2] -= 1;
				a[1] -= 5;
			} else {
				a[1] -= 9;
			}
			break;
		}
	}
	if (a[2] > 0) {
		ans += a[2] / 9;
		if (a[2] % 9 > 0) {
			ans ++;
			a[1] -= (9 - a[2] % 9) * 4;			
		}
	}
	if (a[1] > 0) {
		ans += (a[1] + 35) /36;
	}
	printf("%d\n", ans);
}

int main () {
	while (1) {
		ans = 0;
		for (int i = 1; i <= 6; i ++) {
			scanf("%d", &a[i]);
		}
		if (!a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6]) break;
		solve();
	}
	return 0;
}