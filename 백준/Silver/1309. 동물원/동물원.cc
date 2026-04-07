#include <bits/stdc++.h>

#define MOD 9901

using namespace std;

using ll = long long;

ll mem[100001][2];
int n;

ll dp(int idx, int st) {
    if (mem[idx][st] != -1) return mem[idx][st];

    if (idx == 0) {
        if (st == 0) return mem[idx][st] = 1;
        return mem[idx][st] = 3;
    }

    if (st == 0) {
        return mem[idx][st] = dp(idx - 1, 1) % MOD;
    }

    return mem[idx][st] = (dp(idx - 1, 0) + 2 * dp(idx - 1, 1)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    memset(mem, -1, sizeof(mem));
    cout << dp(n - 1, 1) % MOD << '\n';
}