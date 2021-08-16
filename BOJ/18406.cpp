#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string inputData;
    getline(cin, inputData);
    int mid = inputData.size() / 2;

    int left = 0, right = 0;
    for (int i = 0; i < mid; i++)
        left += inputData[i];
    for (int i = mid; i < inputData.size(); i++)
        right += inputData[i];

    if (left == right) cout << "LUCKY" << '\n';
    else cout << "READY" << '\n';
}