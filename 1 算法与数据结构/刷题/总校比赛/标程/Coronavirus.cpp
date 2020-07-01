#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1}, dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
int sx, sy, gx, gy;
int res[501][501];
typedef pair<int, int> P;
queue<P> que;
char a[501][501];

bool judge(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '*' && res[x][y] == -1) {
        int xx, yy;
        for (int i = 0; i < 8; i++) {
            xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == '*')
                return false;
        }
        return true;
    }
    return false;
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = -1;
            if (a[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    res[sx][sy] = 0;
    que.push(make_pair(sx, sy));
    P temp;
    while(!que.empty()) {
        temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            if (judge(temp.first + dx[i], temp.second + dy[i])) {
                res[temp.first + dx[i]][temp.second + dy[i]] = res[temp.first][temp.second] + 1;
                que.push(make_pair(temp.first + dx[i], temp.second + dy[i]));
                if (a[temp.first + dx[i]][temp.second + dy[i]] == 'E') {
                    printf("%d\n", res[temp.first + dx[i]][temp.second + dy[i]]);
                    return 0;
                }
            }
        }
    }
    printf("Impossible\n");
    return 0;
}