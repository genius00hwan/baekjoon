#include <bits/stdc++.h>

using namespace std;
int n, c;
int ans;
vector<int> v;


void init() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
}

void solve() {
    int s = 1;
    int e = v.back() - v.front() + 1;

    while (s < e) {
        int cnt = 1;
        int m = (s + e) / 2;
        int t = v.front();

        for (int i: v) {
            if (i - t >= m) {
                cnt++;
                t = i;
            }
        }

        if (cnt >= c) {
            ans = max(ans, m);
            s = m + 1;
        } else
            e = m;
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