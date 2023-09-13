#include <iostream>
#include <string>

using namespace std;

string sumBigint(string a, string b) {
    int as = a.size();
    int bs = b.size();
    int car = 0, cur = 0;
    char rst;
    string ans;
    while ( as > 0 || bs > 0) {
        int a1 = 0;
        if ( as > 0 ) {
            a1 = a[ --as ] - '0';
        }
        int b1 = 0;
        if ( bs > 0 ) {
            b1 = b[ --bs ] - '0';
        }
        
        cur = a1 + b1 + car;
        car = cur / 10;
        cur = cur % 10;
        rst = cur + '0';
        ans += rst;
    }
    
    if ( car > 0 ) {
        ans += car + '0';
    }
    
    return ans;
}

int main () {
    //입력
    string a, b;
    cin >> a >> b;
    
    string ans;
    
    //연산
    ans = sumBigint(a, b);

    //출력
    for (int i = ans.size(); i > 0; i--) {
        cout << ans[i-1];   
    }

    return 0;
}