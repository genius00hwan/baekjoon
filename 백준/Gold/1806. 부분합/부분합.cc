#include<bits/stdc++.h>
using namespace std;
int n, s;
vector <int> v;
int ans;
void init() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    ans = INT_MAX;
}

void solve() {
    int start = 0;
    int end = 0;
    int sum = 0;
    while (start <= end) {
        if (sum >= s) {
            ans = min(ans, end - start);
            sum -= v[start++];
        }
        else if (end == n)break;
        else sum += v[end++];
    }
    if (ans >= 1000000)cout << 0;
    else cout << ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();


}