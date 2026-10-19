
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^') {
        return 3;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for (char ch : s) {
        if (ch == ' ') {
            continue;
        }

        if (isalnum(static_cast<unsigned char>(ch))) {
            result += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }

            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                   (precedence(st.top()) == precedence(ch) && ch != '^'))) {
                result += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string expression;
    getline(cin, expression);

    cout << infixToPostfix(expression) << endl;

    return 0;
}
