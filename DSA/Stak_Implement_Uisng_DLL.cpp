#include<bits/stdc++.h>
using namespace std;
class Node
{
	    public:
		int data;
		Node*next=NULL;
		Node*prev=NULL;
		Node(int data)
		{
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
		}
};
void push(Node*&head,Node*&tail,int val)
{
	Node*newnode=new Node(val);
     if(tail==NULL)
	 {
          head=newnode;
          tail=newnode;
          return;
	 }
	 tail->next=newnode;
	 newnode->prev=tail;
	 tail=newnode;
	 return;
}
void pop(Node*&head,Node*&tail)
{
	if(tail==NULL)
	{
		cout<<"stack is empty"<<endl;
		return;
	}
	Node*poped=tail;
	if(tail->prev!=NULL)
	{
	tail=tail->prev;
	tail->next=NULL;
	}
	else
	{
       head=NULL;//jodi ekti matro node thake tahole shetai
                 //head and tail and they are NULL
	   tail=NULL;
	}
	delete poped;
	return;
}
void Top(Node * tail)
{
	if(tail==NULL)
	{
		cout<<"The stack is empty"<<endl;
		return;
	}
	cout<<tail->data<<endl;
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
	return;
}
int main()
{
	Node*head=NULL;
	Node*tail=NULL;
	int val;
	while(true)
	{
		cout<<"OPTION 1: Push "<<endl;
		cout<<"OPTION 2: Pop "<<endl;
	    cout<<"OPTION 3: print top"<<endl;
	    cout<<"OPTION 4: print stack"<<endl;
		int x;
		cin>>x;
		if(x==1)
		{
		 cin>>val;
		 push(head,tail,val);
		 //print(head);
		}
		else if(x==2)
		{
		pop(head,tail);
		//print(head);
		}
		else if(x==3)
		{
			Top(tail);

		}
		else if(x==4)
		{
			print(head);
		}
		else break;
	}

}
