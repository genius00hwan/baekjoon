


#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;

bool bs(int num) {
    int s = 0;
    int e = arr.size();

    while (s < e) {
        int mid = (s + e) / 2;
        if (num == arr[mid])
            return true;

        if (num < arr[mid]) e = mid;
        else s = mid + 1;

    }
    return false;
}

void init() {
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

}

void solve() {
    cin >> m;
    while (m--) {
        int a;
        cin >> a;
        cout << bs(a) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}