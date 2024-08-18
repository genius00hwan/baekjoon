#include <bits/stdc++.h>

using namespace std;

struct node {
    int r, c, d;
};

int R, C, K, W;
int dc[4] = {1, 0, -1, 0};
int dr[4] = {0, 1, 0, -1};
int check[3] = {0, 1, 3};

bool chk[21][21];

int ans;
int graph[21][21];
int chg[21][21];
vector<node> fan;

int wll[4][21][21];
vector<pair<int, int>> loc;

void init() {
    cin >> R >> C >> K;


    int num;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> num;
            if (num == 5) loc.push_back({i, j});
            else if (num == 4) fan.push_back({i, j, 1});
            else if (num == 3) fan.push_back({i, j, 3});
            else if (num == 2) fan.push_back({i, j, 2});
            else if (num == 1) fan.push_back({i, j, 0});
        }
    }

    cin >> W;

    int r, c, t;
    for (int i = 0; i < W; i++) {
        cin >> r >> c >> t;
        r--;
        c--;
        if (t == 0) {
            wll[3][r][c] = true;
            wll[1][r - 1][c] = true;
        } else {
            wll[0][r][c] = true;
            wll[2][r][c + 1] = true;
        }
    }
}

void bfs(int r, int c, int d) {
    queue<pair<node, int>> q;
    memset(chk, false, sizeof chk);
    q.push({{r, c, d}, 5});
    chk[r][c] = true;

    while (!q.empty()) {
        node p = q.front().first;
        int deg = q.front().second - 1;
        q.pop();
        if (deg == 0) continue;

        for (int j = 0; j < 3; j++) {
            int nr = p.r;
            int nc = p.c;
            int nd = (p.d + check[j]) % 4;
            if (wll[nd][nr][nc]) continue;

            int cx = (j == 0) ? 0 : dr[nd];
            int cy = (j == 0) ? 0 : dc[nd];
            nr += cx;
            nc += cy;
            if ((nr < 0) || (nc < 0) || (nr >= R) || (nc >= C)) continue;
            if (wll[p.d][nr][nc]) continue;

            nr += dr[p.d];
            nc += dc[p.d];
            if ((nr < 0) || (nc < 0) || (nr >= R) || (nc >= C)) continue;
            if (chk[nr][nc]) continue;

            chk[nr][nc] = true;
            graph[nr][nc] += deg;
            q.push({{nr, nc, p.d}, deg});
        }
    }
}

void ctrlTmp() {
    memset(chg,0,sizeof chg);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int d = 0; d < 4; d++) {
                if (wll[d][i][j]) continue;

                int nr = i + dr[d];
                int nc = j + dc[d];
                if ((nr < 0) || (nc < 0) || (nr >= R) || (nc >= C)) continue;
                if (graph[i][j] <= graph[nr][nc]) continue;

                int diff = (graph[i][j] - graph[nr][nc]) / 4;
                chg[i][j] -= diff;
                chg[nr][nc] += diff;
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            graph[i][j] += chg[i][j];
    }
}

void decTmp() {
    for (int i = 0; i < R; i++) {
        if (graph[i][0] > 0) graph[i][0]--;
        if (graph[i][C - 1] > 0) graph[i][C - 1]--;
    }

    for (int i = 1; i < C - 1; i++) {
        if (graph[0][i] > 0) graph[0][i]--;
        if (graph[R - 1][i] > 0) graph[R - 1][i]--;
    }
}

void solve() {
    while (true) {
        for (int i = 0; i < fan.size(); i++) {
            int d = fan[i].d;

            int r = fan[i].r + dr[d];
            int c = fan[i].c + dc[d];
            graph[r][c] += 5;

            bfs(r, c, d);
        }

        ctrlTmp();

        decTmp();


        ans++;
        if (ans > 100) break;

        int flag = true;
        for (int i = 0; i < loc.size(); i++) {
            if (graph[loc[i].first][loc[i].second] < K) {
                flag = false;
                break;
            }
        }
        if (flag) break;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();

    return 0;
}
