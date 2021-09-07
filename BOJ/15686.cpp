#include <bits/stdc++.h>
using namespace std;

int n, m, result=1e9;
int arr[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;

int distance(int x1, int y1, int x2, int y2) {
    return abs(x2-x1) + abs(y2-y1);
}

int chickenDistance(vector<pair<int,int>> v) {
    int cityChickenDistance = 0;

    for (int i = 0; i < home.size(); i++) {
        int chickenDistance = 1e9;
        int hx = home[i].first;
        int hy = home[i].second;
        for (int j = 0; j < v.size(); j++) {
            int cx = v[j].first;
            int cy = v[j].second;
            int temp = distance(hx, hy, cx, cy);
            chickenDistance = min(chickenDistance, temp);
        }
        cityChickenDistance += chickenDistance;
    }
    return cityChickenDistance;
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
    vector<bool> brute(chicken.size(), 0);
    fill(brute.end() - m, brute.end(), true);

    do {
        vector<pair<int,int>> v;
        for (int i = 0; i < brute.size(); i++) {
            if (brute[i]) {
                int x = chicken[i].first;
                int y = chicken[i].second;
                v.push_back({x, y});
            }
        }
        result = min(result, chickenDistance(v));
    } while(next_permutation(brute.begin(), brute.end()));
    cout << result << '\n';
}