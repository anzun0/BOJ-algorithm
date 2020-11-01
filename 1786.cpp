#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int result = 0; // 나타나는 횟수
    vector<int> pos; // 나타나는 위치를 저장
    string S, W;
    getline(cin, S);
    getline(cin, W);

    vector<int> failure(W.size()); // 찾을 문자열에 대한 실패함수 생성(0으로 초기화)
    for (int i = 1, j = 0; i < W.size(); i++)
    {
        while (j > 0 && W[i] != W[j]) j = failure[j - 1]; // 실패함수값이 문자열 절반을 넘어설 경우에는 찾을 때까지 계속 반복
        if (W[i] == W[j]) failure[i] = ++j;
    }

    for (int i = 0, j = 0; i < S.size(); i++) // 문자열 전체를 순회
    {
        while (j > 0 && S[i] != W[j]) j = failure[j - 1];
        if (S[i] == W[j])
        {
            if (j == W.size() - 1) // 찾았다!
            {
                result++;
                pos.push_back(i - W.size() + 2);
                j = failure[j];
            }
            else j++; // 못 찾았으면 w를 한칸 미뤄서 다시 비교
        }
    }
    cout << result << '\n';
    for (int i = 0; i < pos.size(); i++)
        cout << pos[i] << '\n';
    return 0;
}
