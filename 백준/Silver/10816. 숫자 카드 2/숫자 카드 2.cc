#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> cards;

void init() {
    cin >> n;
    while (n--) {
        int c;
        cin >> c;
        cards.push_back(c);
    }
    sort(cards.begin(), cards.end());

}

void solve() {
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        cout << upper_bound(cards.begin(), cards.end(), t)
                - lower_bound(cards.begin(), cards.end(), t) << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}