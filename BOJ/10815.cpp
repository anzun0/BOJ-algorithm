#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
int n, m;
int card[MAX+1], num[MAX+1];

bool BinarySearch(int target, int len) {
    int start = 0;
    int end = len - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (card[mid] < target)
            start = mid + 1;
        else if (card[mid] > target)
            end = mid - 1;
        else
            return true;
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> card[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> num[i];
    sort(card, card + n);
    
    for(int i = 0; i < m; i++) {
        if (BinarySearch(num[i], n))
            cout << "1 ";
        else
            cout << "0 ";
    }
}
