
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] <= heap[i])
                break;

            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();

        while (true) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i)
                break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int peek() {
        if (heap.empty())
            return -1;

        return heap[0];
    }

    int extractMin() {
        if (heap.empty())
            return -1;

        int minimum = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return minimum;
    }
};

int main() {
    int N;
    cin >> N;

    MinHeap h;

    for (int i = 0; i < N; i++) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int x;
            cin >> x;
            h.insert(x);
        } 
        else if (operation == "peek") {
            cout << h.peek() << '\n';
        } 
        else if (operation == "extractMin") {
            cout << h.extractMin() << '\n';
        }
    }

    return 0;
}
