// 돌아올 수 있는 화살표를 가지고 있다면 팀을 구성할 수 있다!

#include <bits/stdc++.h>
using namespace std;
int student[100001];
bool vis[100001], members[100001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        queue<int> Q;
        vector<int> teamV;
        int n, cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> student[i];

        for (int i = 1; i <= n; i++)
        {
            Q.push(i); teamV.push_back(i);
            vis[i] = true;

            while (!Q.empty())
            {
                auto cur = Q.front(); Q.pop();
                int nxt = student[cur];
                if (vis[nxt]) {
                    for (int j = 0; j < teamV.size(); j++) {
                        if (teamV[j] == nxt) {
                            int end = nxt;
                            members[cur] = true;
                            while (student[nxt] != end) {
                                members[nxt] = true;
                                nxt = student[nxt];
                            }
                        }
                    }
                    teamV.clear();
                    continue;
                }
                Q.push(nxt); teamV.push_back(nxt);
                vis[nxt] = true;
            }
        }
        for (int i = 1; i <= n; i++)
            if (!members[i]) cnt++;
        cout << cnt << '\n';

        memset(members, false, sizeof(members));
        memset(vis, false, sizeof(vis));
        teamV.clear();
    }
    return 0;
}
