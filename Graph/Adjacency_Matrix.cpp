#include<bits/stdc++.h>
using namespace std;
int main()
{
	int nodes,edges;
	cin>>nodes>>edges;
	int mat[nodes][nodes];
	memset(mat,0,sizeof(mat));//initially all are zero
	while(edges--)
	{
		 int a,b;
		 cin>>a>>b;
		 mat[a][b]=1;
		 mat[b][a]=1;//as undirected graph
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
