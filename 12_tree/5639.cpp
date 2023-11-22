#include <iostream>
#include <vector>

using namespace std;

// 이진 트리 노드 구조체
struct Node {
    int data;
    Node* left;
    Node* right;
};

// 이진 트리 노드 생성 함수
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// 이진 트리 삽입 함수
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// 이진 트리 후위 순회 함수
void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << '\n';
}

int main() {
    int value;
    Node* root = nullptr;

    //입력 & 연산
    // 전위 순회 결과로 이진 트리 생성
    while (cin >> value) {
        root = insertNode(root, value);
    }

    //출력
    postorder(root);

    return 0;
}
