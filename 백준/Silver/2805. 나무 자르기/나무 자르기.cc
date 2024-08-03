#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> trees;
long long mn = INT_MAX;
long long mx;

long long count(long long h) {
    long long cnt = 0;
    for (int t: trees) {
        if (h <= t)
            cnt += t - h;
    }
    return cnt;
}

void init() {
    cin >> n >> m;
    while (n--) {
        long long w;
        cin >> w;
        trees.push_back(w);
        mn = min(mn, w);
        mx = max(mx, w);
    }
}

void solve() {
    long long s = 0;
    long long e = mx + 1;
    long long mid;
    long long ans = 0;
    while (s < e) {
        mid = (s + e) / 2;
        if (s == mid || e == mid) {
            ans = mid;
            break;
        }
        long long cnt = count(mid);
        if (cnt == m)
            ans = max(mid, ans);

        if (cnt >= m) s = mid;
        else e = mid;
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