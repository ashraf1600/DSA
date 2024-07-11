#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next = NULL;
        Node* prev = NULL;
        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

void push(Node*& head, Node*& tail, int val) {
    Node* newnode = new Node(val);
    if (tail == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    return;
}

void pop(Node*& head, Node*& tail) {
    if (tail == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* poped = tail;
    if (tail->prev != NULL) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        head = NULL; // If there's only one node, set both head and tail to NULL
        tail = NULL;
    }
    delete poped;
    return;
}

int Top(Node* tail) {
    if (tail == NULL) {
        return -1; // Indicates the stack is empty
    }
    return tail->data;
}

bool areStacksEqual(Node* head1, Node* tail1, Node* head2, Node* tail2) {
    Node* tmp1 = head1;
    Node* tmp2 = head2;

    while (tmp1 != NULL && tmp2 != NULL) {
        if (tmp1->data != tmp2->data) {
            return false;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    // If one stack is longer than the other, they are not equal
    return tmp1 == NULL && tmp2 == NULL;
}

int main() {
    int n, m;

    // Stack 1
    Node* head1 = NULL;
    Node* tail1 = NULL;

    // Stack 2
    Node* head2 = NULL;
    Node* tail2 = NULL;

    // Reading first stack
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        push(head1, tail1, value);
    }

    // Reading second stack
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int value;
        cin >> value;
        push(head2, tail2, value);
    }

    // Checking if stacks are equal
    if (areStacksEqual(head1, tail1, head2, tail2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
