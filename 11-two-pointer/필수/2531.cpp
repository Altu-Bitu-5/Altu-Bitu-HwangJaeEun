#include <iostream>
#include <vector>

using namespace std;

void findSolution(int n, int d, int k, int c, vector<int>& sushi) {
    vector<int> check(d + 1, 0);
    int crt_ans = 1;
    int ans = 0;

    check[c] = 1;

    for (int i = 0; i < k; i++) {
        if (check[sushi[i]] == 0) {
            crt_ans++;
        }
        check[sushi[i]]++;
        sushi[n + i] = sushi[i];
    }

    for (int i = 0; i < n; i++) {
        ans = max(crt_ans, ans);

        check[sushi[i]]--;

        if (check[sushi[i]] == 0) {
            crt_ans--;
        }

        if (check[sushi[i + k]] == 0) {
            crt_ans++;
        }
        check[sushi[i + k]]++;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> sushi(n + k);
    for (int i = 0; i < n; i++) {
        cin >> sushi[i];
    }

    // 연산 & 출력
    findSolution(n, d, k, c, sushi);

    return 0;
}
