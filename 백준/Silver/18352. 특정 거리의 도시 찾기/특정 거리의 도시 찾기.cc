#include <bits/stdc++.h>

#define N_MAX 300'002
using namespace std;
int n, m, k, x; // v개수, e개수, 기준값, 출발노드
vector<int> edges[N_MAX];
int dist[N_MAX];
vector<int> ans;

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
            if (dist[v] == k) {
                ans.push_back(v);
            }
        }
    }
}

void solve() {
    bfs();
    if (ans.empty()) cout << -1;

    std::sort(ans.begin(), ans.end());
    for (int v : ans) {
        cout << v << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}
