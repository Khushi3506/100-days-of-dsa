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

// Function to search in BST
bool searchBST(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == key) {
        return true;
    }

    if (key < root->data) {
        return searchBST(root->left, key);
    }

    return searchBST(root->right, key);
}

int main() {
    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int key = 60;

    if (searchBST(root, key)) {
        cout << key << " found in BST";
    } else {
        cout << key << " not found in BST";
    }

    return 0;
}
