#include <bits/stdc++.h>

using namespace std;

int n, top, cnt, ans;
int graph[101][101];
bool safe[101][101];
bool chk[101][101];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};


bool oob(int r, int c) {
    return r < 0 || r >= n || c < 0 || c >= n;
}

void dfs(int r, int c) {
    chk[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (oob(nr, nc))continue;
        if (chk[nr][nc] || !safe[nr][nc]) continue;
        dfs(nr, nc);
    }
}

void init(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            top = max(top, graph[i][j]);
        }
    }
}

int solve(){
    for (int rain = 0; rain <= top; rain++) {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                chk[i][j] = false;
                safe[i][j] = (graph[i][j] > rain);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!safe[i][j]) continue;
                if (chk[i][j])continue;
                dfs(i, j);
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cout << solve();
    return 0;
}