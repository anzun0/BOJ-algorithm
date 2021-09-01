#include <bits/stdc++.h>
using namespace std;

string str;
int result;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;

    long long result = str[0] - '0';
    for (int i = 1; i < str.size(); i++) {
        int num = str[i] - '0';
        if (result <= 1 || num <= 1) {
            result += num;
        }
        else result *= num;
    }
    cout << result << '\n';
    return 0;
}