// https://programmers.co.kr/learn/courses/30/lessons/60063
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int pos1X;
    int pos1Y;
    int pos2X;
    int pos2Y;
    Node(int pos1X, int pos1Y, int pos2X, int pos2Y) {
        this -> pos1X = pos1X;
        this -> pos1Y = pos1Y;
        this -> pos2X = pos2X;
        this -> pos2Y = pos2Y;
    }
};

vector<Node> getNextPos(Node pos, vector<vector<int>> board) {
    vector<Node> nextPos;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int dir = 0; dir < 4; dir++) {
        int pos1NextX = pos.pos1X + dx[dir];
        int pos1NextY = pos.pos1Y + dy[dir];
        int pos2NextX = pos.pos2X + dx[dir];
        int pos2NextY = pos.pos2Y + dy[dir];

        if (board[pos1NextX][pos1NextY] == 0 && board[pos2NextX][pos2NextY] == 0) {
            nextPos.push_back(Node(pos1NextX, pos1NextY, pos2NextX, pos2NextY));
        }
    }

    int hor[] = {-1, 1};
    if (pos.pos1X == pos.pos2X) { // 회전(로봇이 수평으로 놓인 경우)
        for (int dir = 0; dir < 2; dir++) {
            if (board[pos.pos1X + hor[dir]][pos.pos1Y] == 0 && board[pos.pos2X + hor[dir]][pos.pos2Y] == 0) {
                nextPos.push_back(Node(pos.pos1X, pos.pos1Y, pos.pos1X + hor[dir], pos.pos1Y));
                nextPos.push_back(Node(pos.pos2X, pos.pos2Y, pos.pos2X + hor[dir], pos.pos2Y));
            }
        }
    }

    int ver[] = {-1, 1};
    if (pos.pos1Y == pos.pos2Y) { // 회전(로봇이 수직으로 놓인 경우)
        for (int dir = 0; dir < 2; dir++) {
            if (board[pos.pos1X][pos.pos1Y + ver[dir]] == 0 && board[pos.pos2X][pos.pos2Y + ver[dir]] == 0) {
                nextPos.push_back(Node(pos.pos1X, pos.pos1Y, pos.pos1X, pos.pos1Y + ver[dir]));
                nextPos.push_back(Node(pos.pos2X, pos.pos2Y, pos.pos2X, pos.pos2Y + ver[dir]));
            }
        }
    }
    return nextPos;
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<int>> newBoard(n+2, vector<int>(n + 2, 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            newBoard[i+1][j+1] = board[i][j];

        queue<pair<Node, int>> q;
        vector<Node> visited;
        Node pos = Node(1, 1, 1, 2);
        q.push({pos, 0});
        visited.push_back(pos);

        while (!q.empty()) {
            Node pos = q.front().first;
            int cost = q.front().second;
            q.pop();

            if ((pos.pos1X == n && pos.pos1Y == n) || (pos.pos2X == n && pos.pos2Y == n)) return cost;

            vector<Node> nextPos = getNextPos(pos, newBoard);
            for (int i = 0; i < nextPos.size(); i++) {
                bool check = true;
                Node pos = nextPos[i];

                for (int j = 0; j < visited.size(); j++) {
                    if (pos.pos1X == visited[j].pos1X && pos.pos1Y == visited[j].pos1Y && pos.pos2X == visited[j].pos2X && pos.pos2Y == visited[j].pos2Y) {
                        check = false;
                        break;
                    }
                }

                if (check) {
                    q.push({pos, cost + 1});
                    visited.push_back(pos);
                }
            }
        }
        return 0;
}