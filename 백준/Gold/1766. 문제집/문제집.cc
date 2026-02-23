#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> indeg;
vector<int> ans;
priority_queue<int, vector<int>, greater<int>> pq;

void init(){
    cin >> n >> m;

    adj.resize(n+1);
    indeg.assign(n + 1, 0);

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
}

void solve(){
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        ans.push_back(cur);

        for (int nxt : adj[cur]) {
            if (!(--indeg[nxt])) pq.push(nxt);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solve();

    return 0;
}