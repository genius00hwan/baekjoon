#include <bits/stdc++.h>

using namespace std;

pair<bool,bool> dfs(vector<int>& a, int l, int r) {
    if (l > r) return {true, false};
    int m = (l + r) / 2;
    auto L = dfs(a, l, m - 1);
    auto R = dfs(a, m + 1, r);

    bool hasOne = (a[m] == 1) || L.second || R.second;
    bool ok = L.first && R.first;
    if (a[m] == 0 && (L.second || R.second)) ok = false;
    return {ok, hasOne};
}

vector<int> bitsWithPadding(unsigned long long x) {
    vector<int> b;
    if (x == 0) b.push_back(0);
    else {
        vector<int> rev;
        while (x) { rev.push_back(x & 1ULL); x >>= 1ULL; }
        b.assign(rev.rbegin(), rev.rend());
    }
    int bits = (int)b.size();
    int len = 1;
    while (len < bits) len = len * 2 + 1;
    vector<int> a(len - bits, 0);
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> ans;
    ans.reserve(numbers.size());
    for (auto v : numbers) {
        vector<int> a = bitsWithPadding((long long)v);
        bool ok = dfs(a, 0, (int)a.size() - 1).first;
        ans.push_back(ok ? 1 : 0);
    }
    return ans;
}