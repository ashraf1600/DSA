#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node * next;
	Node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
};
void create_linked_list(Node * &head,Node * &tail,int val)
{
	Node * newnode=new Node(val);
	if(head==NULL && tail==NULL)
	{
		head=newnode;
		tail=newnode;
		return;
	}
	tail->next=newnode;
	tail=newnode;
	return;
}
void print_list(Node * head)
{
	Node * tmp=head;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	cout<<endl;
}
void sort_des(Node * head)
{
	Node * tmp=head;
	for(Node * i=tmp;i->next!=NULL;i=i->next)
	{
		for(Node * j=i->next;j!=NULL;j=j->next)
		{
             if(i->data<j->data)
			 {
				swap(i->data,j->data);
			 }
		}
	}
}
int main()
{
	Node * head=NULL;
	Node * tail=NULL;
	int val;
	while(true)
	{
		cin>>val;
		if(val==-1) break;
		create_linked_list(head,tail,val);
	}
	sort_des(head);
	print_list(head);
}

