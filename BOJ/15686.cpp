#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

int calculateDistance(pair<int, int> p1, pair<int, int> p2) {
    int diff_x = abs(p1.first - p2.first);
    int diff_y = abs(p1.second - p2.second);

    return diff_x + diff_y;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) home.push_back({i, j});
            if (arr[i][j] == 2) chicken.push_back({i, j});
        }
    }

    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
    int ans = 0x7f7f7f7f;

    do {
        int dist = 0;
        for (auto h : home) {
            int temp = 0x7f7f7f7f;

            for (int i = 0; i < chicken.size(); i++) {
                if (brute[i] == 0) continue;
                temp = min(temp, calculateDistance(chicken[i], h));
            }
            dist += temp;
        }
        ans = min(ans, dist);
    } while(next_permutation(brute.begin(), brute.end()));
    cout << ans << '\n';
}