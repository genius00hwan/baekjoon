#include <bits/stdc++.h>

using namespace std;

string str;

int l, r;
char a;
int q;
int arr[26][200'000];

void init() {
    cin >> str;
    int i = str[0] - 'a';
    arr[i][0]++;
    for (int j = 1; j < str.size(); j++) {
        for (int i = 0; i < 26; i++) {
            arr[i][j] = arr[i][j - 1];
        }
        i = str[j] - 'a';
        arr[i][j]++;
    }
}


void solve() {
    cin >> q;
    while (q--) {
        cin >> a >> l >> r;
        int i = a - 'a';
        cout << (l ? arr[i][r] - arr[i][l - 1] : arr[i][r]);
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}
