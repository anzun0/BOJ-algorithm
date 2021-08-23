#include <bits/stdc++.h>
using namespace std;

int n, result;
vector<int> num;
vector<char> sign;
queue<char> signQueue;

void dfs(int k) {
    if (k == n) return;

    char _sign = signQueue.front(); signQueue.pop();
    if (_sign == '+') result = result + num[k];
    else if (_sign == '-') result = result - num[k];
    else if (_sign == '*') result = result * num[k];
    else if (_sign == '/') result = result / num[k];

    dfs(k+1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        num.push_back(val);
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < a; i++) sign.push_back('+');
    for (int i = 0; i < b; i++) sign.push_back('-');
    for (int i = 0; i < c; i++) sign.push_back('*');
    for (int i = 0; i < d; i++) sign.push_back('/');
    sort(sign.begin(), sign.end());

    int max_result = -1e9;
    int min_result = 1e9;
    do {
        for (auto s: sign) signQueue.push(s);
        result = num[0];
        dfs(1);
        max_result = max(max_result, result);
        min_result = min(min_result, result);
    } while (next_permutation(sign.begin(), sign.end()));
    cout << max_result << '\n' << min_result << '\n';
    return 0;
}