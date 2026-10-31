
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a node in BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find LCA
Node* findLCA(Node* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }

    if (n1 < root->data && n2 < root->data) {
        return findLCA(root->left, n1, n2);
    }

    if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    }

    return root;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    int n1, n2;
    cin >> n1 >> n2;

    Node* ans = findLCA(root, n1, n2);

    if (ans != nullptr) {
        cout << ans->data;
    }

    return 0;
}
