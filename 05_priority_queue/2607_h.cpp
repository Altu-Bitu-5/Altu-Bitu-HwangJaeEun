#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int findSimilarWord(vector<string>& words){
    int rst = 0;
    array<int, 26> alpha = {0};
    
    for (int i = 0; i < words[0].size(); i++) {
        alpha[words[0][i] - 'A'] += 1;
    }

    for (int i = 1; i < words.size(); i++) {
        array<int, 26> alpha_cp = alpha;
            
        int same = 0;
            
        for (int j = 0; j < words[i].size(); j++) {
            if (alpha_cp[words[i][j] - 'A'] > 0) {
                alpha_cp[words[i][j] - 'A'] --;
                same++;
            }
        }
            
        if (words[0].size() == words[i].size()) {
            if (same == words[0].size() || same == words[0].size() -1)
            rst ++;
        }
        
        else if (words[0].size() - 1 == words[i].size() && same == words[0].size() - 1) {
            rst ++;
        }
        
        else if ( words[0].size() + 1 == words[i].size() && same == words[0].size() ) {
            rst ++;
        }
        
        else {
            continue;
        }
    }

    return rst;
}

int main() {
    
    int n;
    int cnt = 0;

    //input
    cin >> n;
    vector<string> words(n);
    
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    //operation & output
    cout << findSimilarWord(words);
    
    return 0;
}