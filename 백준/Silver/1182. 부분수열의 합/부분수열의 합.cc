#include <bits/stdc++.h>

using namespace std;

int n, s;
int arr[21];
int ans;

void init() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void dfs(int idx, int sum, int sz) {
    if (idx == n) {
        if (sum == s && sz > 0) {
            ans++;
        }
        return;
    }
    dfs(idx + 1, sum + arr[idx], sz + 1);
    dfs(idx + 1, sum, sz);
}

void solve() {
    dfs(0, 0, 0);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}