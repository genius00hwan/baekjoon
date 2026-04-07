#include <bits/stdc++.h>

#define INF 1e9
#define MX 10'009

using namespace std;

int n, k, ans;
int coin[101];
int mem[MX];

void init() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    memset(mem, -1, sizeof(mem));

}

int dp(int x) {
    if (x == 0) return 0;
    if (x < 0) return INF;

    if (mem[x] != -1) return mem[x];

    mem[x] = INF;

    for (int i = 0; i < n; i++) {
        mem[x] = min(mem[x], dp(x - coin[i]) + 1);
    }

    return mem[x];
}

void solve() {
    ans = dp(k);
    if (ans >= INF) ans = -1;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    init();
    solve();

    return 0;
}