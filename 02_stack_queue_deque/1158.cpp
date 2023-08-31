#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    for (int i = 1; i < n+1; i++) {
        dq.push_back(i);
    }

    //연산 && 출력
    cout << '<';
    while (dq.size() > 1) {
        for ( int i = 0; i < k-1; i++) {
            dq.push_back(dq.front());
            dq.pop_front();
        } 
        cout << dq.front() << ", ";
        dq.pop_front();
    }
    cout << dq.front() << '>';
    return 0;
}