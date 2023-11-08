#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool isPossible(vector<int>& lessons, int m, int mid) {
    int count = 1;
    int sum = 0;

    for (int i = 0; i < lessons.size(); i++) {
        if (sum + lessons[i] > mid) {
            count++;
            sum = lessons[i];
        } else {
            sum += lessons[i];
        }
    }

    return count <= m;
}

int binarySearch(vector<int>& lessons, int m) {
    int left = *max_element(lessons.begin(), lessons.end());
    int right = accumulate(lessons.begin(), lessons.end(), 0);
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(lessons, m, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n, m;
    cin >> n >> m;

    vector<int> lessons(n);

    for (int i = 0; i < n; i++) {
        cin >> lessons[i];
    }

    // 연산 & 출력
    cout <<  binarySearch(lessons, m);

    return 0;
}
