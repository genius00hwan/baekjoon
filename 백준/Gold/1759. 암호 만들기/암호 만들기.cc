#include <bits/stdc++.h>

using namespace std;

char candi[15];
char aeiou[] = {'a', 'e', 'i', 'o', 'u'};
int L, C;
set<string> ans;

void init() {
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> candi[i];
    }
    sort(candi, candi + C * sizeof(char));
}

bool isValid(string str) {
    int cnt = 0;
    for (char c: str) {
        for (char i: aeiou) {
            if (c == i)cnt++;
        }
    }
    if (cnt >= 1 && L - cnt >= 2)return true;
    return false;
}

void dfs(string tmp, int cur) {
//    cout << tmp<< ' ';
    if (tmp.size() >= L) {
        if (isValid(tmp))
            ans.insert(tmp);
        return;
    }
    for (int i = cur; i < C; i++) {
        dfs(tmp + candi[i], i+1);
    }
}

void solve() {
    dfs("",0);
    for(string v:ans){
        cout << v <<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    solve();
}
