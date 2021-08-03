#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    set<string> s;

    for (int i = 1; i <= str.length(); i++) {
        for (int j = 0; j <= str.length() - i; j++) {
            string subString = str.substr(j, i);
            s.insert(subString);
        }
    }
    cout << s.size() << '\n';
}