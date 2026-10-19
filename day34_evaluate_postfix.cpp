
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            return 0;
        }

        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;

        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }
};

int evaluatePostfix(string expression) {
    Stack st;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" ||
            token == "*" || token == "/") {

            int b = st.pop();
            int a = st.pop();

            if (token == "+") {
                st.push(a + b);
            } else if (token == "-") {
                st.push(a - b);
            } else if (token == "*") {
                st.push(a * b);
            } else if (token == "/") {
                st.push(a / b);
            }
        } else {
            st.push(stoi(token));
        }
    }

    return st.pop();
}

int main() {
    string expression;
    getline(cin, expression);

    cout << evaluatePostfix(expression) << endl;

    return 0;
}
