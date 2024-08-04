#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans;
int graph[21][21];
int tmp[21][21];
bool chk[21][21];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
bool flag = true;


struct bg {
    int r, c;
    int rn;
    vector<pair<int, int>> bs;


    bool operator()(bg g1, bg g2) {
        if (g1.bs.size() == g2.bs.size()) {
            if (g1.rn == g2.rn) {
                if (g1.r == g2.r)
                    return g1.c < g2.c;
                return g1.r < g2.r;
            }
            return g1.rn < g2.rn;
        }
        return g1.bs.size() < g2.bs.size();
    }
};

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == -2)cout << "x ";
            else cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

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
        if (graph[r][c] < 0)continue;
        int cr = r;
        int nr = cr + 1;
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
    bg ret = {r, c, 0};
    queue<pair<int, int>> q;
    q.push({r, c});
    chk[r][c] = true;
    ret.bs.emplace_back(r, c);
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
            ret.bs.emplace_back(nr, nc);
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

void play() {
    priority_queue<bg, vector<bg>, bg> groups;
    memset(chk, false, sizeof chk);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chk[i][j])continue;
            if (graph[i][j] <= 0)continue;
            groups.push(bfs(i, j));
        }
    }
    
    if (groups.empty() || groups.top().bs.size() <= 1) {
        flag = false;
        cout << ans;
        return;
    }

    bg f = groups.top();
    ans += f.bs.size() * f.bs.size();
    for (auto p: f.bs) {
        graph[p.first][p.second] = -2;
    }
//    print();

    for (int i = 0; i < n; i++) {
        gravity(i);
    }
//    print();

    rotate();
//    print();

    for (int i = 0; i < n; i++) {
        gravity(i);
    }
//    print();

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