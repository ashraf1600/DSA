#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10000];
int visited[10000];
int dfs(int src,int des)
{
    visited[src] = 1;
    for (int child : graph[src])
		{
        if (visited[child] == 0)
        {

        }
    }
    return c;
}

int main()
{
    memset(visited, 0, sizeof(visited));
    int node, edge;
    cin >> node >> edge;
    int u, v;
    while(edge--)
	{
        cin>>u>>v;
        graph[u].push_back(v);
    }

    int q;
    cin>>q;
    int a,b;
    while(q--)
	{
       cin>>a>>b;
      cout<< dfs(a,b)<<" ";
	}


}

