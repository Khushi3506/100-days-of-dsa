
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
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << arr[top--] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            if (i != top) {
                cout << " ";
            }
            cout << arr[i];
        }

        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Stack s(n);

    for (int i = 0; i < n; i++) {
        int operation;
        cin >> operation;

        if (operation == 1) {
            int value;
            cin >> value;
            s.push(value);
        }
        else if (operation == 2) {
            s.pop();
        }
        else if (operation == 3) {
            s.display();
        }
    }

    return 0;
}
