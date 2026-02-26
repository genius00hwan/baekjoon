#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
int mx;

priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

int par[100'002];

void init(){
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, a, b});
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
    while(!pq.empty()){
        auto e = pq.top();
        pq.pop();
        int w = get<0>(e);
        int from = get<1>(e);
        int to = get<2>(e);

        if(find(from )== find(to)) continue;

        merge(from, to);
        ans += w;
        mx = max(mx,w);
    }
    ans -= mx;
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solve();
    return 0;
}