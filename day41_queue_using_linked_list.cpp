
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (front == nullptr) {
            return -1;
        }

        Node* temp = front;
        int value = temp->data;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return value;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    int N;
    cin >> N;

    Queue q;

    for (int i = 0; i < N; i++) {
        string operation;
        cin >> operation;

        if (operation == "enqueue") {
            int value;
            cin >> value;
            q.enqueue(value);
        }
        else if (operation == "dequeue") {
            cout << q.dequeue() << '\n';
        }
    }

    return 0;
}
