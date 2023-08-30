#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int w0, i0, t;
    int d, i1, a;
    
    string output1, output2;
    int w1, w2;
    int l;
    
    //입력
    cin >> w0 >> i0 >> t;
    cin >> d >> i1 >> a;
    w1 = w0;
    w2 = w0;
    l = i0;
    
    //연산
    for (int i = 0; i < d; i++) {
        w1 += i1 - (i0 + a);
        w2 += i1 - (l + a);
        
        if (abs(i1-(l+a)) > t) {
            l += floor((i1-(l+a))/2.0);
        }
    }
    
    if (w1 <= 0) {
            output1 = "Danger Diet";
            cout << output1 <<  '\n';
        }
        
    else
        cout << w1 << " " << i0 <<  '\n';
            
    if (w2 <= 0 || l <= 0 ) {
        output2 = "Danger Diet";
        cout << output2;
    }
    else {
        if ( i0 - l > 0) {
            output2 = "YOYO";
            cout << w2 << " " << l << " " << output2; 
        }
        else {
            output2 = "NO";
            cout << w2 << " " << l << " " << output2; 
        }
    }

    return 0;
}