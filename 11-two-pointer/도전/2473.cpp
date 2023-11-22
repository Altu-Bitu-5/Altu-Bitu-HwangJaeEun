#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 2e18 + 1;

/**
 * 세 용액의 합이 가장 0에 가까운 용액의 쌍 리턴
 */

vector<ll> findLiquid(vector<ll>& arr) {
    int n = arr.size();
    vector<ll> result(3, 0);
    ll closestSum = INF;

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            ll currentSum = arr[i] + arr[left] + arr[right];

            if (llabs(currentSum) < closestSum) {
                closestSum = llabs(currentSum);
                result[0] = arr[i];
                result[1] = arr[left];
                result[2] = arr[right];
            }

            if (currentSum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    
    //입력
    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    //연산
    sort(arr.begin(), arr.end());
    vector<ll> result = findLiquid(arr);

    //출력
    for (int i = 0; i < 3; ++i) {
        cout << result[i] << ' ';
    }

    return 0;
}
