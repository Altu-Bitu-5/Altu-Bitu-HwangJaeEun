#include <iostream>

using namespace std;

const int MAX_N = 11;

int n;

int min_num = 1000000001;
int max_num = -1000000001;

int sequence[MAX_N]; // 수열 
int operators[4]; // 연산자

void updateAnswer(int ans) {
    max_num = max(max_num, ans);
    min_num = min(min_num, ans);
}

void findMinMax(int ans, int cnt)
{
    //재귀 호출 종료 조건 : 수열의 값을 다 사용하였을 경우
    if(cnt == n)
    {
        updateAnswer(ans);
        return;
    }

    //i : 연산자 종류
    for(int i = 0; i < 4; i++)
    {
        // 연산자를 다 쓰지 않은 경우만
        if(operators[i] > 0)
        {
            //연산자 사용
            operators[i]--;

            //rst 값 업데이트 및 다음 연산자 고르기
            if(i == 0)
                findMinMax(ans + sequence[cnt], cnt + 1);
            else if(i == 1)
                findMinMax(ans - sequence[cnt], cnt + 1);
            else if(i == 2)
                findMinMax(ans * sequence[cnt], cnt + 1);
            else
                findMinMax(ans / sequence[cnt], cnt + 1);

            operators[i]++; // 연산자 반납
        }
    }
    return;
}

int main() {

    //입력
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> sequence[i];
    for(int i = 0; i < 4; i++)
        cin >> operators[i];

    //연산
    findMinMax(sequence[0], 1);
    
    //출력
    cout << max_num << '\n' << min_num;
}