#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[300][300];
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        memset(board, -1, sizeof(board));
        queue<pair<int, int>> Q;
        int l, x1, y1, x2, y2; // 체스판의 한 변의 길이
        cin >> l >> x1 >> y1 >> x2 >> y2;

        Q.push({ x1,y1 });
        board[x1][y1] = 0;
        while (!Q.empty())
        {
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (board[nx][ny] != -1) continue;
                Q.push({ nx,ny });
                board[nx][ny] = board[cur.X][cur.Y] + 1;
            }
        }
        cout << board[x2][y2] << '\n';
    }
    return 0;
}
