#include<bits/stdc++.h>
using namespace std;
const int N=1e5+123;
vector<int>graph[N];
bool vis[N];
void dfs(int source)
{
	cout<<source<<" ";
	vis[source]=true;
	for(int child:graph[source])
	{
		if(vis[child]==false)
		{
			dfs(child);
		}
	}
}
int main()
{
	memset(vis,false,sizeof(vis));
	int n,e;
	cin>>n>>e;
	int a,b;
	while(e--)
	{
      cin>>a>>b;
      graph[a].push_back(b);
      graph[b].push_back(a);
	}
	int src;
	cin>>src;
	dfs(src);
}
