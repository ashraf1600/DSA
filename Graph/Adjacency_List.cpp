#include<bits/stdc++.h>
using namespace std;
int main()
{
	int nodes,edges;
	cin>>nodes>>edges;
	vector<int> mat[nodes];
	while(edges--)
	{
		 int a,b;
		 cin>>a>>b;
         mat[a].push_back(b);  //as undirected graph
         mat[b].push_back(a);  //as undirected graph
	}
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

}

