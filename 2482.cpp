#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000003;
int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K; // N은 색상환에 포함된 색의 개수, K는 선택할 색의 개수

    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = i; // K개 중 1개를 선택하는 경우의 수
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= K; j++)
        {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
            // i번째 원소까지를 기준으로 j개를 칠하는 경우의 수는
            // i번째 원소를 색칠하거나, 색칠하지 않거나
        }
    }

    dp[N][K] = (dp[N - 1][K] + dp[N - 3][K - 1]) % mod;
    cout << dp[N][K];

    return 0;
}
