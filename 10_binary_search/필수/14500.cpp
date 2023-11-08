#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board; // 게임 보드를 나타내는 2D 벡터
int ans; // 최대 결과를 저장할 변수

// 깊이 우선 탐색(Depth-First Search) 함수로 다양한 테트로미노 모양을 탐색
void dfs(int x, int y, int depth, int sum) {
    // 네 가지 방향으로 이동하기 위한 배열: 위, 오른쪽, 아래, 왼쪽
    vector<int> dx = { -1, 0, 1, 0 };
    vector<int> dy = { 0, 1, 0, -1 };

    if (depth == 4) { // 네 개의 칸을 선택했을 경우, 최대 결과를 갱신
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        // 다음에 선택할 칸의 좌표를 계산
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) {
            // 셀이 범위를 벗어나거나 이미 방문한 경우 CONTINUE
            continue;
        }

        int temp = board[nx][ny]; // 방문하기 전 현재 셀의 값을 저장
        board[nx][ny] = 0; // 재방문을 피하기 위해 현재 셀을 방문 처리

        if (depth == 2) {
            // "ㅜ" 모양의 특수한 경우로, 현재 셀에서 다시 블록을 선택
            dfs(x, y, depth + 1, sum + temp);
        }

        // 깊이와 합을 업데이트하여 다음 셀로 이동
        dfs(nx, ny, depth + 1, sum + temp);

        board[nx][ny] = temp; // 원래 값 복원
    }
}

int main() {
    //입력
    int n, m;
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0)); // 게임 보드의 크기를 n x m으로 초기화

    // 게임 보드의 값 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 각 셀에서 시작하여 테트로미노 모양을 찾기 위한 탐색을 수행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp = board[i][j];
            board[i][j] = 0; // 시작 셀을 방문 처리
            dfs(i, j, 1, temp); // 깊이 1과 초기 합으로 DFS를 시작
            board[i][j] = temp; // 원래 값을 복원
        }
    }

    // 출력
    cout << ans;

    return 0;
}
