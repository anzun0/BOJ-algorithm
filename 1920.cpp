#include <bits/stdc++.h>
using namespace std;
int n, m; // n개의 수 안에 m개의 수가 각각 존재하는지
int a[100001];

int BinarySearch(int target, int len) {
    int st = 0;
    int end = len - 1;
    while(st<=end) {
        int mid = (st + end) / 2;
        if(a[mid] < target) st = mid + 1;
        else if (a[mid] > target) end = mid - 1;
        else return mid;
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    
    cin >> m;
    while(m--) {
        int t;
        cin >> t;
        if(BinarySearch(t, n) == -1) cout << "0\n";
        else cout << "1\n";
    }
}
