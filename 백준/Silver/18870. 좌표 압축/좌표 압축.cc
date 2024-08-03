#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;
map<int, int> res;


void init() {
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        nums.push_back(num);
        res[num] = 0;
    }
}

void solve() {
    int i = 0;
    for (auto &a: res) {
        a.second = i++;
    }

    for (int num: nums) {
        cout << res[num] << ' ';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}