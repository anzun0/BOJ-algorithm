#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string str;
    stack<char> s;
    int result = 0;

    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')' && str[i-1] == '(') {
            s.pop();
            result += s.size();
        }
        else if (str[i] == ')' && str[i-1] != '(' && s.top() == '(') {
            s.pop();
            result++;
        }
    }
    cout << result << '\n';
}