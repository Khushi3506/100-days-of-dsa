
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    while (!q.empty()) {
        cout << q.front();
        q.pop();

        if (!q.empty()) {
            cout << " ";
        }
    }

    cout << endl;
    return 0;
}
