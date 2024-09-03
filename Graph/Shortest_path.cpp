#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10000];
vector<bool>vis(10000,false);
vector<int>par(10000,-1);
int bfs(int src,int des)
{
	queue<int>q;
	q.push(src);
	vis[src]=true;
	while(!q.empty())
	{
		int pr=q.front();
		q.pop();
		for(int child:adj[pr])
		{
           if(!vis[child])
		   {
		   	q.push(child);
		   	vis[child]=true;
		   	par[child]=pr;
		   }

		}
	}
	if(vis[des]==false)
	{
		return -1 ;
	}
	int dis=0;
	int x=des;
	//cout<<x<<" ";
	while(x!=-1)
	{
		dis++;
		x=par[x];
		//cout<<x<<" ";
	}
	return dis-1;
}
int main()
{
	int n,e;
	cin>>n>>e;
	while(e--)
	{
		int v1,v2;
		cin>>v1>>v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	int q;
	cin>>q;
	int s,d;
	while(q--)
	{
	fill(vis.begin(),vis.end(),false);
	fill(par.begin(),par.end(),-1);
	cin>>s>>d;
	 int ans=bfs(s,d);
	 cout<<ans<<endl;

	}
}
