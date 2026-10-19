#include <iostream>
using namespace std;

class Queue {
    int arr[1000];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == 999) {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[++rear] = value;
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
    }

    void display() {
        if (front > rear) {
            cout << "Queue is Empty";
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, value;
    cin >> n;

    Queue q;

    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    q.display();

    return 0;
}