#include <bits/stdc++.h>

using namespace std;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int n;
struct student {
    int num;
    int prefers[4];
    int pn;
};

vector<student> stds;
student graph[21][21];

int point[5] = {0, 1, 10, 100, 1000};

struct seat {
    int r, c;
    int pc;
    int ec;

    bool operator()(seat s1, seat s2) {
        if (s1.pc == s2.pc) {
            if (s1.ec == s2.ec) {
                if (s1.r == s2.r) {
                    return s1.c > s2.c;
                }
                return s1.r > s2.r;
            }
            return s1.ec < s2.ec;
        }
        return s1.pc < s2.pc;
    }
};


bool oob(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n)return true;
    return false;
}

void init() {
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int a;
        cin >> a;
        student st = {a};
        for (int j = 0; j < 4; j++) {
            cin >> st.prefers[j];
        }
        stds.push_back(st);
    }

}

seat cntSeat(student st, int r, int c) {
    seat se = {r, c, 0, 0};
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (oob(nc, nr))continue;
        for (int p: st.prefers) {
            if (graph[nr][nc].num == p) {
                se.pc++;
            }
        }
        if (!graph[nr][nc].num) {
            se.ec++;
        }
    }
    return se;
}

void setSeat(student st) {
    priority_queue<seat, vector<seat>, seat> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j].num)continue;
            pq.push(cntSeat(st, i, j));
        }
    }
    seat se = pq.top();
    st.pn = se.pc;
//    cout << st.num << ":" << se.r << ',' << se.c << endl;
    while (!pq.empty()) {
        seat tmp = pq.top();
//        cout <<"   " <<tmp.r << ',' << tmp.c << ": like " << tmp.pc << ", empty " << tmp.ec << endl;
        pq.pop();
    }
    graph[se.r][se.c] = st;
    for (int i = 0; i < 4; i++) {
        int nr = se.r + dr[i];
        int nc = se.c + dc[i];
        if (oob(nc, nr))continue;
        for (int p: graph[nr][nc].prefers) {
            if (st.num == p) {
                graph[nr][nc].pn++;
            }
        }
    }
}

int cntPoint() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += point[graph[i][j].pn];
        }
    }
    return ans;
}

void solve() {
    for (student st: stds) {
        setSeat(st);
    }
    cout << cntPoint();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}