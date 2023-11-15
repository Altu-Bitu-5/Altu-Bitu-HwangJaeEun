#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPossible(vector<int>& lengths, int target, int m) {
    int count = 0;
    for (int i = 0; i < lengths.size(); i++) {
        count += lengths[i] / target;
    }
    return count >= m;
}

int binarySearch(vector<int>& lengths, int m) {
    int left = 1;
    int right = lengths[lengths.size() - 1];
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(lengths, mid, m)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main () {
    int m, n;
    
    //입력
    cin >> m >> n;

    vector<int> arr(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산 & 출력
    cout << binarySearch(arr, m);

    return 0;
}
