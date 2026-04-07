#include <bits/stdc++.h>

#define MOD 9901

using namespace std;

using ll = long long;

ll mem[100001][2];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    mem[0][0] = 1;
    mem[0][1] = 3;

    for (int i = 1; i < n; i++) {
        mem[i][0] = mem[i - 1][1] % MOD;
        mem[i][1] = (mem[i - 1][1] * 2 + mem[i - 1][0]) % MOD;
    }
    cout << mem[n - 1][1] % MOD << endl;
}