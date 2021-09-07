// https://programmers.co.kr/learn/courses/30/lessons/60059
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> v) {
    int n = v.size();
    vector<vector<int>> temp(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n-i-1] = v[i][j];
        }
    }
    return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    int m = key.size();

    int lockCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lock[i][j] == 0) lockCount += 1;
        }
    }

    for (int r = 0; r < 4; r++) {
        key = rotate(key);

        for (int i = 1 - m; i < n; i++) {
            for (int j = 1 - m; j < n; j++) {

                int keyCount = 0;
                bool flag = true;

                for (int r = i; r < i + m; r++) {
                    for (int c = j; c < j + m; c++) {
                        if (r < 0 || r >= n || c < 0 || c >= n) continue;

                        if (lock[r][c] == 0 && key[r-i][c-j] == 1) keyCount += 1;
                        if (lock[r][c] == 1 && key[r-i][c-j] == 1) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (flag && lockCount == keyCount) return true;
            }
        }
    }
    return false;
}