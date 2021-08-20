// https://programmers.co.kr/learn/courses/30/lessons/60061
#include <vector>
using namespace std;

bool gi[101][101] = {};
bool bo[101][101] = {};

bool check_gi(int x, int y, int n) {
    if (y == 0) return true;
    if (gi[x][y-1]) return true;
    if (x > 0 && bo[x-1][y]) return true;
    if (x < n && bo[x][y]) return true;
    return false;
}

bool check_bo(int x, int y, int n) {
    if (gi[x][y-1]) return true;
    if (x < n && gi[x+1][y-1]) return true;
    if (x > 0 && x < n && bo[x-1][y] && bo[x+1][y]) return true;
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];

        if (a == 0) {
            if (b == 1) {
                if (check_gi(x, y, n))
                    gi[x][y] = true;
            }

            if (b == 0) {
                bool can = true;
                gi[x][y] = false;;

                if (y < n && gi[x][y + 1] && !check_gi(x, y + 1, n)) can = false;
                else if (y < n && bo[x][y + 1] && !check_bo(x, y + 1, n)) can = false;
                else if (x > 0 && bo[x - 1][y + 1] && y < n && !check_bo(x - 1, y + 1, n)) can = false;

                if (!can) gi[x][y] = true;
            }
        }

        if (a == 1) {
            if (b == 1) {
                if (check_bo(x, y, n))
                    bo[x][y] = 1;
            }

            if (b == 0) {
                bool can = true;
                bo[x][y] = false;

                if (gi[x][y] && !check_gi(x, y, n)) can = false;
                if (x < n && gi[x+1][y] && !check_gi(x + 1, y, n)) can = false;
                else if (x > 0 && bo[x-1][y] && !check_bo(x - 1, y, n)) can = false;
                else if (x < n && bo[x+1][y] && !check_bo(x + 1, y, n)) can = false;

                if(!can) bo[x][y] = true;
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (gi[i][j]) {
                answer.push_back({ i, j, 0 });
            }
            if (bo[i][j]) {
                answer.push_back({ i, j, 1 });
            }
        }
    }
    return answer;
}