#include <bits/stdc++.h>
using namespace std;

typedef struct _button
{
    int color; // 현재 색상
    int left = 0, right = 0;
    // left는 좌측 버튼과 같은 색깔로 만드는 데 눌러야 하는 횟수
    // right는 우측 버튼과 같은 색깔로 만드는 데 눌러야 하는 횟수
}button;
vector<button> v;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, C; // N은 버튼의 수, C는 색의 수
    long long tempL = 0, tempR = 0;
    cin >> N >> C;

    for (int i = 0; i < N; i++)
    {
        v.push_back(button());
        int _color; cin >> _color;
        v[i].color = _color;

        if (i != 0)
        {
            int diff = v[i].color - v[i - 1].color;

            if (diff < 0) {
                v[i].left = abs(diff);
                v[i - 1].right = C - abs(diff);
            }
            else if (diff > 0) {
                v[i].left = C - diff;
                v[i - 1].right = diff;
            }
            else v[i].left = v[i - 1].right = 0;

            tempR += v[i - 1].right; // tempR은 첫번째 원소를 기준으로 오른쪽 끝까지의 거리
        }
    }
    int bnt = 1;
    long long cnt = max(tempL, tempR);
    for (int i = 1; i < N; i++)
    {
        tempL = tempL + v[i].left;
        tempR = tempR - v[i - 1].right;

        long long tempCnt = max(tempL, tempR);
        if (tempCnt < cnt) {
            cnt = tempCnt;
            bnt = i + 1;
        }
    }
    cout << bnt << '\n' << cnt;
    return 0;
}
