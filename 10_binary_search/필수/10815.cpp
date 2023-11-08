#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(int n, int key, vector<int> &nums) {
    int left = 0;
    int right = n - 1;
    int mid;

    while(left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == key) {
            return 1;
        }
        else if (nums[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, input;

    //입력
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cin >> m;
    
    //이분 탐색을 하기 위해 정렬
    sort(arr.begin(), arr.end());

    //연산 & 출력
    while(m--) {
        cin >> input;
        cout << binarySearch(n, input, arr) << ' ';
    }

    return 0;
}