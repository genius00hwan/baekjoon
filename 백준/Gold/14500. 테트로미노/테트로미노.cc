#include<bits/stdc++.h>

using namespace std;
int n, m;
int graph[501][501];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
bool chk[501][501];
int ans;

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
}

bool oob(int r, int c) {
    return r < 0 || r >= n || c < 0 || c >= m;
}

void dfs(int r, int c, int cnt, int cur) {
    if (cnt == 4) {
        ans = max(ans, cur);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (oob(nr, nc)) continue;
        if (chk[nr][nc]) continue;
        chk[nr][nc] = true;
        dfs(nr, nc, cnt + 1, cur + graph[nr][nc]);
        chk[nr][nc] = false;
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            chk[i][j] = true;
            dfs(i, j, 1, graph[i][j]);
            chk[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)continue;
            if (i == n - 1 && j == m - 1)continue;
            if (i == 0 && j == m - 1)continue;
            if (i == n - 1 && j == 0)continue;
            int mn = 100001;
            int sm = graph[i][j];
            for (int d = 0; d < 4; d++) {
                int nr = i + dr[d];
                int nc = j + dc[d];
                if (oob(nr, nc)) {
                    mn = 0;
                    continue;
                }
                mn = (min(mn, graph[nr][nc]));
                sm += graph[nr][nc];
            }
            ans = max(ans, sm - mn);
        }
    }
    cout << ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(0);
    init();
    solve();
    return 0;
}