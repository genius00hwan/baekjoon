#include <bits/stdc++.h>

#define ll long long
using namespace std;

vector<pair<int, int>> edges[100001];
ll dist[100'001];
bool visible[100'001];
int n, m;

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> visible[i];

    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        if ((visible[a] && a != n - 1) || (visible[b] && b != n - 1)) continue;
        edges[a].emplace_back(b, t);
        edges[b].emplace_back(a, t);
    }

    fill(dist, dist + n, LLONG_MAX);
}

void solve() {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        ll cd = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cd) continue;
        if (cur == n - 1) {
            cout << cd;
            return;
        }

        for (auto e: edges[cur]) {
            if (dist[e.first] > cd + e.second) {
                dist[e.first] = cd + e.second;
                pq.push({dist[e.first], e.first});
            }
        }
    }

    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solve();
}
