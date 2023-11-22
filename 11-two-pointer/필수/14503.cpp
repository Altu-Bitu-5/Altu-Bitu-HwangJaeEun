#include <iostream>
#include <vector>

using namespace std;

// 북, 동, 남, 서 방향을 나타내는 상수
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// 청소 상태를 나타내는 상수
const int CLEAN = 0;
const int WALL = 1;
const int CLEANED = 2;

int n, m; // 지도의 크기
vector<vector<int>> map; // 지도
int answer = 0; // 청소한 영역의 개수

void clean(int x, int y, int direction) {
    // 현재 위치 청소
    if (map[x][y] == CLEAN) {
        map[x][y] = CLEANED;
        answer++;
    }

    // 네 방향 탐색
    for (int i = 0; i < 4; ++i) {
        int nextDirection = (direction + 3 - i) % 4; // 현재 방향에서 왼쪽으로 회전
        int nx = x + dx[nextDirection];
        int ny = y + dy[nextDirection];

        // 왼쪽 방향에 아직 청소하지 않은 공간이 있다면 전진
        if (map[nx][ny] == CLEAN) {
            clean(nx, ny, nextDirection);
            return;
        }
    }

    // 네 방향 모두 청소가 이미 되어있거나 벽인 경우 후진
    int backwardDirection = (direction + 2) % 4;
    int nx = x + dx[backwardDirection];
    int ny = y + dy[backwardDirection];

    // 후진할 수 있으면 후진
    if (map[nx][ny] != WALL) {
        clean(nx, ny, direction);
    }
}

int main() {
    // 입력
    cin >> n >> m;
    map.resize(n, vector<int>(m));

    int startX, startY, startDirection;
    cin >> startX >> startY >> startDirection;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }

    // 연산
    clean(startX, startY, startDirection);

    // 출력
    cout << answer << '\n';

    return 0;
}
