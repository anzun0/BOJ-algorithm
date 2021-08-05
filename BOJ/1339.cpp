#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> words;
    map<char, int> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        words.push_back(str);
    }

    for (int i = 0; i < n; i++) {
        int digit = 1;
        for (int j = words[i].length() - 1; j >= 0; j--) {
            m[words[i][j]] += digit;
            digit *= 10;
        }
    }

    vector<pair<char, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    int ans = 0, num = 9;
    for (int i = 0; i < v.size(); i++) {
        ans += v[i].second * num;
        num -= 1;
    }
    cout << ans << '\n';
}