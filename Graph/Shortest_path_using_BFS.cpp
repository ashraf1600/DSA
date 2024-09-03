#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
int vis[1000];
int par_tr[1000];

void BFS(int src, int des) {
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    par_tr[src] = -1;  // Set the source's parent to -1

    while (!q.empty()) {
        int par = q.front();
        q.pop();

        for (int child : adj[par]) {
            if (!vis[child]) {
                vis[child] = 1;
                q.push(child);
                par_tr[child] = par;

                if (child == des) return;  // Stop BFS when destination is found
            }
        }
    }
}

vector<int> shortest_path(int d) {
    vector<int> ans;

    // If the destination was never visited, return an empty path
    if (!vis[d]) return ans;

    // Trace the path from destination to source
    for (int at = d; at != -1; at = par_tr[at]) {
        ans.push_back(at);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    memset(vis, 0, sizeof(vis));
    memset(par_tr, -1, sizeof(par_tr));

    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int source, destination;
    cin >> source >> destination;

    BFS(source, destination);
    vector<int> path = shortest_path(destination);

    if (path.empty()) {
        cout << "No path found from " << source << " to " << destination << endl;
    } else {
        for (int u : path) {
            cout << u << " ";
        }
        cout << endl;
    }

    return 0;
}
