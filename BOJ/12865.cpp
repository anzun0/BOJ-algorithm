#include <bits/stdc++.h>
using namespace std;
int n, k; // n: 물품의 수, k: 버틸 수 있는 무게
int d[101][100001];
int w[101]; // weight
int v[101]; // value

int main(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    
    for (int i = 1; i <= n; i++) { // i번째 물건
        for (int j = 1; j <= k; j++) { // 가방 용량 j
            if (j >= w[i])
                d[i][j] = max(d[i-1][j], d[i-1][j-w[i]] + v[i]);
            else
                d[i][j] = d[i-1][j];
        }
    }
    cout << d[n][k] << '\n';
}
