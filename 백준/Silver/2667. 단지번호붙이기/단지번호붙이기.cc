#include <bits/stdc++.h>

using namespace std;

int n;
bool graph[26][26];
int dc[4] = {1, 0, -1, 0};
int dr[4] = {0, 1, 0, -1};
vector<int> ans;


void init() {
    cin >> n;
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            graph[i][j] = (str[j] == '1');
        }
    }

}

int bfs(int a, int b) {
    int cnt2 = 1;
    queue<pair<int, int>> q;
    q.push({a, b});
    graph[a][b] = false;
    while (!q.empty()) {
        int cc = q.front().first;
        int cr = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nc = cc + dc[i];
            int nr = cr + dr[i];
            if (nc < 0 || nc >= n || nr < 0 || nr >= n)continue;
            if (!graph[nc][nr])continue;
            q.push({nc, nr});
            graph[nc][nr] = false;
            cnt2++;
        }
    }
    return cnt2;
}

void solve() {
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!graph[i][j])continue;
            ans.emplace_back(bfs(i, j));
            cnt1++;
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt1 << '\n';
    for (int a: ans) {
        cout << a << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}