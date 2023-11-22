#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void findSolution(const string& word, int K) {
    vector<int> positions[26];
    int min_length = INT_MAX;
    int max_length = -1;

    for (int i = 0; i < word.length(); i++)
        positions[word[i] - 'a'].push_back(i);

    for (int i = 0; i < 26; i++) {
        if (positions[i].size() >= K) {
            int left = 0;
            int right = K - 1;

            int temp_min_length = positions[i][right] - positions[i][left] + 1;
            int temp_max_length = positions[i][right] - positions[i][left] + 1;

            while (right < positions[i].size() - 1) {
                right++;
                left++;
                temp_min_length = min(positions[i][right] - positions[i][left] + 1, temp_min_length);
                temp_max_length = max(positions[i][right] - positions[i][left] + 1, temp_max_length);
            }

            min_length = min(temp_min_length, min_length);
            max_length = max(temp_max_length, max_length);
        }
    }

    if (min_length == INT_MAX)
        cout << -1 << "\n";
    else
        cout << min_length << " " << max_length << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int T;
    cin >> T;

    while (T--) {
        string word;
        int K;
        cin >> word >> K;

        // 연산 & 출력
        findSolution(word, K);
    }

    return 0;
}
