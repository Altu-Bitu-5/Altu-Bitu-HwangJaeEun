#include <iostream>     // 표준 입력 출력 스트림을 사용
#include <vector>       // 벡터 컨테이너 사용
#include <deque>        // 덱 컨테이너 사용
#include <map>          // 맵 컨테이너 사용

using namespace std;    // 표준 네임스페이스 사용

typedef pair<int, int> ci; // 두 정수의 쌍을 나타내는 데이터 타입 정의

const int EMPTY = 0;    // 빈칸
const int APPLE = 1;    // 사과
const int SNAKE = 2;    // 뱀

/**
 * 게임이 몇 초에 끝나는지 계산하는 함수
 */

int playGame(int n, vector<vector<int>> &board, map<int, char> &cmd) {
    // 동(→), 남(↓), 서(←), 북(↑) 방향을 나타내는 배열
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    // 뱀의 위치 정보를 담는 덱
    deque<ci> snake;
    snake.push_front({1, 1});   // 뱀의 초기 위치 설정
    board[1][1] = SNAKE;        // 보드 상에 뱀의 위치 표시

    int time = 0;   // 현재 게임 시간
    int dir = 0;    // 현재 뱀의 이동 방향

    while (true) {
        // 뱀의 방향 변환 정보가 있는 경우
        if (cmd[time] == 'L') { // 왼쪽으로 회전
            dir = (dir + 1) % 4;
        } else if (cmd[time] == 'D') { // 오른쪽으로 회전
            dir = (dir + 3) % 4;
        }

        // 게임 시간 증가
        time++;

        // 뱀의 다음 머리 위치 계산
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        // 게임 종료 조건: 벽에 부딪히거나 자신의 몸과 충돌
        if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == SNAKE) {
            break;
        }

        // 뱀 이동 처리
        snake.push_front({nx, ny}); // 머리 이동
        if (board[nx][ny] != APPLE) { // 사과가 없는 경우 꼬리 이동
            ci tail = snake.back();
            board[tail.first][tail.second] = EMPTY;
            snake.pop_back();
        }
        board[nx][ny] = SNAKE; // 뱀의 새로운 위치 표시
    }
    return time; // 게임이 종료된 시간 반환
}

/**
 * [백준 3190: 뱀] https://www.acmicpc.net/problem/3190
 * 뱀의 머리와 꼬리 좌표에 접근하기 위해 deque를 사용
 * 사과가 있는 위치는 APPLE(1), 뱀이 있는 위치는 SNAKE(2), 빈 공간은 EMPTY(0)으로 표시
 * 1. 뱀의 초기 위치 설정
 * 2. 뱀의 방향 변환 정보 입력 및 저장
 * 3. 게임 진행 및 결과 출력
 */

int main() {
    int n, k, x, y, l, time; //보드 크기, 사과 개수, 사과 위치, 방향 전환 개수, 시간
    char command; //뱀 방향 변환 정보

    // 입력
    cin >> n >> k;
    vector<vector<int>> board(n + 1, vector<int>(n + 1, EMPTY)); // n x n 크기의 보드 초기화
    while (k--) {
        cin >> x >> y;
        board[x][y] = APPLE; // 사과의 위치 표시
    }
    cin >> l;
    map<int, char> cmd; // 시간별 뱀의 방향 변환 정보 저장
    while (l--) {
        cin >> time >> command;
        cmd[time] = command;
    }

    // 게임 진행하고 결과 출력
    cout << playGame(n, board, cmd);
    return 0;
}
