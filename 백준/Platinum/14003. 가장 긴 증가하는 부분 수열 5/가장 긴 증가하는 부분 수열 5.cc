#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> in;
vector<int> tmp;
vector<int> pos;
vector<int> out;
string ans;

void init() {
    cin >> n;
    in.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        int cur = lower_bound(tmp.begin(), tmp.end(), in[i]) - tmp.begin();
        if (cur == tmp.size()) {
            tmp.emplace_back(in[i]);
        }
        tmp[cur] = in[i];
        pos[i] = cur;
    }
//    for(int v: pos){
//        cout << v << endl;
//    } // debug
    int tar = tmp.size() -1;
    for (int i = n - 1; i >= 0; i--) {
        if (pos[i] == tar) {
            out.push_back(in[i]);
            tar--;
        }
    }
    reverse(out.begin(),out.end());
    ans += to_string(tmp.size());
    ans += "\n";
    for(int v:out){
        ans += to_string(v);
        ans += " ";
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();
}
