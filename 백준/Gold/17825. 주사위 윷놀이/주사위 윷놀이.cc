#include <bits/stdc++.h>

#define CMD_SZ 10
using namespace std;

class Node {
public:
    Node* blue= nullptr;
    Node* next = nullptr;
    int value = 0;
    Node(){}
    Node(int value){
        this->value = value;
    }
};

int ans;
int cmd[CMD_SZ];

Node nodes[33];
Node* horse[4];
Node* finishNode;

void init() {
    for (int i = 0; i < CMD_SZ; i++) {
        cin >> cmd[i];
    }
    // 둘레
    for (int i = 0; i <= 20; i++) {
        nodes[i] = Node(i * 2);
    }

    // 서쪽 분기 (13,16,19)
    nodes[21] = Node(13);
    nodes[22] = Node(16);
    nodes[23] = Node(19);

    // 남쪽 분기 (22,24)
    nodes[24] = Node(22);
    nodes[25] = Node(24);

    // 동쪽 분기 (28,27,26)
    nodes[26] = Node(28);
    nodes[27] = Node(27);
    nodes[28] = Node(26);

    // 북쪽 분기. 25포함 (25,30,35)
    nodes[29] = Node(25);
    nodes[30] = Node(30);
    nodes[31] = Node(35);

    // 도착
    nodes[32] = Node(0);
    finishNode = &nodes[32];

    for (int i = 0; i < 20; i++) {
        nodes[i].next = &nodes[i + 1];
    }
    nodes[20].next = finishNode;
    nodes[32].next = finishNode;

    // blue
    nodes[5].blue = &nodes[21];
    nodes[10].blue = &nodes[24];
    nodes[15].blue = &nodes[26];

    nodes[21].next = &nodes[22];
    nodes[22].next = &nodes[23];
    nodes[23].next = &nodes[29];
    nodes[24].next = &nodes[25];
    nodes[25].next = &nodes[29];
    nodes[26].next = &nodes[27];
    nodes[27].next = &nodes[28];
    nodes[28].next = &nodes[29];
    nodes[29].next = &nodes[30];
    nodes[30].next = &nodes[31];
    nodes[31].next = &nodes[20];
    for (int i = 0; i < 4; i++) {
        horse[i] = &nodes[0];
    }
}

Node* moveHorse(Node* cur, int dice) {
    if (cur == finishNode)
        return cur;


    if (dice > 0) {
        if (cur->blue != nullptr) cur = cur->blue;
        else cur = cur->next;
        dice--;
    }

    while (dice-- > 0 && cur != finishNode) {
        cur = cur->next;
    }
    return cur;
}

bool isChecked(int idx, Node* target) {
    if (target == finishNode) return false;
    for (int i = 0; i < 4; i++) {
        if (i == idx) continue;
        if (horse[i] == target) return true;
    }
    return false;
}

void dfs(int cur, int sum) {
    if (cur == CMD_SZ) {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (horse[i] == finishNode) continue;

        Node* now = horse[i];
        Node* nxt = moveHorse(now, cmd[cur]);

        if (isChecked(i, nxt)) continue;

        horse[i] = nxt;
        dfs(cur + 1, sum + nxt->value);
        horse[i] = now;
    }
}

void solve() {
    ans = 0;
    dfs(0, 0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();
    return 0;
}