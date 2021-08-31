#include <bits/stdc++.h>
using namespace std;

int n;
int maxDP[3], minDP[3];
int input[3];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> maxDP[0] >> maxDP[1] >> maxDP[2];
    minDP[0] = maxDP[0]; minDP[1] = maxDP[1]; minDP[2] = maxDP[2];

    for (int i = 1; i < n; i++) {
        cin >> input[0] >> input[1] >> input[2];

        int temp_0 = maxDP[0];
        int temp_2 = maxDP[2];

        maxDP[0] = max(maxDP[0], maxDP[1]) + input[0];
        maxDP[2] = max(maxDP[1], maxDP[2]) + input[2];
        maxDP[1] = max({temp_0, maxDP[1], temp_2}) + input[1];

        temp_0 = minDP[0];
        temp_2 = minDP[2];

        minDP[0] = min(minDP[0], minDP[1]) + input[0];
        minDP[2] = min(minDP[2], minDP[1]) + input[2];
        minDP[1] = min({temp_0, minDP[1], temp_2}) + input[1];
    }
    int maxValue = max({maxDP[0], maxDP[1], maxDP[2]});
    int minValue = min({minDP[0], minDP[1], minDP[2]});
    cout << maxValue << ' ' << minValue << '\n';
    return 0;
}