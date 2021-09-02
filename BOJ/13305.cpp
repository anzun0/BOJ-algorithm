#include <bits/stdc++.h>
using namespace std;

long long n, result;
long long cost_now = 1e9;
long long cost[100000];
long long dist[100000];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> dist[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    for (int i = 0; i < n; i++) {
        if (cost[i] < cost_now) {
            cost_now = cost[i];
        }
        result += cost_now * dist[i];
    }
    cout << result << '\n';
}