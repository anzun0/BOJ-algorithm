#include <bits/stdc++.h>
using namespace std;

int max (int a, int b) {
    return a > b ? a : b;
}

int main() {
    int arr[10] = {0, };
    char str[1000000];
    int i, temp, ans;
    scanf("%s", str);

    int len = strlen(str);

    for (i = 0 ; i < len; i++) {
        temp = (int)str[i] - 48;
        arr[temp]++;
    }

    ans  = 0;
    for (i = 0; i < 10; i++) if (i != 9 && i != 6) ans = max(ans, arr[i]);

    ans = max((arr[6] + arr[9] + 1) / 2, ans);
    printf("%d\n", ans);


    return 0;
}
