#include <bits/stdc++.h>
using namespace std;

string str;
int count0, count1;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;
    if (str[0] == '0') count0 += 1;
    else count1 += 1;

    for (int i = 1; i < str.size(); i++) {
        if (str[i] != str[i-1]) {
            if (str[i] == '0') count0 += 1;
            else count1 += 1;
        }
    }
    cout << min(count0, count1) << '\n';
    return 0;
}