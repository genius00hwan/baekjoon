#include <bits/stdc++.h>

using namespace std;

int n;
int paper[129][129];
int color[2];


void init() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];
}

void div(int r, int c, int size) {
    int flag = paper[r][c];
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (flag == paper[i][j])continue;
            div(r, c, size / 2);
            div(r, c + size / 2, size / 2);
            div(r + size / 2, c, size / 2);
            div(r + size / 2, c + size / 2, size / 2);
            return;
        }
    }
    color[flag]++;
}

void solve() {
    div(0, 0, n);
    cout << color[0] << '\n' << color[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}