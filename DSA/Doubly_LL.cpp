#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void ins_tail(Node*& head, Node*& tail, int val) {
    Node* newnode = new Node(val);
    if (tail == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = tail->next;
}

void print(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_Reverse(Node* tail) {
    Node* tmp = tail;
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void ins_at_head(Node*& head, Node*& tail, int val) {
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    return;
}

int sizee(Node* head) {
    int sz = 0;
    Node* tmp = head;
    while (tmp != NULL) {
        sz++;
        tmp = tmp->next;
    }
    return sz;
}

void ins_at_pos(Node* head, int pos, int val) {
    Node* newnode = new Node(val);
    Node* tmp = head;
    for (int i = 1; i < pos; i++) {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    if (tmp->next != NULL) {
        tmp->next->prev = newnode;
    }
    tmp->next = newnode;
    newnode->prev = tmp;
    return;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    while (true) {
        cin >> val;
        if (val == -1) break;
        ins_tail(head, tail, val);
    }
    print(head);
    cout << "Enter val and pos" << endl;
    int x, pos;
    cin >> x >> pos;
    if (pos == 0) {
        ins_at_head(head, tail, x);
    }
    else if (pos == sizee(head)) {
        ins_tail(head, tail, x);
    }
    else if (pos > sizee(head)) {
        cout << "Invalid" << endl;
    }
    else {
        ins_at_pos(head, pos, x);
    }
    print(head);
}
