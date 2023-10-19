#include <deque>
#include <iostream>

using namespace std;

struct info { // 내구도와 로봇 존재 여부를 나타내는 구조체
    int power;   // 컨베이어 벨트의 칸 내구도
    bool is_on;  // 해당 칸에 로봇이 존재하는지 여부
};

// 컨베이어 벨트 한 칸 회전 함수
void rotateBelt(deque<info> &belt, int n) {
    belt.push_front(belt.back());  // 맨 뒤의 칸을 앞으로 이동
    belt.pop_back();               // 맨 뒤의 칸 제거
    belt[n - 1].is_on = false;     // 로봇이 내리는 위치에서 로봇 제거
}

// 로봇을 이동시킬 수 있는 경우 이동하는 함수
void moveRobot(deque<info> &belt, int n) {
    for (int i = n - 2; i >= 0; i--) {
        if (!belt[i].is_on) {
            continue;  // 해당 칸에 로봇이 없으면 다음 칸으로 이동
        }
        
        if (!belt[i + 1].is_on && (belt[i + 1].power >= 1)) {
            // 다음 칸이 비어있고 내구도가 남아있을 때 로봇 이동
            belt[i].is_on = false;
            belt[i + 1].is_on = true;
            belt[i + 1].power--;
        }
        
        belt[n - 1].is_on = false; // 로봇이 내리는 위치에서 로봇 제거
    }
}

// 로봇을 컨베이어 벨트에 올릴 수 있는 경우 로봇을 올리는 함수
void putRobot(deque<info> &belt) {
    if (!belt[0].is_on && belt[0].power >= 1) {
        // 로봇이 없고 내구도가 남아있는 경우 로봇을 올림
        belt[0].is_on = true;
        belt[0].power--;
    }
}

// 컨베이어 벨트의 내구도를 확인하여 작업 종료 여부를 반환
bool checkFinish(deque<info> &belt, int n, int k) {
    int count = 0;
    
    for (int i = 0; i < 2 * n; i++) {
        if (belt[i].power == 0) {
            count++;
        }
    }

    return count >= k;
}

int solution(deque<info> &belt, int n, int k) {
    int step = 1;
    while (true) {
        // 컨베이어 벨트 회전
        rotateBelt(belt, n);
        // 로봇 이동
        moveRobot(belt, n);
        // 로봇 올리기
        putRobot(belt);

        // 내구도 체크
        if (checkFinish(belt, n, k)) {
            return step;
        }
        step++;
    }
}

int main() {
    // 입력
    int n, k;
    cin >> n >> k;
    deque<info> belt(2 * n); // 컨베이어 벨트의 내구도와 로봇 존재 여부 저장
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i].power;
        belt[i].is_on = false;
    }
    
    // 연산
    int answer = solution(belt, n, k);
    
    // 출력
    cout << answer;
}