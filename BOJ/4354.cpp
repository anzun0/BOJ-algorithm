#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;

    while (1)
    {
        cin >> str;
        if (str.size() == 1 && str[0] == '.') return 0;

        vector<int> failure(str.size()); // 광고 문자열에 대한 실패함수
        for (int i = 1, j = 0; i < str.size(); i++)
        {
            while (j > 0 && str[i] != str[j]) j = failure[j - 1];
            if (str[i] == str[j]) failure[i] = ++j;
        }

        int word_size = str.length() - failure[str.length() - 1]; // 반복되는 단어의 길이
        if (str.length() % word_size == 0)
            cout << str.length() / word_size << '\n';
        else
            cout << 1 << '\n';
    }
    return 0;
}
