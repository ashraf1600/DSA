#include<bits/stdc++.h>
using namespace std;
 class Node
 {
   public:
 	int value;
 	Node*link;
 	Node(int val)
 	{
		this->value=val;
		this->link=NULL;
 	}

 };
 void ins_at_tail(Node * &head,int value)
 {
	Node * newnode=new Node(value);
	if(head==NULL)
	{
	  // newnode->link=head;
	   head=newnode;
	   return;
	}
	Node * temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=newnode;

 }
 void printList(Node*head)
 {
	Node * curNode=head;
	while(curNode!=NULL)
	{
		cout<<curNode->value<<" ";
		curNode=curNode->link;
	}
	cout<<endl;
 }
int main()
{
	Node * head=NULL;
	while(true)
	{
	  int val;
	  cin>>val;
	  if(val==-1) break;
	  ins_at_tail(head,val);
	}
	printList(head);

}
