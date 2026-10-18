
#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) {
            return;
        }

        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            return;
        }

        top--;
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i];

            if (i > 0) {
                cout << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Stack s(n);

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        s.push(value);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        s.pop();
    }

    s.display();

    return 0;
}
