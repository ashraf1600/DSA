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
void ins_tail(Node*&head,Node*&tail,int val)
{
	Node*newnode=new Node(val);
	if(head==NULL)
	{
		head=newnode;
		tail=newnode;
		return;
	}
	tail->next=newnode;
	tail=newnode;
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
	cout<<endl;
}
bool has_cycle(Node*head)
{
	if(head==NULL || head->next==NULL)
	{
		return false;
	}
	Node*slow=head;
	Node*fast=head;
	while(slow!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			return true;
		}

	}
	return false;
}
int main()
{
	Node*head=NULL;
	Node*tail=NULL;
	int val;
	while(true)
	{
		cin>>val;
		if(val==-1) break;
		ins_tail(head,tail,val);


	}
	print(head);
	if(has_cycle(head))
	{
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;

}
