#include <bits/stdc++.h>

using namespace std;

#define MOD 10007
int n;
int mem[1002];

void init() {
    cin >> n;
    mem[0] = 1;
    mem[1] = 2;
}

int dp(int i) {
    if (mem[i] != 0)return mem[i];
    return mem[i] = (dp(i - 1) + dp(i - 2)) % MOD;
}

void solve() {
    cout << dp(n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}