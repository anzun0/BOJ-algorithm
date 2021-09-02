#include <bits/stdc++.h>
using namespace std;

int result;
string str;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;
    string temp = "";
    bool flag = false; // minus 기호 등장 여부

    for (int i = 0; i <= str.size(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
            if (flag) result -= stoi(temp);
            else result += stoi(temp);
            temp = "";

            if (str[i] == '-') flag = true;
        }
        else temp += str[i];
    }
    cout << result << '\n';
    return 0;
}