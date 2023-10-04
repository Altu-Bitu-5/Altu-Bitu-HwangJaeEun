#include <iostream>
#include <queue>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    int a, x;
    priority_queue<int> gift;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) {
            if(gift.empty()) {
                cout << "-1\n";
            }
            else {
                cout << gift.top() << "\n";
                gift.pop();
            }
        }
        else {
            while (a--) {
                cin >> x;
                gift.push(x);   
            }
        }
    }

    return 0;
}