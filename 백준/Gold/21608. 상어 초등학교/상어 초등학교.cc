#include <bits/stdc++.h>

using namespace std;


int n;
int rd[4] = {0, 0, 1, -1};
int cd[4] = {1, -1, 0, 0};

struct student {
    int num;
    int prefers[4];
};

bool oob(int r, int c) {
    return (r < 0 || r >= n || c < 0 || c >= n);
}

struct seat {
    int r, c;
    int preferNum;
    int emptyNum;

    bool operator()(seat s1, seat s2) {
        if (s1.preferNum == s2.preferNum) {
            if (s1.emptyNum == s2.emptyNum) {
                if (s1.r == s2.r) {
                    return s1.c > s2.c;
                }
                return s1.r > s2.r;
            }
            return s1.emptyNum < s2.emptyNum;
        }
        return s1.preferNum < s2.preferNum;
    }
};

student classroom[21][21];

vector<student> students;

void init() {
    cin >> n;
    int m = n * n;
    for (int i = 0; i < m; i++) {
        int sn;
        cin >> sn;
        student tmp = {sn};
        for (int k = 0; k < 4; k++) {
            cin >> tmp.prefers[k];
        }
        students.push_back(tmp);
    }
}

bool contains(student st, int trg) {
    for (int arg: st.prefers) {
        if (arg == trg) {
            return true;
        }
    }
    return false;
}

seat scoreSeat(student st, int r, int c) {
    int numberOfEmptySeats = 0;
    int numberOfPreferStudents = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + rd[i];
        int nc = c + cd[i];
        if (oob(nr, nc))continue;
        if (!classroom[nr][nc].num) {
            numberOfEmptySeats++;
            continue;
        }
        if (contains(st, classroom[nr][nc].num)) {
            numberOfPreferStudents++;
        }
    }
    return {r, c, numberOfPreferStudents, numberOfEmptySeats};
}

void sit(student st) {
    priority_queue<seat, vector<seat>, seat> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (classroom[i][j].num) continue;
            pq.push(scoreSeat(st, i, j));
        }
    }
    seat s = pq.top();
    classroom[s.r][s.c] = st;
}

int score(int r, int c) {
    student st = classroom[r][c];
    int cnt = 0;
    int points[] = {0,1,10,100,1000};
    for (int i = 0; i < 4; i++) {
        int nr = r + rd[i];
        int nc = c + cd[i];
        if (oob(nr, nc))continue;
        if (contains(st, classroom[nr][nc].num))cnt++;
    }
    return points[cnt];
}

int agg() {
    int totalScore = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            totalScore += score(i, j);
        }
    }
    return totalScore;
}

//void debug() {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << classroom[i][j].num;
//        }
//        cout << endl;
//    }
//}

void solve() {
    for (student st: students) {
        sit(st);
    }
    cout << agg();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();
}