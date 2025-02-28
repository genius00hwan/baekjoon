#include <bits/stdc++.h>

using namespace std;

int mem[101][100'002];
pair<int, int> items[101]; // 무게,가치
int n, k;

void init() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        items[i] = make_pair(w, v);
    }

}

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            mem[i][j] = (j < items[i].first) ? mem[i - 1][j] : max(mem[i - 1][j],items[i].second + mem[i - 1][j - items[i].first]);
        }
    }

    cout << mem[n][k] << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    solve();

}