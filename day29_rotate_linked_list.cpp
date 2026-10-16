
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
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

Node* rotateRight(Node* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    Node* tail = head;
    int length = 1;

    while (tail->next != nullptr) {
        tail = tail->next;
        length++;
    }

    k = k % length;

    if (k == 0) {
        return head;
    }

    tail->next = head;

    int steps = length - k;
    Node* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data;

        if (current->next != nullptr) {
            cout << " ";
        }

        current = current->next;
    }

    cout << endl;
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

    int k;
    cin >> k;

    head = rotateRight(head, k);

    printList(head);
    deleteList(head);

    return 0;
}
