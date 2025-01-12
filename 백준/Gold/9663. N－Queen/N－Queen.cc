#include <iostream>
#include <algorithm>

#define MAX 20


using namespace std;
int xLoc[MAX];//인덱스는 y좌표, 값은 x좌표
int n, cnt;

bool checkX(int i, int x) {
    for (int j = 0; j < i; j++) {
        if (xLoc[j] == x || abs(xLoc[j] - x) == abs(j - i)) {
            return false;
        }
    }
    return true;
}

void ithQ(int i, int x) {
    if (i == n) {
        cnt++;
        return;
    }
    if (x == n) {
        return;
    }
    if (checkX(i, x)) {
        xLoc[i] = x;
        ithQ(i + 1, 0);
    }
    ithQ(i, x + 1);
}

int main() {
    cin >> n;
    ithQ(0, 0);
    cout << cnt;
}