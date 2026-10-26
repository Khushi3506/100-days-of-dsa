
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    deque<int> dq;
    int n;
    cin >> n;

    while (n--) {
        string operation;
        cin >> operation;

        if (operation == "push_front") {
            int value;
            cin >> value;
            dq.push_front(value);
        }
        else if (operation == "push_back") {
            int value;
            cin >> value;
            dq.push_back(value);
        }
        else if (operation == "pop_front") {
            if (!dq.empty()) {
                dq.pop_front();
            }
        }
        else if (operation == "pop_back") {
            if (!dq.empty()) {
                dq.pop_back();
            }
        }
        else if (operation == "front") {
            cout << (dq.empty() ? -1 : dq.front()) << endl;
        }
        else if (operation == "back") {
            cout << (dq.empty() ? -1 : dq.back()) << endl;
        }
        else if (operation == "size") {
            cout << dq.size() << endl;
        }
        else if (operation == "empty") {
            cout << (dq.empty() ? "true" : "false") << endl;
        }
        else if (operation == "clear") {
            dq.clear();
        }
        else if (operation == "reverse") {
            reverse(dq.begin(), dq.end());
        }
        else if (operation == "sort") {
            sort(dq.begin(), dq.end());
        }
    }

    for (int value : dq) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
