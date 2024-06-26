#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
	{
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp!= NULL)
	{
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void make_uniq(Node *&head)
{
    Node * i = head;

    while (  i!=NULL && i->next!= NULL)
		{
        Node *j = i;
        while (j->next != NULL)
		{
            if (j->next->val == i->val)
			{
                Node *del_node = j->next;
                j->next = j->next->next;
                delete del_node;
            }
             else
            {
                j = j->next;
            }
        }

        i= i->next;
    }
}

int main()
 {
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
	{
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head, tail, val);
    }
    make_uniq(head);
    print_linked_list(head);
}
