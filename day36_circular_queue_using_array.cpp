
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[1000];
    int front, rear, capacity, count;

public:
    CircularQueue(int k) {
        front = 0;
        rear = -1;
        capacity = k;
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

    void dequeue() {
        if (count == 0) {
            return;
        }

        front = (front + 1) % capacity;
        count--;
    }

    void display() {
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    void rotate() {
        if (count == 0) {
            return;
        }

        int value = arr[front];
        front = (front + 1) % capacity;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
    }
};

int main() {
    int n;
    cin >> n;

    CircularQueue q(1000);

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        q.enqueue(value);
    }

    int m;
    cin >> m;

    // Move the first m elements to the rear.
    for (int i = 0; i < m; i++) {
        q.rotate();
    }

    q.display();

    return 0;
}
