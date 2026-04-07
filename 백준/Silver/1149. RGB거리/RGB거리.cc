#include <bits/stdc++.h>

using namespace std;

int n;
int mem[1002][3];


void precal() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mem[i][j];
            if (i == 0)continue;
            mem[i][j] +=
                    min(mem[i - 1][(j + 2) % 3],
                        mem[i - 1][(j + 4) % 3]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    precal();

    cout << min(mem[n - 1][0], min(mem[n - 1][1], mem[n - 1][2]));
}