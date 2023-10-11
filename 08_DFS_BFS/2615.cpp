#include <iostream>
#include <vector>
#include <stack>
#define MAX 19

using namespace std;

char board[MAX][MAX];
int moves[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
bool visited[MAX][MAX][4][2];

char dfs(int x, int y, int dir, char color, int count) {
    visited[x][y][dir][color - '1'] = true;
    int nextX = x + moves[dir][0];
    int nextY = y + moves[dir][1];

    if (nextX < 0 || nextX >= MAX || nextY < 0 || nextY >= MAX || board[nextX][nextY] != color) {
        if (count == 5) {
            return color;
        } else {
            return '0';
        }
    }

    return dfs(nextX, nextY, dir, color, count + 1);
}

vector<int> dfs(int n, int v, vector<vector<bool>> &edge) {
    vector<int> result;
    vector<bool> visited(n + 1, false);
    stack<int> s;

    s.push(v);
    visited[v] = true;
    result.push_back(v);

    while (!s.empty()) {
        int node = s.top();
        bool child = false;

        for (int i = 1; i <= n; i++) {
            if (edge[node][i] && !visited[i]) {
                child = true;
                s.push(i);
                visited[i] = true;
                result.push_back(i);
                break;
            }
        }
        if (!child) {
            s.pop();
        }
    }
    return result;
}

int main() {

    //입력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> board[i][j];
        }
    }

    //연산&출력
    bool found = false;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (board[j][i] != '0') {
                for (int dir = 0; dir < 4; dir++) {
                    if (!visited[j][i][dir][board[j][i] - '1']) {
                        char result = dfs(j, i, dir, board[j][i], 1);
                        if (result != '0') {
                            cout << board[j][i] << '\n' << j + 1 << ' ' << i + 1;
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        cout << 0;
    }

    return 0;
}
