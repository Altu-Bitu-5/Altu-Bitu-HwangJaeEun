//백준에서 자꾸 11%에서 틀려서 주석도 달아보고 문제를 해결하려고 했는데 모르겠습니다ㅠㅠ

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 뱀의 좌표 구조체
struct Point {
    int x, y;
};

int main() {
    //입력
    int N, K, L;
    cin >> N >> K;

    vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1; // 사과의 위치를 1로 표시
    }

    cin >> L;
    queue<pair<int, char>> moves;
    for (int i = 0; i < L; ++i) {
        int X;
        char C;
        cin >> X >> C;
        moves.push(make_pair(X, C));
    }

    vector<Point> snake; // 뱀의 위치 저장
    snake.push_back({1, 1}); // 뱀의 초기 위치 (1, 1)
    board[1][1] = -1; // 뱀의 위치를 -1로 표시

    int dx[4] = {0, 1, 0, -1}; // 상, 우, 하, 좌
    int dy[4] = {-1, 0, 1, 0};
    int direction = 1; // 초기 방향: 오른쪽

    int time = 0;
    int idx = 0;

    while (true) {
        time++;

        int nx = snake.front().x + dx[direction];
        int ny = snake.front().y + dy[direction];

        // 벽에 부딪히거나 자기 몸에 닿으면 종료
        if (nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] == -1) {
            cout << time << '\n';
            break;
        }

        snake.insert(snake.begin(), {nx, ny});

        // 사과를 먹지 않으면 꼬리 제거
        if (board[nx][ny] != 1) {
            board[snake.back().x][snake.back().y] = 0;
            snake.pop_back();
        } else {
            board[nx][ny] = -1; // 사과를 먹으면 뱀의 몸통으로 표시
        }

        // 방향 전환
        if (!moves.empty() && time == moves.front().first) {
            if (moves.front().second == 'L') {
                direction = (direction + 3) % 4; // 왼쪽으로 회전
            } else {
                direction = (direction + 1) % 4; // 오른쪽으로 회전
            }
            moves.pop();
        }

        // 뱀의 머리 위치 업데이트
        board[snake.front().x][snake.front().y] = -1;
    }

    return 0;
}
