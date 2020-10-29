#include <iostream>
int main()
{
    int N, dp[31];
    std::cin >> N;
    for (int i = 1; i <= N; i += 2)
        dp[i] = 0; // 홀수 길이는 불가능!

    dp[0]=1, dp[2] = 3; dp[4] = 11;

    for (int i = 6; i <= N; i += 2)
    {
        dp[i] = dp[i - 2] * dp[2];
        for (int j = 4; i - j >= 0; j += 2)
            dp[i] += dp[i - j] * 2;
    }

    std::cout << dp[N];
}
