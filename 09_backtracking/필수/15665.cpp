#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 8;

int n, m;
int sequence[MAX_N];
vector<int> ans;

void printSequence() {
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

void backtrack(int cnt, int start)
{
    // 재귀 호출 종료 조건 : M개의 숫자를 다 뽑은 경우
    if (cnt == m)
    {
        printSequence();
        return;
    }

    //i : 고르려는 수
    int prev_num = -1;  // 이전에 선택한 숫자를 기억하기 위한 변수
    for (int i = 0; i < n; i++)
    {
        // 중복 선택 허용, 중복된 숫자를 생성하지 않도록 조건 추가
        if (sequence[i] != prev_num) {
            //사용
            ans.push_back(sequence[i]);
            prev_num = sequence[i];
            
            //다음 숫자 고르기
            backtrack(cnt + 1, i + 1);
            
            //반납
            ans.pop_back();
        }
    }
}

int main()
{
    //입력력
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> sequence[i];
        
    //연산 및 출력
    sort(sequence, sequence + n);  // 입력된 숫자 배열을 정렬

    backtrack(0, 0);  // 조합 생성 시작
}
