/* 
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.

Time Complexity: O(M.N)
Auxillary Space: O(M.N)

*/
#include<bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<int, int>> bfs, dummy;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
                bfs.push({i, j});
        }
    }
    vector<pair<int, int>> dir({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
    int counter = 0;
    bfs.push({-1, -1});
    while(!bfs.empty())
    {
        pair<int, int> curr = bfs.front();
        bfs.pop();
        for(auto i: dir)
        {
            int x = curr.first + i.first;
            int y = curr.second + i.second;
            
            if(x<0 || x>=n || y<0 || y>=m || grid[x][y]!=1)
                continue;
            grid[x][y] = 2;
            dummy.push({x, y});
        }
        if(bfs.empty() && !dummy.empty())
        {
            while(!dummy.empty())
            {
                bfs.push(dummy.front());
                dummy.pop();
            }
            counter++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
                return -1;
        }
    }
    return counter;
}
int main()
{
    int n, m, x;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> x;
            grid[i][j] = x;
        }
    }
    cout << orangesRotting(grid) << endl;
    return 0;
}