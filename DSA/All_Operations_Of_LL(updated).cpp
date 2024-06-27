//max value print of LL size print and mid valur print of LL
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
void create_linked_list(Node*&head,Node*&tail,int val)
{
   Node * newnode=new Node(val);
   if(head==NULL && tail==NULL)
   {
	head=newnode;
	tail=newnode;
	return;
   }
   tail->next=newnode;
   tail=tail->next;
}
void print(Node * head)
{
   Node * tmp=head;
   while(tmp!=NULL)
   {
	cout<<tmp->data<<" ";
	tmp=tmp->next;
   }
}
void print_reverse(Node * head)
{
	Node * tmp=head;
	if(tmp==NULL)return;
	print_reverse(tmp->next);
	cout<<tmp->data<<" ";
}
void print_mid(Node * head,int sz)
{
   Node * tmp=head;
   if(sz%2!=0)
   {
	int mid =sz/2+1;
	for(int i=1;i<mid;i++)
	{
		tmp=tmp->next;
	}
	cout<<tmp->data<<endl;
   }
   else
   {
	int mid=sz/2;
   	for(int i=1;i<mid;i++)
	{
		tmp=tmp->next;
	}
	cout<<tmp->data<< " "<<tmp->next->data<<endl;;
   }
}
void print_max(Node * head)
{
	int maxv=INT_MIN;
	Node * tmp=head;
	while(tmp!=NULL)
	{
		//tmp=tmp->next;
		if(tmp->data>=maxv)
		{
			maxv=tmp->data;
		}
	 tmp=tmp->next;
	}
	cout<<"maxv="<<maxv<<endl;
}
int main()
{
	Node * head=NULL;
	Node * tail=NULL;
	int val;
	int cn=0;
	while(true)
	{
		cin>>val;
		if(val==-1)break;
		cn++;
		create_linked_list(head,tail,val);
	}
	print(head);
	cout<<endl;
	print_reverse(head);
	cout<<endl;
	cout<<"size : "<<cn<<endl;
	print_mid(head,cn);
	print_max(head);
	//cout<<midd<<endl;
}
