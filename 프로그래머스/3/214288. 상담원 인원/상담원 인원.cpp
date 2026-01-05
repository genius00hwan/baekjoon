#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if (a.first == b.first) return a.second > b.second; 
        return a.first > b.first;
    }
};

int n, k;
priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> mentees[6];
vector<vector<int>> mem; // mem[type][m] = type에 m명 배정했을 때 총 대기시간
int ans;
vector<int> pick;

int cal(int m, int type) {
    int ret = mem[type][m];
    if (ret != -1) return ret;

    auto pq = mentees[type];
    priority_queue<int, vector<int>, greater<int>> ends;
    for (int i = 0; i < m; i++) ends.push(0);

    int time = 0;

    while (!pq.empty()) {
        auto [start, duration] = pq.top();
        pq.pop();

        int earliestEnd = ends.top();
        ends.pop();

        if (earliestEnd > start) time += (earliestEnd - start);

        int newEnd = max(earliestEnd, start) + duration;
        ends.push(newEnd);
    }

    ret = time;
    return ret;
}

void init(int inputK, int inputN, vector<vector<int>> reqs) {
    k = inputK;
    n = inputN;

    for (int t = 0; t < 6; t++) {
        mentees[t] = priority_queue<pair<int,int>, vector<pair<int,int>>, cmp>();
    }

    for (int i = 0; i < (int)reqs.size(); i++) {
        int s = reqs[i][0];
        int d = reqs[i][1];
        int type = reqs[i][2] - 1;
        mentees[type].push({s, d});
    }
}

void dfs(int type, int spare, int curSum) {
    if (curSum >= ans) return;

    if (type == k - 1) {
        int total = curSum + cal(spare, type);
        ans = min(ans, total);
        return;
    }

    int mx = spare - k + type + 1;

    for (int i = 1; i <= mx; i++) {
        pick[type] = i;
        dfs(type + 1, spare - i, curSum + cal(i, type));
    }
}

int solution(int inputK, int inputN, vector<vector<int>> reqs) {
    init(inputK, inputN, reqs);

    mem.assign(k, vector<int>(n + 1, -1));

    ans = INT_MAX;
    pick.assign(k, 1);

    dfs(0, n, 0);

    return ans;
}
