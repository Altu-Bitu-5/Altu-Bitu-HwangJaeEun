#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumNum(string s) {
    int rst = 0;
    for ( int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])){
            rst += s[i] - '0';
        }
    }
    return rst;
}

bool cmp(const string &s1, const string &s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
    }
    if (sumNum(s1) != sumNum(s2)) {
        return sumNum(s1) < sumNum(s2);
    }
    
    return s1 < s2;
}

int main() {
    int n;
    string input;

    //입력
    cin >> n;
    vector <string> serial(n, "");
    for ( int i = 0; i < n; i++ ) {
        cin >> input;
        serial[i] = input;
    }

    //연산
    sort(serial.begin(), serial.end(), cmp);

    //출력
    for ( int i = 0; i < n; i++ ) {
        cout << serial[i] << '\n';
    }

    return 0;
}