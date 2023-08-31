#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력 && 연산
    while(1) {
        string input;
        getline(cin, input);
        
        if(input[0] == '.') {
            break;
        }
        
        stack<char> s;
        bool ans = false;
        
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(' || input[i] != '[') {
                s.push(input[i]);
            }
            if (input[i] == ')') {
                if ( !s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    ans = true;
                    break;
                }
            }
            if (input[i] == ']') {
                if ( !s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    ans = true;
                    break;
                }
            }
        }
        
        if (ans == false && s.empty()) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }
        
    }
    

    //출력
    
    return 0;
}