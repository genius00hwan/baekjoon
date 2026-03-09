#include <bits/stdc++.h>

#define INF 14938;
using namespace std;

int dist[102][102];
int item[102];
int n, m, r;
int ans;

void init() {
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        cin >> item[i];
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    while (r--) {
        int a, b, i;
        cin >> a >> b >> i;
        dist[--a][--b] = i;
        dist[b][a] = i;
    }
}

void solve() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= m)
                tmp += item[j];
        }
        if (tmp > ans)
            ans = tmp;
    }
    cout << ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();
}
