#include <bits/stdc++.h>

using namespace std;

int k, n;
vector<int> wires;
long long mn = INT_MAX;
long long mx;

long long count(long long l) {
    long long cnt = 0;
    for (int w: wires) {
        cnt += w / l;
    }
    return cnt;
}

void init() {
    cin >> k >> n;
    while (k--) {
        long long w;
        cin >> w;
        wires.push_back(w);
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
        if (cnt == n)
            ans = max(mid, ans);

        if (cnt >= n) s = mid;
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