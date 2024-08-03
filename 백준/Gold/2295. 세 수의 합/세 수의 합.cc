#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> nums;
vector<int> sums;

void init() {
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
}


void solve() {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i; j < nums.size(); j++) {
            sums.push_back(nums[i] + nums[j]);
        }
    }
    sort(sums.begin(), sums.end());

    for (int i = nums.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (binary_search(sums.begin(), sums.end(), nums[i] - nums[j])) {
                cout << nums[i];
                return;
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}