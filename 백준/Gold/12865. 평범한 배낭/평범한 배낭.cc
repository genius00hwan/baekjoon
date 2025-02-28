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
        int w = items[i].first;
        int v = items[i].second;
        for (int j = 1; j <= k; j++) {
            if (j >= w) {
                mem[i][j] = max(mem[i - 1][j], v + mem[i-1][j - w]);
                continue;
            }
            mem[i][j] = mem[i - 1][j];
        }
    }

    cout << mem[n ][k] << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    solve();

}