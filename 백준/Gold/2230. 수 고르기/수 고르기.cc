#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n, m;
int l, r;
int ans;

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    std::sort(v.begin(), v.end());
    l = 0;
    r = 1;
    ans = v[n - 1] - v[0];
}


void solve() {
    while (r < n) {
        int diff = v[r] - v[l];
        if (diff < m) {
            r++;
            continue;
        }
        if (diff > m) {
            l++;
            ans = min(ans,diff);
        }
        if (diff==m){
            ans = diff;
            break;
        }
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
