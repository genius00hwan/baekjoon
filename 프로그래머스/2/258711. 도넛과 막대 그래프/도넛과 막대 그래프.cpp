#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;


// 문제가 여러개의 그래프를 잇는 정점을 구하고 그래프의 수를 구하면 된다.
// 그럼 팔자그래프랑 도넛그래프를 구하고 직선 그래프를 구하는 방법만 도출을 하면된다.

int visit[1000001];
int Find[1000001];
vector<vector<int>> v;

int graph(int start) {
    queue<int> q;
    int vertex = 0;
    int edge = 0;
    q.push(start);
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        visit[n] += 1;
        vertex += 1;
        for (auto i: v[n]) {
            if (!visit[i] ) {
                q.push(i);
            }
            edge += 1;
        }
    }

    if (edge == vertex) {
        return 0;
    } else if (edge == vertex - 1) {
        return 1;
    } else {
        return 2;
    }
}

vector<int> solution(vector<vector<int>> edges) {
    v.resize(1000001);
    for (auto i: edges) {
        v[i[0]].push_back(i[1]);
    }
    int size = 0;
    for (auto i: v) {
        size++;
        for (auto j: i) {
            Find[j] = true;
        }
    }

    vector<int> answer;
    vector<int> start;
    for (int i = 1; i <= size; i++) {
        if (!Find[i]) {
            start.push_back(i);
        }
    }
    for (int i = 0; i < 4; i++) {
        answer.push_back(0);
    }
    int s = 0;
    if (start.size() != 1) {
        for (auto k: start) {
            if (v[k].size() > 1) {
                s = k;
            }
        }
    }
    answer[0]=s;
    for (auto i: v[s]) {
        if (!visit[i]) {
            int sol = graph(i);
            if (sol == 0) {
                answer[1] += 1;
            } else if (sol == 1) {
                answer[2] += 1;
            } else {
                answer[3] += 1;
            }
        }
    }


    return answer;
}


