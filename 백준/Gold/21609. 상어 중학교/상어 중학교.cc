#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans;
int graph[22][22];
int tmp[22][22];
bool chk[22][22];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
bool flag = true;


struct bg {
    int r, c;
    int bn;
    int rn;
};

struct compare {
    bool operator()(bg g1, bg g2) {
        if (g1.bn == g2.bn) {
            if (g1.rn == g2.rn) {
                if (g1.r == g2.r)
                    return g1.c < g2.c;
                return g1.r < g2.r;
            }
            return g1.rn < g2.rn;
        }
        return g1.bn < g2.bn;
    }
};

bool oob(int r, int c) {
    return (r < 0 || r >= n || c < 0 || c >= n);
}

void rotate() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[n - j - 1][i] = graph[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = tmp[i][j];
        }
    }
}

void gravity(int c) {
    for (int r = n - 2; r >= 0; r--) {
        if (graph[r][c] == -1)continue;
        if (graph[r][c] == -2)continue;
        int cr = r;
        int nr = cr + 1;
        if (oob(nr, c))continue;
        while (graph[nr][c] == -2) {
            graph[nr][c] = graph[cr][c];
            graph[cr][c] = -2;
            cr++;
            nr++;
            if (oob(nr, c))break;
        }
    }
}

bg bfs(int r, int c) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!graph[i][j])chk[i][j] = false;
        }
    }
    bg ret = {r, c, 1};

    queue<pair<int, int>> q;
    q.push({r, c});
    chk[r][c] = true;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (oob(nr, nc))continue;
            if (chk[nr][nc])continue;
            if (graph[nr][nc] && graph[nr][nc] != graph[r][c])continue;
            if (!graph[nr][nc])ret.rn++;
            q.push({nr, nc});
            chk[nr][nc] = true;
            ret.bn++;
        }
    }
    return ret;
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
}

void erase(bg f) {
    memset(chk, false, sizeof chk);

    queue<pair<int, int>> q;
    vector<pair<int, int>> v;

    q.push({f.r, f.c});
    chk[f.r][f.c] = true;
    v.emplace_back(f.r, f.c);
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (oob(nr, nc))continue;
            if (chk[nr][nc])continue;
            if (graph[nr][nc] && graph[nr][nc] != graph[f.r][f.c])continue;
            q.push({nr, nc});
            chk[nr][nc] = true;
            v.emplace_back(nr, nc);
        }
    }
    for (pair<int, int> p: v) {
        graph[p.first][p.second] = -2;
    }
}

void play() {
    priority_queue<bg, vector<bg>, compare> groups;
    memset(chk, false, sizeof chk);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chk[i][j])
                continue;
            if (graph[i][j] <= 0)
                continue;
            groups.push(bfs(i, j));
        }
    }
    if (groups.empty() || groups.top().bn <= 1) {
        flag = false;
        cout << ans;
        return;
    }

    bg f = groups.top();
    ans += f.bn * f.bn;
    erase(f);

    for (int j = 0; j < n; j++) {
        gravity(j);
    }

    rotate();

    for (int j = 0; j < n; j++) {
        gravity(j);
    }

}


void solve() {
    while (flag) {
        play();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}