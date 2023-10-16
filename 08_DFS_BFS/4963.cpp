#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
    
int bfs(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if (nextX >= 0 && nextX < map.size() && nextY >= 0 && nextY < map[0].size() && map[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                q.push({nextX, nextY});
                visited[nextX][nextY] = true;
            }
        }
    }

    return 1;
}

int main() {
    int w, h;
    
    while (1) {
        cin >> w >> h;

        if (w == 0 && h == 0)
            break;

        vector<vector<int>> map(h, vector<int>(w, 0));
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        int rst = 0;  

        // 입력
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        // 연산
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j] && map[i][j]) {
                    rst += bfs(i, j, map, visited);
                }
            }
        }

        // 출력
        cout << rst << "\n";
    }

    return 0;
}

