
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node*next;
	Node(int data)
	{
		this->data=data;
		this->next=NULL;
	}

};
void ins_tail(Node*&head,int node)
{
	Node*newnode=new Node(node);
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	Node*tmp=head;

	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=newnode;
	//return;
}
void ins_at_any(Node * head,int val ,int pos)
{
	Node * newnode=new Node(val);
	Node * tmp=head;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	for(int i=1;i<pos;i++)
	{
		tmp=tmp->next;
	}
	newnode->next=tmp->next;
	tmp->next=newnode;
	return;
}
void print(Node*head)
{
	Node*tmp=head;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	return;
}
 void ins_at_head(Node * &head,int val)
{
	Node * newnode=new Node(val);
	newnode->next=head;
	head=newnode;
	return;
}
void del_at_pos(Node * head,int pos)
{
	Node*tmp=head;
	for(int i=1;i<pos;i++)
	{
		tmp=tmp->next;
	}
	Node * x=tmp->next;
	tmp->next=tmp->next->next;
	delete x;
}
int main()
{
	Node*head=NULL;
	while(true)
	{
	cout<<"OPTION 1 : Insert at tail"<<endl;
	cout<<"OPTION 2 : Print Linked List"<<endl;
	cout<<"OPTION 3 : Insert at any position"<<endl;
	cout<<"OPTION 4 : Insert at head"<<endl;
	cout<<"OPTION 5 : Delete from a position"<<endl;
	cout<<"OPTION  : Break"<<endl;

	int op;
	cin>>op;
	if(op==1)
	{
		cout<<"Put element in ur Linked list"<<endl;
		int node;
        cin>>node;
        ins_tail(head,node);

	}
	else if(op==2)
	{
	cout<<"Your Linked List is : ";
	print(head);
	cout<<endl;
	}
	else if(op==3)
	{
		cout<<"Put the value to be inserted at Nth position"<<endl;
		int val;
		cin>>val;
		cout<<"Enter the position"<<endl;
		int pos;
		cin>>pos;
		ins_at_any(head,val,pos);
	}
	else if(op==4)
	{
		cout<<"Put the value to be inserted at Head"<<endl;
		int val;
		cin>>val;
		ins_at_head(head,val);
	}
	else if(op==5)
	{
		cout<<"Enter the position to be deleted"<<endl;
		int pos;
		cin>>pos;
		del_at_pos(head,pos);
	}
	else break;
	}
return 0;
}
