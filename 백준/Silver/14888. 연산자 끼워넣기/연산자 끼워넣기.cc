#include <bits/stdc++.h>

#define MIN -1'000'000'000
#define MAX 1'000'000'000
#define SUM 0
#define SUB 1
#define MUL 2
#define DIV 3

using namespace std;
int num[13];
vector<int> oper;
int n;
int minAns;
int maxAns;

void init() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int op;
    for (int i = SUM; i <= DIV; i++) {
        cin >> op;

        while (op--)oper.push_back(i);
    }

    minAns = MAX;
    maxAns = MIN;

}

void solve() {
    do {
        int cur = num[0];
        for (int i = 1; i < n; i++) {
            if (oper[i - 1] == SUM)cur += num[i];
            if (oper[i - 1] == SUB)cur -= num[i];
            if (oper[i - 1] == MUL)cur *= num[i];
            if (oper[i - 1] == DIV)cur /= num[i];
        }

        minAns = min(minAns, cur);
        maxAns = max(maxAns, cur);

    } while (next_permutation(oper.begin(), oper.end()));

    cout << maxAns << '\n' << minAns;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();

    return 0;
}
