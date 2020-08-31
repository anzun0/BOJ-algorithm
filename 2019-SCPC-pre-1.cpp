#include <bits/stdc++.h>
using namespace std;

int answer;
int dp[1000001];
int sum[1000001];

int main(void)
{
    dp[1] = 0; dp[2] = 1; dp[3] = 3; dp[4] = 2; dp[5] = 5; dp[6] = 4;
    for(int i=5;i<1000001;i++)
    {
        if(i%2==0)
            dp[i] = dp[i/2] + 1;
        else if(i%2==1)
            dp[i] = dp[i/2+1] + 2;
    }
    for(int i=1;i<1000001;i++)
        sum[i] = dp[i]+sum[i-1];
    
    int T;
    cin >> T;

    for(int test_case = 0; test_case < T; test_case++)
    {
        int n1, n2;
        cin >> n1 >> n2; // n1과 n2사이의 숫자들의 작업 횟수를 구한다.
        cout << "Case #" << test_case+1 << '\n' << sum[n2]-sum[n1-1]<<'\n';
    }
    return 0;
}
