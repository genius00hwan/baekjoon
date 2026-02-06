#include <bits/stdc++.h>

using namespace std;

int R, C;
int N;
vector<int> shops;
int d;

void init() {
    cin >> C >> R >> N;
    pair<int, int> in;
    for (int i = 0; i <= N; i++) {
        cin >> in.first >> in.second;
        int v = in.second;
        if (in.first == 2) {
            v = (2 * C) + R - v;
        } else if (in.first == 3) {
            v = (2 * C) + (2 * R) - v;
        } else if (in.first == 4) {
            v = C + v;
        }
        if (i == N) d = v;
        else shops.emplace_back(v);
    }
}

int calD(int c) {
    int l = min(c, d);
    int r = max(c, d);
    return min(r - l, (2 * R + 2 * C) - r + l);
}

int solve() {
    int ans = 0;
    for (auto v: shops) {
        ans += calD(v);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cout << solve();
}