#include <bits/stdc++.h>

using namespace std;

int n, k, ans;

vector<tuple<int,int,int>> edges;

int par[1001];

void init(){
    cin >> n >> k;
    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(c, a, b);
    }

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
void solve(){
    sort(edges.begin(),edges.end());
    for(auto e:edges){
        int w = get<0>(e);
        int from = get<1>(e);
        int to = get<2>(e);

        if(find(from )== find(to)) continue;

        merge(from, to);
        ans += w;
    }
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solve();
    return 0;
}