#include <bits/stdc++.h>

using namespace std;

int n;
bool board[65][65];


void init() {
    cin >> n;
    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < input.size(); j++) {
            board[i][j] = (input[j] == '1');
        }
    }

}

void qt(int r, int c) {
    bool flag = true;
    for (int i = r; i < r + n; i++) {
        for (int j = c; j < c + n; j++) {
            if (board[r][c] == board[i][j]) continue;
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << board[r][c];
        return;
    }
    n /= 2;

    cout << '(';
    qt(r, c);
    qt(r, c + n);
    qt(r + n, c);
    qt(r + n, c + n);
    cout << ')';

    n *= 2;
}

void solve() {
    qt(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}