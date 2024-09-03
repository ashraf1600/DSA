#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
int vis[10000000];
int par[10000000];

void make_tree(Node *root, int b)
{
    queue<Node *>q;
    q.push(root);
    par[root->data] = -1;  // The root's parent is -1

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        int pr = f->data;
        if (pr <= b)
        {
            if (2 * pr <= b)
            {
                f->left = new Node(2 * pr);
                q.push(f->left);
                par[2 * pr] = pr;  // Set parent for left child
            }
            if (10 * pr + 1 <= b)
            {
                f->right = new Node(10 * pr + 1);
                q.push(f->right);
                par[10 * pr + 1] = pr;  // Set parent for right child
            }
        }
    }
}

void level_order_print(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
       // cout<<f->data<<" ";
        vis[f->data]=1;
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

int main()
{
	memset(vis,0,sizeof(vis));
	memset(par,-1,sizeof(par));
	vector<int>ans;
    int a, b;
    cin >> a >> b;
    Node *root = new Node(a);
	// Using unordered_map for parent tracking
    make_tree(root,b);

    // Print the tree using level order
    level_order_print(root);

    // Print parent tracking
    if(vis[b]!=1)
	{
		cout<<"NO"<<endl;
	}
	else
	{
	 cout<<"YES"<<endl;
	for (int at = b; at != -1; at = par[at])
	{
        ans.push_back(at);
    }

    reverse(ans.begin(), ans.end());
	  cout<<ans.size()<<endl;
	  for(auto u: ans)
	  {
		cout<<u<<" ";
	  }
	}

    return 0;
}
