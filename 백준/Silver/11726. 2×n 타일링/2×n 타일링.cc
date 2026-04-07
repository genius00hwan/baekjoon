#include <bits/stdc++.h>

using namespace std;

int n;
int mem[1002] = {1, 2,};


int dp(int i) {
    if (mem[i] != 0)return mem[i];
    return mem[i] = (dp(i - 1) + dp(i - 2)) % 10'007;
}

void solve() {
    cin >> n;
    cout << dp(n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    solve();
}