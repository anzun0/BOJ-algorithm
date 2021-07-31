#include <bits/stdc++.h>
using namespace std;

int arr[100][100];
int vis[100];
int n;

void dfs(int k) {
    for (int i = 0; i < n; i++) {
        if (arr[k][i] && !vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < n; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(i);
        
        for (int j = 0; j < n; j++)
            if (vis[j])
                arr[i][j] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}
