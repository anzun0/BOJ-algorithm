//https://programmers.co.kr/learn/courses/30/lessons/60061
#include <bits/stdc++.h>
using namespace std;

int gi[101][101];
int bo[101][101];

bool check_gi(int x, int y, int n) {
    if (y == 0) return true;
    if (bo[x-1][y] && x > 0) return true;
    if (bo[x][y] && x < n) return true;
    if (gi[x][y-1]) return true;
    return false;
}

bool check_bo(int x, int y, int n) {
    if (gi[x][y-1]) return true;
    if (gi[x+1][y-1] && x < n) return true;
    if (bo[x-1][y] && bo[x+1][y] && x > 0 && x < n) return true;
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];

        if (b == 1) { //설치
            if (a == 0) { // 기둥
                if (check_gi(x, y, n))
                    gi[x][y] = 1;
            }

            if (a == 1) { // 보
                if (check_bo(x, y, n))
                    bo[x][y] = 1;
            }
        }

        if (b == 0) { //제거
            if (a == 0) { // 기둥
                bool flag = true;
                gi[x][y] = 0;

                if (y < n && gi[x][y+1] && !check_gi(x, y+1, n)) flag = false;
                if (x > 0 && y < n && bo[x-1][y+1] && !check_bo(x-1, y+1, n)) flag = false;
                if (y < n && bo[x][y+1] && !check_bo(x, y+1, n)) flag = false;

                if (!flag) gi[x][y] = 1;
            }

            if (a == 1) { // 보
                bool flag = true;
                bo[x][y] = 0;

                if (gi[x][y] && !check_gi(x, y, n)) flag = false;
                if (x < n && gi[x+1][y] && !check_gi(x+1, y, n)) flag = false;
                if (x > 0 && bo[x-1][y] && !check_bo(x-1, y, n)) flag = false;
                if (x < n && bo[x+1][y] && !check_bo(x+1, y, n)) flag = false;

                if (!flag) bo[x][y] = 1;
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (gi[i][j] == 1) answer.push_back({i, j, 0});
            if (bo[i][j] == 1) answer.push_back({i, j, 1});
        }
    }
    return answer;
}