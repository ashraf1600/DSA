#include<bits/stdc++.h>
using namespace std;
const int N=1e5+123;
vector<int>graph[N];
bool vis[N];
int dfs(int src)
{
	int c=1;
    vis[src] = 1;  // Mark the current node as visited

    for (int child : graph[src]) {  // Traverse all neighbors (children) of the current node
        if (vis[child] == 0) {  // If the child node is not visited
							     // Increment the count of visited nodes
           c+=dfs(child);          // Recursively visit the child node
        }
    }
    return c;  // Return the total count of visited nodes
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
	vector<int>ans;
	 for( int i=0;i<n;i++)
	 {
		if(!vis[i])
		{
			ans.push_back(dfs(i));
		}
	 }
       sort(ans.begin(),ans.end());
       for(int u:ans)
	   {
	   	cout<<u<<" ";
	   }

}
