#include <bits/stdc++.h>

#define MOD 1'000'000'000

using namespace std;

int n;
long long mem[101][10];
long long ans;

long long dp(int len, int digit) {
    if (mem[len][digit] != -1) return mem[len][digit];

    if (len == 1) {
        if (digit == 0) return mem[len][digit] = 0;
        return mem[len][digit] = 1;
    }

    if (digit == 0) return mem[len][digit] = dp(len - 1, 1) % MOD;
    if (digit == 9) return mem[len][digit] = dp(len - 1, 8) % MOD;

    return mem[len][digit] = (dp(len - 1, digit - 1) + dp(len - 1, digit + 1)) % MOD;
}

void init() {
    cin >> n;
    memset(mem, -1, sizeof(mem));
}

void solve() {
    for (int i = 0; i < 10; i++) {
        ans = (ans + dp(n, i)) % MOD;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}