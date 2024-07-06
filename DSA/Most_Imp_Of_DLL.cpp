
/*
Problem Statement

You have a doubly linked list which is empty initially. Then you will be given Q queries. In each query you will be given two values X and V.

You need to insert the value V at index X. Assume that index starts from 0.
After that for each query you need to print the linked list from left to right and right to left.
If the index is invalid, then print "Invalid".
Note: You must use Doubly Linked List, otherwise you will not get marks.

Input Format

First line will contain Q.
Next Q lines will contain X and V.
Constraints

1 <= Q <= 1000;
0 <= X <= 1000;
0 <= V <= 1000
Output Format

For each query print the linked list from left to right and right to left or print "Invalid" as asked.
Print "L -> " before printing the linked list from left to right.
Print "R -> " before printing the linked list from right to left.
Sample Input 0

5
1 10
0 10
1 20
3 30
2 30
Sample Output 0

Invalid
L -> 10
R -> 10
L -> 10 20
R -> 20 10
Invalid
L -> 10 20 30
R -> 30 20 10



*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

int size(Node*head)
{
    int l=0;
    Node*tmp=head;
    while (tmp!=NULL)
	{
        l++;
        tmp=tmp->next;
    }
    return l;
}
void ins_head(Node*&head,Node*&tail,int val)
{
    Node*newnode=new Node(val);
    if (head == NULL)
	{
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void ins_tail(Node*& head,Node*&tail,int val)
{
    Node* newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void ins_pos(Node*&head,Node*& tail,int pos, int val)
{
    int l = size(head);
    if (pos == 0)
	{
        ins_head(head, tail, val);
        return;
    }
	else if (pos==l)
	{
        ins_tail(head,tail,val);
        return;
    }
    else
    {
        Node* newnode = new Node(val);
        Node* tmp = head;
        for (int i = 1; i < pos; i++)
		{
            tmp = tmp->next;
        }
        newnode->next = tmp->next;
        if (tmp->next != NULL) {
            tmp->next->prev = newnode;
        }
        tmp->next = newnode;
        newnode->prev = tmp;
    }
}

void print(Node* head)
{
    Node* tmp = head;
    while (tmp != NULL)
	{
        cout<<tmp->data<< " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_rev(Node* tail)
{
    Node*tmp=tail;
    while (tmp != NULL)
	{
        cout<<tmp->data << " ";
        tmp=tmp->prev;
    }
    cout<<endl;
}

int main() {
    Node*head = NULL;
    Node*tail = NULL;
    int q;
    cin >> q;
    while (q--)
	{
        int x,v;
        cin >>x>>v;
        int l=size(head);
        if (x>l)
        {
            cout<<"Invalid"<<endl;
        }
	    else
        {
            ins_pos(head,tail,x,v);
            cout<<"L -> ";
            print(head);
            cout<<"R -> ";
            print_rev(tail);
        }
    }
    return 0;
}

