#include <bits/stdc++.h>
using namespace std;

class Ball {
public:
    int m, s, d;
    Ball(int m, int s, int d) {
        this -> m = m;
        this -> s = s;
        this -> d = d;
    };
};

int N, M, K;
queue<Ball> arr[51][51];
queue<Ball> temp[51][51];

int ex[] = {-1, 0, 1, 0};
int ey[] = {0, 1, 0, -1};
int ox[] = {-1, 1, 1, -1};
int oy[] = {1, 1, -1, -1};

void getResult() {
    int result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            while (!arr[i][j].empty()) {
                result += arr[i][j].front().m;
                arr[i][j].pop();
            }
        }
    }
    cout << result << '\n';
}

pair<int, int> move(int x, int y, int s, int d) {
    if (d % 2 == 0) {
        d /= 2;
        while (s--) {
            x += ex[d];
            y += ey[d];
            if (x < 1) x = N;
            else if (x > N) x = 1;
            if (y < 1) y = N;
            else if (y > N) y = 1;
        }
        return {x, y};
    }
    if (d % 2 == 1) {
        d = (d - 1) / 2;
        while (s--) {
            x += ox[d];
            y += oy[d];
            if (x < 1) x = N;
            else if (x > N) x = 1;
            if (y < 1) y = N;
            else if (y > N) y = 1;
        }
        return {x, y};
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int x, y;
        int m, s, d;
        cin >> x >> y >> m >> s >> d;
        arr[x][y].push(Ball(m, s, d));
    }

    while (K--) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {

                while (!arr[i][j].empty()) {
                    Ball now = arr[i][j].front(); arr[i][j].pop();
                    pair<int, int> nextPos = move(i, j, now.s, now.d);
                    temp[nextPos.first][nextPos.second].push(now);
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (temp[i][j].empty()) continue;

                int massSum = 0, speedSum = 0, count = 0, dir;
                bool isOdd = false, isEven = false;

                while (!temp[i][j].empty()) {
                    Ball now = temp[i][j].front(); temp[i][j].pop();
                    massSum += now.m;
                    speedSum += now.s;
                    count += 1;
                    dir = now.d;
                    if (now.d % 2 == 0) isEven = true;
                    if (now.d % 2 == 1) isOdd = true;
                }

                if (count == 1) arr[i][j].push(Ball(massSum, speedSum, dir));
                if (count > 1) {
                    int mass = massSum / 5;
                    int speed = speedSum / count;
                    if (mass != 0) {
                        if (isOdd && isEven) {
                            for (int k = 1; k <= 7; k += 2) {
                                arr[i][j].push(Ball(mass, speed, k));
                            }
                        }
                        else {
                            for (int k = 0; k <= 6; k += 2) {
                                arr[i][j].push(Ball(mass, speed, k));
                            }
                        }
                    }
                }
            }
        }
    }
    getResult();
}