#include <bits/stdc++.h>

using namespace std;

string input;
vector<string> v;
int ans = 0;

bool insert(char a, char b) {
    for (string &s: v) {
        if (s.back() == a) {
            s += b;
            return true;
        }
    }
    return false;
}

map<char, char> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    m['q'] = 'k';
    m['u'] = 'q';
    m['a'] = 'u';
    m['c'] = 'a';
    m['k'] = 'c';

    cin >> input;
    for (char c: input) {
        if (!insert(m[c], c)) {
            if (c == 'q') {
                v.push_back("q");
            }else{
                cout << -1;
                return 0;
            }
        }
    }
//    for (string s: v) {
//        cout << s << " ";
//    }
    for (string s: v) {
        if (s.size() % 5) {
            cout << -1;
            return 0;
        }
        ans++;
    }
    ans ? cout << ans : cout << -1;
}
