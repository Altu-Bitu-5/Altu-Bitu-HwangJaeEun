#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;
bool board[MAX][MAX] = {false};

// 우 상 좌 하
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void drawDragonCurve(int x, int y, int d, int g) {
    vector<int> directions = {d};
    for (int i = 0; i < g; ++i) {
        int size = directions.size();
        for (int j = size - 1; j >= 0; --j) {
            directions.push_back((directions[j] + 1) % 4);
        }
    }

    board[y][x] = true;
    for (int dir : directions) {
        x = x + dx[dir];
        y = y + dy[dir];
        board[y][x] = true;
    }
}

int countSquare() {
    int cnt = 0;
    for (int i = 0; i < MAX - 1; ++i) {
        for (int j = 0; j < MAX - 1; ++j) {
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1])
                cnt++;
        }
    }
    return cnt;
}

int main() {
    
    //입력
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        drawDragonCurve(x, y, d, g);
    }

    //연산 & 출력
    cout << countSquare() << endl;

    return 0;
}
