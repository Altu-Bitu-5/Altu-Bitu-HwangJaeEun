#include <iostream>
#include <vector>
#include <string>

using namespace std;

void add(vector<bool> &s) {
    int x;
    cin >> x;
    s[x] = true;
}

void remove(vector<bool> &s) {
    int x;
    cin >> x;
    s[x] = false;
}

void check(vector<bool> &s) {
    int x;
    cin >> x;
    cout << s[x] << '\n';
}

void toggle(vector<bool> &s) {
    int x;
    cin >> x;
    s[x] = !s[x];
}

void all(vector<bool> &s) {
    s.assign(21, true);
}

void empty(vector<bool> &s) {
    s.assign(21, false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    string input;
    cin >> m;
    vector<bool> s(21, false);

    while (m--) {
        cin >> input;
        if (input == "add"){
            add(s);
            continue;
        }
        if (input == "remove"){
            remove(s);
            continue;
        }
        if (input == "check"){
            check(s);
            continue;
        }
        if(input == "toggle"){
            toggle(s);
            continue;
        }
        if(input == "all"){
            all(s);
            continue;
        }
        if(input == "empty"){
            empty(s);
            continue;
        }
    }
    return 0;
}