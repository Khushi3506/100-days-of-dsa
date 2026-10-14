
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

Node* deleteFirstOccurrence(Node* head, int key) {
    if (head == nullptr) {
        return head;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;

    while (current->next != nullptr) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            break;
        }

        current = current->next;
    }

    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << " ";
        }
        head = head->next;
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

    int key;
    cin >> key;

    head = deleteFirstOccurrence(head, key);

    printList(head);
    deleteList(head);

    return 0;
}
