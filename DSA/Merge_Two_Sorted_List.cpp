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
void Merge(Node * &mhead,Node * &mtail,Node * head1,Node * head2)
{
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data<=head2->data)
		{
			create_linked_list(mhead,mtail,head1->data);
			head1=head1->next;
		}
		else
		{
			create_linked_list(mhead,mtail,head2->data);
			head2=head2->next;
		}
	}
	while(head1!=NULL)
	{
		create_linked_list(mhead,mtail,head1->data);
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		create_linked_list(mhead,mtail,head2->data);
		head2=head2->next;
	}
}
void Display(Node * head)
{
	Node * tmp=head;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	cout<<endl;
}
int main()
{
	Node * head1=NULL;
	Node * tail1=NULL;
	Node * head2=NULL;
	Node * tail2=NULL;
	Node * mhead=NULL;
	Node * mtail=NULL;
	int val1;
	int val2;
	int s1=0;
	int s2=0;
	while(true)
	{   cin>>val1;
		if(val1==-1) break;
		s1++;
		create_linked_list(head1,tail1,val1);
	}
	while(true)
	{
		cin>>val2;
		if(val2==-1) break;
		s2++;
		create_linked_list(head2,tail2,val2);
	}
	Merge(mhead,mtail,head1,head2);
	Display(head1);
	cout<<"-------------------"<<endl;
	Display(head2);
	cout<<"-------------------"<<endl;
	Display(mhead);


}
