#include <bits/stdc++.h>

using namespace std;

int n, m;
long long arr[100'001];
int s;
long long sum, ans;

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i < m)sum += arr[i];
    }
    s = 0;
}


void solve() {
    ans = sum;
    for (int e = m; e < n; e++) {
        sum -= arr[s];
        sum += arr[e];
        s++;
        ans = max(ans,sum);
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
