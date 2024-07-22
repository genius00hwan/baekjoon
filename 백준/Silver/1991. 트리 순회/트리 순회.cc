#include <bits/stdc++.h>

using namespace std;

int n;
struct node {
    int lc;
    int rc;
};

node arr[27];

void init() {
    cin >> n;
    while (n--) {
        char p, l, r;
        cin >> p >> l >> r;
        arr[p - 'A'] = {l - 'A', r - 'A'};
    }
}

char toChar(int c) {
    return c + 'A';
}

void preOrder(int cur) {
    if (toChar(cur) == '.')return;
    cout << toChar(cur);
    preOrder(arr[cur].lc);
    preOrder(arr[cur].rc);
}

void inOrder(int cur) {
    if (toChar(cur) == '.')return;
    inOrder(arr[cur].lc);
    cout << toChar(cur);
    inOrder(arr[cur].rc);
}

void postOrder(int cur) {
    if (toChar(cur) == '.')return;
    postOrder(arr[cur].lc);
    postOrder(arr[cur].rc);
    cout << toChar(cur);
}

void solve() {
    preOrder(0);
    cout << '\n';
    inOrder(0);
    cout << '\n';
    postOrder(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}