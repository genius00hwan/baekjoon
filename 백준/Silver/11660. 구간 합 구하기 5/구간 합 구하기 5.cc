#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[1100][1100];
int sum[1100][1100];
vector<pair<pair<int, int>, pair<int, int>>> targets;
string ans;

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        pair<pair<int, int>, pair<int, int>> t;
        cin >> t.first.first >> t.first.second >> t.second.first >> t.second.second;
        targets.emplace_back(t);
    }
}

bool oob(int r, int c) {
    return r < 0 || r >= n || c < 0 || c >= n;
}

int castSum(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n) return 0;
    return sum[r][c];
}

string solve() {
    sum[0][0] = graph[0][0];
    for (int i = 1; i < n; i++) sum[i][0] = sum[i - 1][0] + graph[i][0];
    for (int j = 1; j < n; j++) sum[0][j] = sum[0][j - 1] + graph[0][j];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + graph[i][j];


    for (auto tar: targets) {
        int sr = tar.first.first - 1;
        int sc = tar.first.second - 1;
        int er = tar.second.first - 1;
        int ec = tar.second.second - 1;
        ans += to_string(
                sum[er][ec]
                - castSum(er, sc - 1)
                - castSum(sr - 1, ec)
                + castSum(sr - 1, sc - 1)
                ) + '\n';
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    cout << solve();
}
