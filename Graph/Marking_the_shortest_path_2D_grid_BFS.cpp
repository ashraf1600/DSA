/*
###Question
---------------
Rezia is trapped in a 2D maze of N*M size, starting at position R, and her goal is to reach the exit marked by D. The maze contains blocks represented by #, and she can only traverse through cells marked with dots (.). As she need to escape as early as possible, we need to determine the path she will follow.

Place an X in each cell representing Rezia's route to exit the maze. If there is no viable path for her to exit, leave the maze unchanged.

Note: Rezia can move in four directions – right, left, up, and down. It is crucial to adhere to the specified order: attempting right first, then left, followed by up, and finally down.

Input Format

First line will contain  and .
Next you will be given the 2D matrix.
Constraints

Output Format

Output the final maze with marked X indicating the path she will follow.
Sample Input 0

5 6
...D.#
.##..#
....#.
.R#...
.#.##.
Sample Output 0

...D.#
.##X.#
.XXX#.
.R#...
.#.##.
Sample Input 1

5 6
...D.#
.R...#
....#.
..#...
.#.##.
Sample Output 1

...D.#
.RXX.#
....#.
..#...
.#.##.
Sample Input 2

5 6
...D.#
.....#
.##.#.
.R#...
.#.##.
Sample Output 2

...D.#
XXXX.#
X##.#.
XR#...
.#.##.
Sample Input 3

5 6
...D.#
.....#
###.#.
.R#...
.#.##.
Sample Output 3

...D.#
.....#
###.#.
.R#...
.#.##.
*/

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>>directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char maze[1005][1005];
pair<int, int> parent[1005][1005];
bool visited[1005][1005];

bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != '#' && !visited[x][y]);
}
bool bfs(int sx,int sy)
{
    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy]=true;
    parent[sx][sy]={-1, -1};

    while (!q.empty())
		{
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (maze[x][y] == 'D')
		{
            return true;
        }

        for (auto dir : directions)
		{
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (valid(nx, ny))
			{
                visited[nx][ny] = true;
                parent[nx][ny] = {x,y};
                q.push({nx, ny});
            }
        }
    }
    return false;
}

void mark_path(int ex, int ey)
{
    pair<int, int> current = {ex, ey};

    while (current != make_pair(-1, -1))
	{
        if (maze[current.first][current.second] != 'R' && maze[current.first][current.second] != 'D') {
            maze[current.first][current.second] = 'X';
        }
        current = parent[current.first][current.second];
    }
}

int main()
{
    cin >> n >> m;

    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
		{
            cin >> maze[i][j];
            if (maze[i][j] == 'R')
            {
                sx = i;
                sy = j;
            }
        }
    }
   memset(visited, false, sizeof(visited));
   if (bfs(sx, sy))
	{
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == 'D')
                {
                    mark_path(i, j);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
		{
        for (int j = 0; j < m; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}
