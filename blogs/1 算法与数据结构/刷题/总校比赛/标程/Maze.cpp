#include <bits/stdc++.h>
using namespace std;

int n, m, q;
char s[3005][3005];
typedef pair<int, int> P;
queue<P> que;
int vis[3005][3005];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int sum = 0;

bool judge(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]) {
        return true;
    }
    return false;
}

void dfs(int x, int y) {
    int tx, ty;
    for (int i = 0; i < 4; i++) {
        tx = x + dx[i], ty = y + dy[i];
        if (judge(tx, ty) && s[x][y] != s[tx][ty]) {
            sum++;
            vis[tx][ty] = 1;
            que.push({tx, ty});
            dfs(tx, ty);
        }
    }
    return ;
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                que.push({i, j});
                vis[i][j] = 1;
                sum = 1;
                dfs(i, j);
                while (!que.empty()) {
                    vis[que.front().first][que.front().second] = sum;
                    que.pop();
                }
            }
        }
    }
    int a, b;
    while (q--) {
        cin >> a >> b;
        cout << vis[a - 1][b - 1] << endl;
    }
    return 0;
}