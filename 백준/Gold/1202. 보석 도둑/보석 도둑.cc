#include <bits/stdc++.h>

using namespace std;

int n, k;
struct jwl {
    long long weight;
    long long value;
};
long long ans;

struct cmp {
    bool operator()(jwl j1, jwl j2) {
        return j1.weight > j2.weight;
    }
};

struct cmp2 {
    bool operator()(jwl j1, jwl j2) {
        return j1.value < j2.value;
    }
};

priority_queue<jwl, vector<jwl>, cmp> jwls;
priority_queue<jwl, vector<jwl>, cmp2> tmp;

priority_queue<long long, vector<long long>, greater<>> bags;


void init() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        long long m, v;
        cin >> m >> v;
        jwls.push({m, v});
    }

    for (int i = 0; i < k; i++) {
        long long c;
        cin >> c;
        bags.push(c);
    }
}

void solve() {

    while (!bags.empty()) {
        long long bag = bags.top();
        bags.pop();
        while (!jwls.empty()) {
            jwl cur = jwls.top();
            if (cur.weight > bag)break;
            jwls.pop();
            tmp.push(cur);
        }

        if (!tmp.empty()) {
            ans += tmp.top().value;
            tmp.pop();
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}
