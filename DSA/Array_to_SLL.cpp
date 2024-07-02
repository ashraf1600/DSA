#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void convert_arr_to_LL(int arr[], int n, Node*& head) {
    if (n == 0) return;
    head = new Node(arr[0]);
    Node* tmp = head;
    for (int i = 1; i < n; i++)
	{
        Node* newnode = new Node(arr[i]);
        tmp->next = newnode;
        tmp = tmp->next;
    }
}

int main()
 {
    cout << "Give your array" << endl;
    int n;
    cout<<"Size Of The array"<<endl;SS
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
	{
        cin >> arr[i];
    }
    Node * head1=NULL;
	convert_arr_to_LL(arr, n, head1);
	print(head1);


return 0;
}
