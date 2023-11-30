#include <iostream>  // 입출력 라이브러리
#include <vector>    // 벡터 컨테이너 사용
#include <queue>     // 우선순위 큐 사용

using namespace std;  // 표준 네임스페이스 사용
typedef pair<int, int> ci;  // 정수 쌍에 대한 typedef
const int INF = 2e5;  //최대 V-1개의 간선을 지나게 됨 -> V * (가중치 최대값)

// 다익스트라 알고리즘: 시작 노드부터 다른 모든 노드까지의 최단 경로를 찾음
vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
    vector<int> dist(v + 1, INF);  // 각 정점까지의 최단 경로 저장
    priority_queue<ci> pq;  // first: 시작점으로부터의 거리, second: 정점
    
    // 시작 정점 초기화
    dist[start] = 0;
   
    pq.push({ 0, start });  // 거리가 0인 시작 노드를 우선순위 큐에 삽입
    
    while (!pq.empty()) {
        int w = -pq.top().first;  // 현재 정점까지의 경로값
        int n = pq.top().second;  // 현재 탐색하려는 정점
        pq.pop();
        if (w > dist[n]) {   // 이미 더 작은 값으로 기록된 정점
            continue;
        }

        for (auto [nxt_node, nxt_weight] : graph[n]) { // 다음 정점과 해당 정점까지의 가중치를 반복문으로 처리
            if (dist[nxt_node] > dist[n] + nxt_weight) {  // 현재 정점을 거쳐서 가는 것이 더 짧은 경로인 경우
                dist[nxt_node] = dist[n] + nxt_weight; // 해당 정점까지의 최단 경로 갱신
                pq.push({ -dist[nxt_node], nxt_node }); // 최단 경로 우선순위 큐에 삽입
            }
        }
    }
    return dist;
}

int main() {
    int v, e, k, a, b, w;
    int answer = 0;

    // 입력
    cin >> v >> e >> k;
    vector<vector<ci>> graph(v + 1, vector<ci>(0));  // 인접 리스트

    while (e--) {
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });  // 방향 그래프
    }

    // 연산
    vector<int> go(v + 1), back;

    // 정점 i에서 파티 장소까지 걸리는 시간
    for (int i = 1; i <= v; i++) {
        vector<int> tmp = dijkstra(i, v, graph);
        go[i] = tmp[k];
    }

    // 파티 장소에서 다른 정점들까지 걸리는 시간
    back = dijkstra(k, v, graph);

    // 총 걸리는 시간 비교
    for (int i = 1; i <= v; i++) {
        answer = max(answer, go[i] + back[i]);
    }

    // 출력
    cout << answer;
    return 0;
}
