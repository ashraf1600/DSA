#include<bits/stdc++.h>
using namespace std;
int row,col;
char graph[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>>p = {{0,1},{0,-1},{-1,0},{1,0}};
bool isvalid(int si,int sj)
{
	if(si<0 || si>=row || sj<0 || sj>=col || graph[si][sj]=='#')
	{
		return false;
	}
	return true;
}
int DFS(int si,int sj)
{
	int c=1;
	vis[si][sj]=true;
	for(int i=0;i<4;i++)
	{
		int ci=si+p[i].first;
		int cj=sj+p[i].second;
		if(isvalid(ci,cj) && !vis[ci][cj])
		{
			c+=DFS(ci,cj);
		}
	}
	return c;
}
int main()
{
	memset(vis,false,sizeof(vis));
	cin>>row>>col;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>graph[i][j];
		}
	}
	vector<int>ans;
	int c=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(graph[i][j]=='.' && !vis[i][j])
			{

				int room=DFS(i,j);
				ans.push_back(room);
			}
		}
	}
	 sort(ans.begin(),ans.end());
	 if(ans.empty())
	 {
	 	cout<<0<<endl;

	 }
	 else
	 {
	 for(int u:ans)
	 {
	 	cout<<u<<" ";
	 }
	 cout<<endl;
	 }

}

