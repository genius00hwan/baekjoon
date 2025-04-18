#include<bits/stdc++.h>

using namespace std;

const int MAX = 10001;
int N, M;
vector<pair<int, int>> graph[MAX];
int start, dest;

int dkstra() {
    vector<int> dist(N + 1, -1);
    priority_queue<pair<int, int>> pq; 
    pq.push({INT_MAX, start});

    dist[start] = INT_MAX;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (node == dest) return weight;

        for (auto& [next, w] : graph[node]) {
            int nextWeight = min(weight, w);
            if (dist[next] < nextWeight) {
                dist[next] = nextWeight;
                pq.push({nextWeight, next});
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    cin >> start >> dest;

    cout << dkstra() << "\n";

    return 0;
}
