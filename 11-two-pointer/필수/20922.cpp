#include <iostream>
#include <vector>

using namespace std;

int findSolution(const vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> frequency(100001, 0);

    int left = 0, right = 0;
    int maxLength = 0;

    while (right < n) {
        frequency[arr[right]]++;

        // 현재 구간의 서로 다른 숫자의 개수가 k 초과라면
        while (frequency[arr[right]] > k) {
            frequency[arr[left]]--;
            left++;
        }

        // 현재 구간의 길이가 최대인지 확인하고 right 증가
        maxLength = max(maxLength, right - left + 1);
        right++;
    }

    return maxLength;
}

int main() {
    //입력
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    //연산 & 출력
    cout << findSolution(arr, k) << '\n';

    return 0;
}
