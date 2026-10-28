
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree(vector<int>& arr, int n) {
    if (n == 0 || arr[0] == -1) {
        return nullptr;
    }

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        if (i < n && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = buildTree(arr, n);

    inorder(root);
    cout << endl;

    deleteTree(root);
    return 0;
}
