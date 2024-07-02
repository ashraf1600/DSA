#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void ins_at_tail(Node*& head1, Node*& tail1, int dig)
{
    Node* newnode = new Node(dig);
    if (head1 == NULL) {
        head1 = newnode;
        tail1 = newnode;
        return;
    }
    tail1->next = newnode;
    tail1 = tail1->next;
}

void Add_Two_Num(Node* head1, Node* head2, Node*& head, Node*& tail)
{
    int carry = 0;

    while (head1 != NULL || head2 != NULL) {
        int sum = carry;
        if (head1 != NULL) {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            sum += head2->data;
            head2 = head2->next;
        }

        Node* newnode = new Node(sum % 10);
        carry = sum / 10;

        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = tail->next;
        }
    }

    if (carry) {
        Node* newnode = new Node(carry);
        tail->next = newnode;
        tail = tail->next;
    }
}

void print(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    Node* head = NULL;
    Node* tail = NULL;

    cout << "Give your two numbers:" << endl;
    int n1, n2;
    cin >> n1 >> n2;

    while (n1 > 0) {
        int r = n1 % 10;
        ins_at_tail(head1, tail1, r);
        n1 = n1 / 10;
    }
    print(head1);

    while (n2 > 0) {
        int r = n2 % 10;
        ins_at_tail(head2, tail2, r);
        n2 = n2 / 10;
    }
    print(head2);

    Add_Two_Num(head1, head2, head, tail);
    print(head);

    return 0;
}
