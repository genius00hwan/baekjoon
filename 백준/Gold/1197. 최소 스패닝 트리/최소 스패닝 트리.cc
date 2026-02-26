//
// Created by 김수환 on 2022/08/30.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k, ans;
priority_queue<pair<int, pair<int, int>>> edges;
int par[10001];

void reset() {
    for (int i = 1; i <= n; i++)
        par[i] = i;

}

int find(int x) {
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    par[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    reset();

    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push({-c, {a, b}});
    }
    while (!edges.empty()) {
        int from = edges.top().second.first;
        int to = edges.top().second.second;
        int w = edges.top().first;
        edges.pop();

        if (find(from) != find(to)) {
            merge(from, to);
            ans -= w;
        }
    }
    cout << ans;
    return 0;
}