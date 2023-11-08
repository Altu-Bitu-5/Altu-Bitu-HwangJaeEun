#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll binarySearch(const vector<int>& times, int n, int m) {
    ll start = 1, end = static_cast<ll>(*max_element(times.begin(), times.end())) * m;
    ll answer = 0;

    while (start <= end) {
        ll mid = (start + end) / 2;
        ll cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += mid / times[i];
            if (cnt >= m) {
                break;
            }
        }

        if (cnt >= m) {
            answer = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> times(n);

    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    sort(times.begin(), times.end());

    cout << binarySearch(times, n, m);

    return 0;
}
