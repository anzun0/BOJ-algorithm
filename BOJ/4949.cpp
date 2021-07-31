#include <bits/stdc++.h>
using namespace std;

int main(void) {

    while(1) {
        string str;
        stack<char> s;

        getline(cin, str);
        if (str.length() == 1 && str[0] == '.') break;

        for (int i = 0; i < str.length(); i++) {

            if (str[i] == ')' && s.size() != 0 && s.top() == '(') {
                s.pop();
                continue;
            }
            else if (str[i] == ']' && s.size() != 0 && s.top() == '[') {
                s.pop();
                continue;
            }

            if (str[i] == '(' || str[i] == '[' || str[i] == ')' || str[i] == ']')
                s.push(str[i]);
        }

        if (s.empty())
            cout << "yes" << '\n';
        else {
            cout << "no" << '\n';
        }
    }
}