
#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, capacity, count;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int value) {
        if (count == capacity) {
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
    }

    int dequeue() {
        if (count == 0) {
            return -1;
        }

        int value = arr[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }

    void display() {
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity];
            if (i < count - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    int n, value, m;

    cin >> n;

    if (n <= 0) {
        return 0;
    }

    CircularQueue q(n);

    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cin >> m;

    for (int i = 0; i < m && i < n; i++) {
        int removed = q.dequeue();
        q.enqueue(removed);
    }

    q.display();

    return 0;
}
