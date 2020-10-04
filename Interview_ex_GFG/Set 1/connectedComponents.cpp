// Find number of connected components in an undirected graph

// Time Complexity: O(edges^2)
// Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
vector<int> par;
int find(int x)
{
    if(x == par[x])
        return x;
    return par[x] = find(par[x]);
}
void unionAlgo(int s, int d)
{
    int x = find(s);
    int y = find(d);
    
    if(x!=y)
    {
        par[x] = y;
    }
}
int countComponents(int n, vector<vector<int>>& edges) 
{
    int ans = 0;
    par.resize(n, 0);
    for(int i=0;i<n;i++)
        par[i] = i;
    for(int i=0;i<edges.size();i++)
    {
        int s = edges[i][0];
        int d = edges[i][1];
        unionAlgo(s, d);
    }
    for(int i=0;i<n;i++)
    {
        if(par[i]==i)
            ans++;
    }
    return ans;
}
int main()
{
    int n, e, x, y;
    cin >> n >> e;
    vector<vector<int>> edges;
    for(int i=0;i<e;i++)
    {
        cin >> x >> y;
        edges.push_back({x, y});
    }
    cout << countComponents(n, edges);
    return 0;
}