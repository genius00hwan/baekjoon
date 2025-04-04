#include <bits/stdc++.h>

#define N_MAX 300'002
using namespace std;
int n, m, k, x; // v개수, e개수, 기준값, 출발노드
vector<int> edges[N_MAX];
int dist[N_MAX];

void init() {
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }
    memset(dist, -1, sizeof dist);
}

void bfs() {
    queue<int> q;
    dist[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int v: edges[cur]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[cur] + 1;
            q.push(v);
        }
    }
}

void solve() {
    bfs();

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            cout << i << '\n';
            cnt++;
        }
    }
    if (!cnt)cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}
