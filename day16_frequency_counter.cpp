#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> frequency;

    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }

    for (auto x : frequency) {
        cout << x.first << ":" << x.second << " ";
    }

    return 0;
}