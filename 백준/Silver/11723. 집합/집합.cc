#include <bits/stdc++.h>

using namespace std;
int t;
map<string, int> cmds;
int n;

void init() {
    cmds["add"] = 1;
    cmds["remove"] = 2;
    cmds["check"] = 3;
    cmds["toggle"] = 4;
    cmds["all"] = 5;
    cmds["empty"] = 0;

}

int input() {
    string cmd;
    cin >> cmd;
    return cmds[cmd];
}


void solve(int cmd) {
    int x;
    if (cmd == 0) {
        n = 0;
        return;
    }
    if (cmd == 1) {
        cin >> x;
        n = n | (1 << (x - 1));
        return;
    }
    if (cmd == 2) {
        cin >> x;
        n =  n & ~(1 << (x - 1));
        return;
    }
    if (cmd == 3) {
        cin >> x;
        cout << (bool)(n & (1 << (x - 1))) <<'\n';
        return;
    }
    if (cmd == 4){
        cin >> x;
        n = n ^ (1 << (x - 1));
        return;
    }
    if(cmd == 5){
        n = 0b1111'1111'1111'1111'1111;
        return;
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    init();
    while (t--) {
        solve(input());
    }

}