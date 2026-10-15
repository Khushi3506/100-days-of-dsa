
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* createList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int countOccurrences(Node* head, int key) {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        if (current->data == key) {
            count++;
        }

        current = current->next;
    }

    return count;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = createList(n);

    int key;
    cin >> key;

    cout << countOccurrences(head, key) << endl;

    deleteList(head);

    return 0;
}
