#include <bits/stdc++.h>

using namespace std;

int n;
int s[21][21];
vector<int> a;
vector<int> b;
int ans;

void init() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> s[i][j];
    ans = INT_MAX;
}

void dfs(int idx) {
    if (idx > n) {
        if(a.empty()||b.empty()){
            return;
        }
        int ta = 0;
        int tb = 0;
        for(int v : a){
            for(int v2 : a){
                ta +=s[v-1][v2-1];
            }
        }
        for(int v : b){
            for(int v2 : b){
                tb +=s[v-1][v2-1];
            }
        }
        ans = min(ans,abs(ta-tb));
        return;
    }
    a.push_back(idx);
    dfs(idx + 1);
    a.pop_back();

    b.push_back(idx);
    dfs(idx + 1);
    b.pop_back();
}

void solve() {
    dfs(1);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    solve();

}
