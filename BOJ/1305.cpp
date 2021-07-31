#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size, result = 0;
    string adv;
    cin >> size >> adv;

    vector<int> failure(adv.size()); // 광고 문자열에 대한 실패함수
    for (int i = 1, j = 0; i < adv.size(); i++)
    {
        while (j > 0 && adv[i] != adv[j]) j = failure[j - 1];
        if (adv[i] == adv[j]) failure[i] = ++j;
    }

    result = size - failure[adv.size() - 1];
    cout << result;
    return 0;
}
