#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;
vector<int> qs;
bool chk[100000];

void init() {
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cin >> m;
    while (m--) {
        int a;
        cin >> a;
        qs.push_back(a);
    }
    sort(arr.begin(), arr.end());
}

bool bs(int v,int s, int e) {
    int m = (s + e) / 2 ;
    if(chk[m])
        m++;
    if(chk[m])
        return false;
    chk[m] = true;
    if (m >= arr.size())
        return false;
    if (m < 0)
        return false;
    if (arr[m] == v)
        return true;
    if (v < arr[m])
        return bs(v, s, m);
    if (v > arr[m])
        return bs(v, m, e);
    return false;
}

void solve() {
    for (int q: qs) {
        cout << bs(q, 0, arr.size()) << '\n';
        memset(chk,0,sizeof(chk));
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}