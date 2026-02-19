#include <bits/stdc++.h>

#define MX 32001
using namespace std;

vector<int> taller[MX];
deque<int> ans;
bool chk[MX];
int n, m;

void init() {
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        taller[a].push_back(b);
    }
}

void dfs(int cur) {
    if (chk[cur]) return;
    chk[cur] = true;
    for (auto nxt: taller[cur]) dfs(nxt);
    ans.push_front(cur);
}

void sol() {
    for (int i = 1; i <= n; i++) {
        if (chk[i])continue;
        dfs(i);
    }
    for(auto a : ans) cout << a << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    sol();
    return 0;
}