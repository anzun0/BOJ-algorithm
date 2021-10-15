#include <bits/stdc++.h>
using namespace std;

int k;
deque<int> dq[4];
int rotation[4];
bool check[4];

void setRotationDir(int num, int dir) {
    rotation[num] = dir;
    check[num] = true;

    if (num - 1 >= 0 && !check[num-1]) {
        //왼쪽 톱니바퀴 검사
        if (dir == 0) setRotationDir(num - 1, 0);
        else if (dq[num][6] == dq[num-1][2]) setRotationDir(num - 1, 0);
        else setRotationDir(num - 1, -dir);
    }

    if (num + 1 < 4 && !check[num+1]) {
        //오른쪽 톱니바퀴 검사
        if (dir == 0) setRotationDir(num + 1, 0);
        else if (dq[num][2] == dq[num+1][6]) setRotationDir(num+1, 0);
        else setRotationDir(num+1, -dir);
    }
}

void rotate() {
    for (int i = 0; i < 4; i++) {
        if (rotation[i] == 0) continue;

        if (rotation[i] == 1) {
            // 시계 방향 회전
            int temp = dq[i].back();
            dq[i].pop_back();
            dq[i].push_front(temp);
        }
        else {
            // 반시계 방향 회전
            int temp = dq[i].front();
            dq[i].pop_front();
            dq[i].push_back(temp);
        }
    }
}

int getScore() {
    int score = 0;
    for (int i = 0; i < 4; i++) {
        if (dq[i][0] == 1) {
            score += pow(2, i);
        }
    }
    return score;
}

int main(void) {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            int x;
            scanf("%1d", &x);
            dq[i].push_back(x);
        }
    }

    cin >> k;
    int num, dir;

    while (k--) {
        cin >> num >> dir;
        memset(check, false, sizeof(check));
        setRotationDir(num - 1, dir);
        rotate();
    }
    cout << getScore() << '\n';
}