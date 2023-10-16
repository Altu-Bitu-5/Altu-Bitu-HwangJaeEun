#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> hacked; // 각 컴퓨터의 해킹 여부를 저장하는 배열

// 깊이 우선 탐색(DFS)을 통해 컴퓨터가 해킹할 수 있는 컴퓨터 개수를 세는 함수
int dfs(int node, vector<vector<int>> &graph) {
    int cnt = 1; // 현재 노드가 해킹할 수 있는 컴퓨터 수를 1로 초기화
    hacked[node] = true; // 현재 노드를 해킹한 것으로 표시

    for (int i = 0; i < graph[node].size(); i++) { // node 컴퓨터가 해킹할 수 있는 컴퓨터 탐색
        int next_node = graph[node][i];
        int next_node = graph[node][i];
        if (!hacked[next_node]) { // 아직 해킹되지 않은 컴퓨터를 발견
            cnt += dfs(next_node, graph); // 재귀적으로 탐색하여 해킹 가능한 컴퓨터 수 증가
        }
    }
    return cnt; // 현재 노드가 해킹할 수 있는 컴퓨터 수 반환
}

// 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호를 찾는 함수
vector<int> hack(int n, vector<vector<int>> &graph) {
    int max_cnt = 0; // 최대 감염된 컴퓨터 수를 저장하는 변수
    vector<int> result; // 결과로 반환할 컴퓨터 번호를 저장하는 벡터

    for (int i = 1; i <= n; i++) { // i : 최초로 해킹된 컴퓨터
        hacked.assign(n + 1, false); // (탐색 시작전 전역변수 초기화 필요)
        int tmp = dfs(i, graph); // tmp : i번 컴퓨터가 해킹한 컴퓨터 수

        if (tmp > max_cnt) { // 최대 감염된 컴퓨터 수를 갱신
            max_cnt = tmp;
            result = {i};
        } else if (tmp == max_cnt) { // 현재 컴퓨터에서 감염된 컴퓨터 수가 최대와 같다면 결과에 추가
            result.push_back(i);
        }
    }
    return result; // 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호를 반환
}

/*
 * [가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호 구하기]
 * 그래프 탐색을 이용하여 컴퓨터별 해킹할 수 있는 컴퓨터 수를 구한다.
 */

int main() {
    int n, m, a, b; //컴퓨터의 수, 컴퓨터 신뢰 관계, 컴퓨터 간 관계를 나타내는 두 개의 정수
    vector<vector<int>> graph; //그래프를 나타내는 2차원 벡터

    // 입력
    cin >> n >> m;
    graph.assign(n + 1, vector<int>(0)); //벡터 할당 후 0으로 초기화

    while (m--) {
        /*
         * a는 b를 신뢰한다.
         * == b는 a를 감염시킬 수 있다.
         */
        cin >> a >> b;
        graph[b].push_back(a); // 간선 정보 저장
    }

    // 연산 & 출력
    vector<int> result = hack(n, graph); // 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 찾기
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' '; // 결과 출력
    }
    return 0;
}
