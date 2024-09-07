#include<bits/stdc++.h>
using namespace std;
const int N=1e5+123;
int n,m;
int arr[N][N];
bool vis[N][N];
vector<pair<int,int>>p={{0,1},{0,-1},{-1,0},{1,0}};
bool isvalid(int i,int j)
{
	if(i<0 || i>=n||j>=m||j<0)
	return false;
	return true;
}
void dfs(int si,int sj)
{
	cout<<arr[si][sj]<<" ";
	vis[si][sj]=true;
	for(int i=0;i<4;i++)
	{
		int ci=si+p[i].first;
		int cj=sj+p[i].second;
		if(isvalid(ci,cj)&& !vis[ci][cj])
		{
			dfs(ci,cj);
		}

	}

}

int main()
{
	memset(vis,false,sizeof(vis));
	cin>>n>>m;
	for(int i=0;i,n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	int si,sj;
	cin>>si,sj;
	dfs(si,sj);

}
