
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PriorityQueue {
private:
    vector<int> arr;

public:
    void insert(int x) {
        arr.push_back(x);
        sort(arr.begin(), arr.end());
    }

    int peek() {
        if (arr.empty()) {
            return -1;
        }
        return arr[0];
    }

    int deleteElement() {
        if (arr.empty()) {
            return -1;
        }

        int value = arr[0];
        arr.erase(arr.begin());
        return value;
    }
};

int main() {
    int N;
    cin >> N;

    PriorityQueue pq;

    for (int i = 0; i < N; i++) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int x;
            cin >> x;
            pq.insert(x);
        }
        else if (operation == "delete") {
            cout << pq.deleteElement() << endl;
        }
        else if (operation == "peek") {
            cout << pq.peek() << endl;
        }
    }

    return 0;
}
