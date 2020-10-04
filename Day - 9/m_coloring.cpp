#include<bits/stdc++.h>
using namespace std;
#define MAXM 105
const int n = 4;
void printGraph(int color[], int n)
{
	for(int i=0;i<n;i++)
		cout << color[i] << ' ';
	cout << endl;
}
bool isSafe(int graph[][MAXM], int color[])
{

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(graph[i][j] && color[i]==color[j])
				return false;
		}
	}
	return true;
}
bool mColoring(int m, int graph[][MAXM], int color[], int curr)
{
	if(curr==n)
	{
		if(isSafe(graph, color))
			return true;
		return false;
	}
	for(int i=1;i<=m;i++)
	{
		color[curr] = i;

		if(mColoring(m, graph, color, curr+1))
			return true;

		color[curr] = 0;
	}
	return false;
}
int main()
{
	int m;
	cin >> m;
	int graph[MAXM][MAXM] = { 
        { 0, 1, 1, 1 }, 
        { 1, 0, 1, 0 }, 
        { 1, 1, 0, 1 }, 
        { 1, 0, 1, 0 }, 
    }; 
    int color[n+1] = {0};
    if(mColoring(m, graph, color, 0))
    {
    	cout << "Cooring possible\n";
    	printGraph(color, n);
    }
    else
    	cout << "Coloring not possible\n";
    return 0;
}