#include <bits/stdc++.h>

using namespace std;

int n, m;
int trains[100'002];

void init() {
    cin >> n >> m;
//    cout << bitset<21>(~(1 << 20)) << '\n';
}

void print() {
    for (int j = 0; j < n; j++) {
        cout << bitset<32>(trains[j]) << '\n';
    }
    cout << endl;
}

void solve() {
    int cmd;
    int i, x;
    while (m--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> i >> x;
            trains[i - 1] |= (1 << (x - 1));
        } else if (cmd == 2) {
            cin >> i >> x;
            trains[i - 1] &= ~(1 << (x - 1));
        } else if (cmd == 3) {
            cin >> i;
            trains[i - 1] = trains[i - 1] << 1;
            trains[i - 1] &= ~(1 << 20);
        } else {
            cin >> i;
            trains[i - 1] = trains[i - 1] >> 1;
        }

    }
    set<int> gone;
    for (int j = 0; j < n; j++) {
        gone.insert(trains[j]);
    }
    cout << gone.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}