//
// Created by 김수환 on 2022/09/02.
//
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
long long cnt, k;
vector<pair<int, pair<int, int>>> edges;
set<pair<int, int>> dmz;
int par[1000005];

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

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        int w;
        cin >> w;
        edges.push_back({w, {n, i % n}});
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dmz.insert({u % n, v % n});
    }
    for (int i = 1; i <= n; i++) {
        if (dmz.find({i % n, (i + 1) % n}) != dmz.end()) continue;
        if (dmz.find({(i + 1) % n, i % n}) != dmz.end()) continue;
        edges.push_back({0, {i % n, (i + 1) % n}});
    }
    reset();
    sort(edges.begin(), edges.end());
    for (auto edge: edges) {
        long long w = edge.first;
        int from = edge.second.first;
        int to = edge.second.second;

        if (find(from) != find(to)) {
            merge(from, to);
            cnt += w;
        }
    }
    if (m <= 1) cout << "YES" << '\n';
    else {
        if (cnt > k)
            cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}
