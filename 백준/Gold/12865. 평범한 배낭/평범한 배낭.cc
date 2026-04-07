#include <bits/stdc++.h>

#define MX_W 100'002
#define MX_N 101

using namespace std;

int mem[MX_N][MX_W];
pair<int, int> items[MX_N];
int n, k;

int dp(int idx, int w) {
    if (idx == 0) return 0;

    if (mem[idx][w] != -1) return mem[idx][w];

    mem[idx][w] = dp(idx - 1, w);

    if (w >= items[idx].first) {
        mem[idx][w] = max(
                mem[idx][w],
                items[idx].second + dp(idx - 1, w - items[idx].first)
        );
    }

    return mem[idx][w];
}

void init() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        items[i] = {w, v};
    }

    memset(mem, -1, sizeof(mem));
}

void solve() {
    cout << dp(n, k) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}