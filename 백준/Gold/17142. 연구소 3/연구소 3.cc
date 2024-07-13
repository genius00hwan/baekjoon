#include <bits/stdc++.h>

#define INF 987654321

using namespace std;
int n, m;
int graph[52][52];
int tmp[52][52];
int en;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int ans = INF;
struct node {
    int r;
    int c;
};
struct virus {
    node n;
    bool chk;
};

struct ele {
    node n;
    int dist;
};

vector<virus> v;
queue<ele> q;

bool outOfBound(int r, int c) {
    return (r < 0 || r >= n || c < 0 || c >= n);
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) {
                v.push_back({i, j, false});
            }
            if (graph[i][j] == 0) {
                en++;
            }
        }
    }

}

void bfs() {
    int time = 0;
    int cnt = 0;
    while (!q.empty()) {
        ele cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.n.r + dr[i];
            int nc = cur.n.c + dc[i];
            if (outOfBound(nr, nc))continue;
            if (graph[nr][nc] == 1)continue;
            if (tmp[nr][nc] != -1)continue;
            if (!graph[nr][nc]) {
                time = max(cur.dist + 1, time);
                cnt++;
            }
            tmp[nr][nc] = 1;
            q.push({nr, nc, cur.dist + 1});
        }
    }
    if (cnt == en) {
        ans = min(ans, time);
    }
}

void dfs(int idx, int num) {
    if (num == m) {
        memset(tmp, -1, sizeof(tmp));
        for (auto i: v) {
            if (!i.chk) continue;
            q.push({i.n, 0});
            tmp[i.n.r][i.n.c] = 0;
        }
        bfs();
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                cout << tmp[i][j] << ' ';
//            }
//            cout << endl;
//        }cout << endl;
        return;
    }
    if (idx >= v.size())return;
    v[idx].chk = true;
    dfs(idx + 1, num + 1);
    v[idx].chk = false;
    dfs(idx + 1, num);
}


void solve() {
    dfs(0, 0);
    if (ans == INF)cout << -1;
    else cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();
}