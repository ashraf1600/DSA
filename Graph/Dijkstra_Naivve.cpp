#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 123;
vector<pair<int, int>> graph[N];  // Adjacency list {node, weight}
int dis[N];  // Distance array to store shortest path distances from source node
void NaiveDijkstra(int src)
{
    dis[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});  // {node, cost}

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_node = par.first;
        int par_cost = par.second;

        for (pair<int, int> child : graph[par_node])
        {
            int child_node = child.first;
            int child_cost = child.second;

            // Relaxation: check if we found a shorter path to child_node
            if (par_cost + child_cost < dis[child_node])
            {
                dis[child_node] = par_cost + child_cost;
                q.push({child_node, dis[child_node]});  // Push the updated distance and node
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    // Initialize the distance array with infinity (a large value)
    for (int i = 0; i < N; i++) dis[i] = INT_MAX;

    // Read the edges
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});  // If the graph is undirected
    }

    int s;
    cin >> s;

    // Run the naive version of Dijkstra's algorithm
    NaiveDijkstra(s);

    // Output the shortest distances from source node s
    for (int i = 0; i < n; i++)
    {
        if (dis[i] == INT_MAX)
            cout << s << " -> " << i << " : No path" << endl;
        else
            cout << s << " -> " << i << " : Shortest cost distance = " << dis[i] << endl;
    }

    return 0;
}
