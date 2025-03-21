//
// Created by 김수환 on 2022/09/06.
//
#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321
using namespace std;

int n, m, j, s;
int minDis = INF;
int minJ = INF;
int ans = -1;
vector<int> jDist;
vector<int> sDist;
vector<pair<int, int>> edges[1002];


void diijkstra(vector<int> &dist, int loc) {
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[loc] = 0;
    pq.push({0, loc});
    while (!pq.empty()) {
        int d = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for (auto edge: edges[now]) {
            int next = edge.first;
            int nd = edge.second + d;
            if (dist[next] > nd) {
                pq.push({-nd, next});
                dist[next] = nd;
            }
        }
    }
}


int main() {

    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }
    cin >> j >> s;
    jDist.resize(n + 1);
    sDist.resize(n + 1);
    diijkstra(jDist, j);
    diijkstra(sDist, s);

    for (int i = 1; i <= n; i++) {
        if (i == j || i == s) continue;
        minDis = (minDis > jDist[i] + sDist[i] ? jDist[i] + sDist[i] : minDis);
    }
    for (int i = 1; i <= n; i++) {
        if (i == j || i == s || jDist[i] > sDist[i]) continue;
        if (minDis == jDist[i] + sDist[i] && minJ > jDist[i])
            minJ = jDist[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i == j || i == s || jDist[i] > sDist[i]) continue;
        if (minDis == jDist[i] + sDist[i] && minJ == jDist[i]) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}