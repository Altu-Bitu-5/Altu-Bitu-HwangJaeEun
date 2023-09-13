#include <iostream>
#include <string>
#include <utility>
using namespace std;

pair<char, int> stringToCoord(const string& s) {
    return make_pair(s[0], s[1] - '0');
}

string coordToString(const pair<char, int>& c) {
    return string(1, c.first) + to_string(c.second);
}

void move(pair<char, int>& king, pair<char, int>& stone, const string& command) {
    pair<char, int> nextKing = king;
    pair<char, int> nextStone = stone;

    if (command == "R") {
        nextKing.first++;
    } else if (command == "L") {
        nextKing.first--;
    } else if (command == "B") {
        nextKing.second--;
    } else if (command == "T") {
        nextKing.second++;
    } else if (command == "RT") {
        nextKing.first++;
        nextKing.second++;
    } else if (command == "LT") {
        nextKing.first--;
        nextKing.second++;
    } else if (command == "RB") {
        nextKing.first++;
        nextKing.second--;
    } else if (command == "LB") {
        nextKing.first--;
        nextKing.second--;
    }

    if (nextKing.first < 'A' || nextKing.first > 'H' || nextKing.second < 1 || nextKing.second > 8)
        return;

    if (nextKing == stone) {
        if (command == "R") {
            nextStone.first++;
        } else if (command == "L") {
            nextStone.first--;
        } else if (command == "B") {
            nextStone.second--;
        } else if (command == "T") {
            nextStone.second++;
        } else if (command == "RT") {
            nextStone.first++;
            nextStone.second++;
        } else if (command == "LT") {
            nextStone.first--;
            nextStone.second++;
        } else if (command == "RB") {
            nextStone.first++;
            nextStone.second--;
        } else if (command == "LB") {
            nextStone.first--;
            nextStone.second--;
        }

        if (nextStone.first < 'A' || nextStone.first > 'H' || nextStone.second < 1 || nextStone.second > 8)
            return;

        king = nextKing;
        stone = nextStone;
    
    } else {
        king = nextKing;
    }
}

int main() {
    pair<char, int> king, stone;
    string k_pos, s_pos;
    int n;
    cin >> k_pos >> s_pos >> n;
    
    king = stringToCoord(k_pos);
    stone = stringToCoord(s_pos);

    while (n--) {
        string command;
        cin >> command;
        move(king, stone, command);
    }

    cout << coordToString(king) << '\n';
    cout << coordToString(stone) << '\n';

    return 0;
}
