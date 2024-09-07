#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10000];  // Adjacency list for the graph
int visited[10000];        // Visited array to track which nodes are visited

// DFS function to count how many nodes can be visited from the source node `src`
int dfs(int src, int &c) {
    visited[src] = 1;  // Mark the current node as visited

    for (int child : graph[src]) {  // Traverse all neighbors (children) of the current node
        if (visited[child] == 0) {  // If the child node is not visited
            c++;                    // Increment the count of visited nodes
            dfs(child, c);          // Recursively visit the child node
        }
    }
    return c;  // Return the total count of visited nodes
}

int main() {
    memset(visited, 0, sizeof(visited));  // Initialize visited array to 0
    int node, edge;
    cin >> node >> edge;  // Input the number of nodes and edges

    int u, v;
    while (edge--) {
        cin >> u >> v;
        graph[u].push_back(v);  // Create the undirected graph
        graph[v].push_back(u);  // Since it's undirected, add both edges
    }

    int N;
    cin >> N;  // Input the node from which we start the DFS

    int c = 1;  // Start counting from 1 since the node `N` itself is visited
    int ans = dfs(N, c);  // Perform DFS from node `N`

    cout << ans << endl;  // Output the total number of nodes visited

    return 0;
}
