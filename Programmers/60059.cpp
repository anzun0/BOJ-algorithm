// https://programmers.co.kr/learn/courses/30/lessons/60059
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> v) {
    int m = v.size();
    vector<vector<int>> temp(m, vector<int>(m));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            temp[j][m-i-1] = v[i][j];
        }
    }
    return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    int n = lock.size();
    int m = key.size();

    int keyCount = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (lock[i][j] == 0)
                keyCount += 1;

            for (int ro = 0; ro < 4; ro++) {
                key = rotate(key);

                for (int i = 1 - m; i < n; i++) {
                    for (int j = 1 - m; j < n; j++) {
                        int count = 0;
                        bool flag = true;

                        for (int r = i; r < i + m; r++) {
                            for (int c = j; c < j + m; c++) {
                                if (r < 0 || r >= n || c < 0 || c >= n) continue;

                                if (lock[r][c] == 1 && key[r-i][c-j] == 1) {
                                    flag = false;
                                    break;
                                }
                                if (lock[r][c] == 0 && key[r-i][c-j] == 1) count += 1;
                            }
                            if (!flag) break;
                        }
                        if (flag && count == keyCount) return true;
                    }
                }
            }
            return false;
}