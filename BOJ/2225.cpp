#include <iostream>
#define DIV 1000000000
long long dp[201][201];
int dmp(int n, int k)
{
    if (k == 0) return 0;
    if (k == 1) return 1;

    if (dp[n][k] != 0) return dp[n][k];

    int result = 0;
    for (int i = 0; i <= n; i++)
    {
        result += dmp(i, k - 1);
        result %= DIV;
    }
    dp[n][k] = result;

    return dp[n][k];
}
int main()
{
    int N, K;
    std::cin >> N >> K;

    std::cout << dmp(N, K);
}
