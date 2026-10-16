
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
    if (n <= 0) {
        return nullptr;
    }

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

        tail->next = head;
    }

    return head;
}

void printList(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;

    do {
        cout << current->data;
        current = current->next;

        if (current != head) {
            cout << " ";
        }
    } while (current != head);

    cout << endl;
}

void deleteList(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head->next;

    while (current != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    delete head;
}

int main() {
    int n;
    cin >> n;

    Node* head = createList(n);

    printList(head);

    deleteList(head);

    return 0;
}
