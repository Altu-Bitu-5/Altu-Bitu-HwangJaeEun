#include <iostream>
#include <vector>

using namespace std;

const int INF = 6e8;

void floydWarshall(int n, vector<vector<int>> &graph) {
    for (int k = 1; k <= n; k++) { // 중간 정점
        for (int i = 1; i <= n; i++) { // 출발 정점
            for (int j = 1; j <= n; j++) { // 도착 정점
                // 중간에 k를 거쳐서 i에서 j로 갈 때의 비용
                int cost = graph[i][k] + graph[k][j];
                // 더 짧은 경로 선택
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}

int findAnswer(int n, vector<vector<int>> &graph) {
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (i != j && (graph[i][j] != INF || graph[j][i] != INF)) {
                cnt++;
            }
        }
        if (cnt == n - 1) {
            answer++;
        }
    }
    return answer;
}

int main() {
    int N, M;
    //입력
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));

    for (int i = 1; i <= N; ++i) {
        graph[i][i] = 0; // 자기 자신과의 거리
    }

    while(M--) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1; // a가 b보다 작음을 나타내는 정보
    }

    //연산
    floydWarshall(N, graph);

    //출력
    cout << findAnswer(N, graph) << '\n';

    return 0;
}
