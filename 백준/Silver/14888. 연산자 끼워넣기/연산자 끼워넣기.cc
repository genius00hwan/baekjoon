#include <bits/stdc++.h>

using namespace std;

int num[12];
int op[4];//+,-,*,/
int n;
int mini, maxi;

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];

    for (int i = 0; i < 4; i++)cin >> op[i];

    mini = INT_MAX;
    maxi = INT_MIN;
}


void solve(int cur, int idx) {
    if (idx == n - 1) {
        mini = min(mini, cur);
        maxi = max(maxi, cur);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (!op[i])continue;
        op[i]--;
        if (i == 0) // +
            solve(cur + num[idx + 1], idx + 1);
        else if (i == 1) // -
            solve(cur - num[idx + 1], idx + 1);
        else if (i == 2) // *
            solve(cur * num[idx + 1], idx + 1);
        else // /
            solve(cur / num[idx + 1], idx + 1);
        op[i]++;
    }
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve(num[0], 0);
    cout << maxi << '\n' << mini;
}