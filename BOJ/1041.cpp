#include <bits/stdc++.h>
using namespace std;

long long n, result;
int dice[6];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
    }

    if (n == 1) {
        sort(dice, dice + 6);
        for (int i = 0; i < 5; i++) {
            result += dice[i];
        }
    }
    else {
        int temp[3];
        temp[0] = min(dice[0], dice[5]);
        temp[1] = min(dice[1], dice[4]);
        temp[2] = min(dice[2], dice[3]);
        sort(temp, temp + 3);

        int min3 = temp[0] + temp[1] + temp[2];
        int min2 = temp[0] + temp[1];
        int min1 = temp[0];

        long long n3 = 4;
        long long n2 = (n - 1) * 4 + (n - 2) * 4;
        long long n1 = (n - 2) * (n - 2) + 4 * (n - 2) * (n - 1);

        result += min3 * n3;
        result += min2 * n2;
        result += min1 * n1;
    }
    cout << result << '\n';
}