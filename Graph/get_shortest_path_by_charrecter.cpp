#include<bits/stdc++.h>
using namespace std;
const int MAX = 1005;  // Maximum size for grid
int n, m;
char arr[MAX][MAX];    // Grid array containing '.', '#', 'A', 'B'
bool vis[MAX][MAX];    // Visited array
int dis[MAX][MAX];     // Distance array
pair<int, int> parent[MAX][MAX];  // To store the parent cell of each cell for path reconstruction
string path;

// Directions for moving up, down, left, right
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<char> dir_char = {'R', 'L', 'U', 'D'};  // Directions: Right, Left, Up, Down

// Check if the next position is within bounds and valid
bool isvalid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (arr[i][j] == '#')  // Can't move into walls
        return false;
    return true;
}

// BFS traversal
bool bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty()) {
        pair<int, int> pr = q.front();
        int pi = pr.first;
        int pj = pr.second;
        q.pop();

        // If we've reached 'B', stop BFS
        if (arr[pi][pj] == 'B') {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int ci = pi + directions[i].first;
            int cj = pj + directions[i].second;
            if (isvalid(ci, cj) && !vis[ci][cj]) {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[pi][pj] + 1;  // Update distance
                parent[ci][cj] = {pi, pj};      // Store the parent cell for path reconstruction
            }
        }
    }
    return false;  // If 'B' is not reachable
}

// Function to reconstruct the path from 'A' to 'B' using parent array
void get_path(int ei, int ej)
{
    while (arr[ei][ej] != 'A')
	{
        pair<int, int> p = parent[ei][ej];
        int pi = p.first;
        int pj = p.second;

        // Determine direction based on movement from parent to current cell
        if (pi == ei) {
            if (pj < ej)
                path.push_back('R');
            else
                path.push_back('L');
        } else {
            if (pi < ei)
                path.push_back('D');
            else
                path.push_back('U');
        }

        ei = pi;
        ej = pj;
    }
    reverse(path.begin(),path.end());
}

int main() {
    memset(vis, false, sizeof(vis));   // Initialize visited array
    memset(dis, -1, sizeof(dis));      // Initialize distance array

    // Input for grid dimensions
    cin >> n >> m;

    pair<int, int> start, end;

    // Input for the grid values and find the positions of 'A' and 'B'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'A') {
                start = {i, j};
            } else if (arr[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    // Perform BFS from the starting position 'A'
    if (bfs(start.first, start.second))
	{
        cout << "YES\n";
		get_path(end.first, end.second);
        cout<<path.size()<<endl;
        for(auto u:path)
		{
			cout<<u;
		}
		cout<<endl;
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}

