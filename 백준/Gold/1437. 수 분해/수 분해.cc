#include <bits/stdc++.h>

using namespace std;

#define MOD 10'007

int n;
int ans = 1;

void solve() {
    if (n <= 3) {
        cout << n;
        return;
    }

    while (n > 4) {
        n -= 3;
        ans *= 3;
        ans %= MOD;
    }
    ans *= n;
    ans %= MOD;
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    solve();
}