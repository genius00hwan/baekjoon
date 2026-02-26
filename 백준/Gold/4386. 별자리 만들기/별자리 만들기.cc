#include <bits/stdc++.h>

using namespace std;

int n;
double ans;

priority_queue<tuple<double,int,int>,vector<tuple<double,int,int>>,greater<>> pq;
vector<pair<double,double>>loc;

int par[100'002];


void init(){
    cin >> n;
    for (int i = 0; i < n; i++){
        par[i] = i;
        double x,y;
        cin >> x >> y;
        loc.emplace_back(x,y);
    }
    for(int i=0;i<n;i++){
        auto p1 = loc[i];
        for(int j=i;j<n;j++){
            auto p2 = loc[j];
            double xd = abs(p1.first-p2.first);
            double yd = abs(p1.second - p2.second);
            double d = sqrt(xd*xd+yd*yd);
            pq.push({d,i,j});
        }
    }




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
        double w = get<0>(e);
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