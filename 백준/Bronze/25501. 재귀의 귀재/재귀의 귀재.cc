#include <bits/stdc++.h>

using namespace std;
int t;
string str;
int cnt;

void init() {
    cin >> str;
    cnt = 0;
}


bool isP(int b, int e) {
    cnt++;
    if (b >= e)return true;
    if (str[b] != str[e])return false;
    return isP(b + 1, e - 1);
}

void solve() {
    cout << isP(0, str.size() - 1) << " " << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        init();
        solve();
    }

}