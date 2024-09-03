#include<bits/stdc++.h>
using namespace std;
int vis[1000];
vector<int> adj[1000];
int level[1000];

void BFS(int source) {
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    level[source]=0;
    while(!q.empty()) {
        int parent = q.front();
        cout << parent << " ";
        q.pop();
        for(auto child:adj[par])
		{
            if(vis[child] == 0)
			{
                q.push(child);
                vis[child] = 1;
			level[child]=level[parent]+1;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    // Ensure all nodes are marked as unvisited at the start
    memset(vis, 0, sizeof(vis));
    memset(level,-1,sizeof(level));

    while(e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    BFS(0); // Assuming you start BFS from node 0
    return 0;
}
