#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node*insrt_bst(Node*&root,int v)
{
	Node*newnode=new Node(v);
	if(root==NULL)
	{
		root=newnode;
		return root;
	}
	if(v<root->data)
	{
		root->left=insrt_bst(root->left,v);
	}
	else
	{
       root->right=insrt_bst(root->right,v);
	}
	return root;
}
void level_order_print(Node*root)
{
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
		Node*f=q.front();
		q.pop();
		cout<<f->data<<" ";
		if(f->left)
		{
			q.push(f->left);
		}
		if(f->right)
		{
			q.push(f->right);
		}
	}
	return;
}
int main()
{
	Node*root=NULL;
	int val;
	while(true)
	{
		cin>>val;
		if(val==-1)
		{
			break;
		}
		insrt_bst(root,val);
	}
	level_order_print(root);
}
