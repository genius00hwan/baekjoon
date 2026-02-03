#include <bits/stdc++.h>
#define MX 11
using namespace std;
int N;
int popu[MX];
int totalSum;
vector<int> adj[MX];

void init() {
    cin >> N;
    totalSum = 0;
    for (int i = 0; i < N; i++) {
        cin >> popu[i];
        totalSum += popu[i];
    }

    for (int i = 0; i < N; i++) adj[i].clear();

    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int a;
            cin >> a;
            --a;
            adj[i].push_back(a);
        }
    }
}

bool isAdj(int mask) {
    if (mask == 0) return false;

    int start = -1;
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i)) {
            start = i;
            break;
        }
    }

    queue<int> q;
    bool vis[MX] = {false};
    vis[start] = true;
    q.push(start);

    int cnt = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!(mask & (1 << v))) continue;
            if (vis[v]) continue;
            vis[v] = true;
            cnt++;
            q.push(v);
        }
    }

    return cnt == __builtin_popcount((unsigned)mask);
}

int sum(int mask) {
    int s = 0;
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i)) s += popu[i];
    }
    return s;
}

int solve() {
    int full = (1 << N) - 1;
    int best = INT_MAX;

    for (int mask = 1; mask < full; mask++) {
        int other = full ^ mask;
        if (other == 0) continue;

        if (!isAdj(mask)) continue;
        if (!isAdj(other)) continue;

        int sumA = sum(mask);
        int diff = abs(sumA - (totalSum - sumA));
        best = min(best, diff);
    }

    if (best == INT_MAX) return -1;
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cout << solve();
    return 0;
}
