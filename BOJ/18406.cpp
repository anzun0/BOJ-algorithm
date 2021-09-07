#include <bits/stdc++.h>
using namespace std;

string num;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> num;
    int left = 0, right = 0;

    int idx = num.size() / 2;
    for (int i = 0; i < idx; i++) left += (num[i] - '0');
    for (int i = idx; i < num.size(); i++) right += (num[i] - '0');

    if (left == right) cout << "LUCKY" << '\n';
    else cout << "READY" << '\n';
}