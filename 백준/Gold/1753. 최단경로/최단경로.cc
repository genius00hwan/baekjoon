#include <bits/stdc++.h>

#define INF INT_MAX
using namespace std;

int v, e, k;
vector<int> dist;
vector<pair<int, int>> edges[20005];
priority_queue<pair<int, int>> pq;


void diijkstra() {
    for (int i = 0; i < v; i++) {
        dist.emplace_back(INF);
    }
    dist[k] = 0;
    pq.push({0, k});
    while (!pq.empty()) {
        int cur = pq.top().second;
        int d = -pq.top().first;
        pq.pop();
        
        for (auto edge: edges[cur]) {
            int next = edge.first;
            int nd = d + edge.second;
            if (nd < dist[next]) {
                pq.push({-nd, next});
                dist[next] = nd;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> v >> e >> k;
    k--;
    while (e--) {
        int from, to, w;
        cin >> from >> to >> w;
        edges[from - 1].emplace_back(to - 1, w);
    }
    diijkstra();
    for (int d: dist) {
        if (d == INF)
            cout << "INF" << '\n';
        else
            cout << d << '\n';
    }
    return 0;
}