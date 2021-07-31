#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N, K, doll[501];
    long double min = LLONG_MAX; // 적당히 아주 큰 수
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> doll[i];

    for (int i = 0; i <= N - K; i++)
    {
        for (int j = i + K - 1; j < N; j++) // K개 이상의 인형들 검사
        {
            long double avg = 0;

            for (int l = i; l <= j; l++)
                avg += doll[l];

            avg /= (long double)(j - i + 1); // 평균
            long double sd = 0;

            for (int l = i; l <= j; l++)
                sd += (doll[l] - avg) * (doll[l] - avg); // 분산

            sd /= (long double)(j - i + 1); // 표준 편차
            min = min > sd ? sd : min;
        }
    }

    cout.precision(11);
    cout << sqrt(min);
}
