
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int coefficient;
    int exponent;
    Node* next;

    Node(int c, int e) {
        coefficient = c;
        exponent = e;
        next = nullptr;
    }
};

Node* insertTerm(Node* head, int c, int e) {
    Node* newNode = new Node(c, e);

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

void sortPolynomial(Node*& head) {
    vector<pair<int, int>> terms;

    Node* current = head;

    while (current != nullptr) {
        terms.push_back({current->exponent, current->coefficient});
        current = current->next;
    }

    sort(terms.begin(), terms.end(), greater<pair<int, int>>());

    current = head;

    for (auto term : terms) {
        current->exponent = term.first;
        current->coefficient = term.second;
        current = current->next;
    }
}

void printPolynomial(Node* head) {
    if (head == nullptr) {
        cout << 0 << endl;
        return;
    }

    Node* current = head;
    bool first = true;

    while (current != nullptr) {
        int c = current->coefficient;
        int e = current->exponent;

        if (c != 0) {
            if (!first) {
                cout << (c > 0 ? " + " : " - ");
            } else if (c < 0) {
                cout << "-";
            }

            int absC = (c < 0 ? -c : c);

            if (e == 0 || absC != 1) {
                cout << absC;
            }

            if (e > 0) {
                cout << "x";
                if (e > 1) {
                    cout << "^" << e;
                }
            }

            first = false;
        }

        current = current->next;
    }

    if (first) {
        cout << 0;
    }

    cout << endl;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        int coefficient, exponent;
        cin >> coefficient >> exponent;

        head = insertTerm(head, coefficient, exponent);
    }

    sortPolynomial(head);
    printPolynomial(head);

    deleteList(head);

    return 0;
}
