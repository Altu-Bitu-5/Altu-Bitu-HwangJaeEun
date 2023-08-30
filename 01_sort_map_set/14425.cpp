#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    
    int n, m;
    int cnt = 0;
    string input;    
    map <string, bool> s1;
    
    //입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input;
        s1.insert(pair<string, bool> (input, true));
    }
    
    //연산
    for (int i = 0; i < m; i++) {
        cin >> input;
        if (s1[input]) {
            cnt++;
        }
    }
    
    //출력
    cout << cnt << '\n';
    
    return 0;
}