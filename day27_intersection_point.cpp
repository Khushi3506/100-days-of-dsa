
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

Node* findIntersection(Node* head1, Node* head2) {
    Node* p1 = head1;
    Node* p2 = head2;

    while (p1 != p2) {
        p1 = (p1 == nullptr) ? head2 : p1->next;
        p2 = (p2 == nullptr) ? head1 : p2->next;
    }

    return p1;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head1 = new Node(10);
    head1->next = new Node(20);

    Node* shared = new Node(30);
    shared->next = new Node(40);
    shared->next->next = new Node(50);

    head1->next->next = shared;

    Node* head2 = new Node(15);
    head2->next = new Node(25);
    head2->next->next = shared;

    Node* intersection = findIntersection(head1, head2);

    if (intersection != nullptr) {
        cout << intersection->data << endl;
    } else {
        cout << "No Intersection" << endl;
    }

    deleteList(head1);
    delete head2->next;
    delete head2;

    return 0;
}
