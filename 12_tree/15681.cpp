#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list; // 인접 리스트
vector<int> subtree_size; // 각 정점의 서브트리 크기
vector<bool> visited; // 방문 여부 표시

// DFS를 통해 각 정점을 루트로 하는 서브트리의 크기를 계산
int calculateSubtreeSizes(int node) {
    visited[node] = true;
    subtree_size[node] = 1; // 해당 정점 자신을 포함

    for (int i = 0; i < adj_list[node].size(); ++i) {
        int child = adj_list[node][i];
        if (!visited[child]) { // 아직 방문하지 않은 자식 노드라면
            subtree_size[node] += calculateSubtreeSizes(child);
        }
    }

    return subtree_size[node];
}

int main() {
    ios_base::sync_with_stdio(false); // 입출력 최적화
    cin.tie(NULL), cout.tie(NULL);
    
    //입력
    int num_vertices, root, num_queries;
    cin >> num_vertices >> root >> num_queries;


    adj_list.resize(num_vertices + 1);
    subtree_size.resize(num_vertices + 1);
    visited.resize(num_vertices + 1, false);

    for (int i = 0; i < num_vertices - 1; ++i) {
        int U, V;
        cin >> U >> V;
        adj_list[U].push_back(V);
        adj_list[V].push_back(U);
    }

    //연산
    calculateSubtreeSizes(root);

    //출력
    for (int i = 0; i < num_queries; ++i) {
        int query_vertex;
        cin >> query_vertex;
        cout << subtree_size[query_vertex] << '\n';
    }

    return 0;
}
