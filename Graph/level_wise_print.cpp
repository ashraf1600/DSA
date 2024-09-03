#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10000];
vector<bool>vis(10000,false);
vector<int>par(10000,-1);
vector<int> bfs(int src,int lvl)//u will be given a level the print that levls all elemnt
{
	vector<int>p[1000];
	queue<pair<int,int>>q;
	q.push({src,0});
	p[0].push_back(src);
	vis[src]=true;
	while(!q.empty())
	{
		pair<int,int> fr=q.front();
		int pr=fr.first;
		int l=fr.second;
		p[l].push_back(pr);
		q.pop();
		for(int child:adj[pr])
		{
           if(!vis[child])
		   {
		   	q.push({child,l+1});
		   	vis[child]=true;
		   	par[child]=pr;

		   }

		}
	}
	sort(p[lvl].begin(),p[lvl].end(),greater<int>());
	return p[lvl];
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
	  int level;
	  cin>>level;
	  vector<int>ans=bfs(0,level);
	  for(auto u: ans)
	  {
		cout<<u<<" ";
	  }

}


