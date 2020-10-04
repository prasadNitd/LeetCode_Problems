// Only right and down movement is allowed
#include<bits/stdc++.h>
using namespace std;
#define MAXM 1005
void printPath(int n, int soln[][MAXM])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << soln[i][j] << ' ';
		cout << endl;
	}
}

bool isSafe(int x, int y, int n)
{
	if(x>=0 && x<n && y>=0 && y<n)
		return true;
	return false;
}

bool findPathUtil(int n, int x, int y, int mat[][MAXM], int soln[][MAXM])
{
	if(x==n-1 && y==n-1)
	{
		soln[x][y] = 1;
		return true;
	}
	if(mat[x][y]==1)
	{
	    soln[x][y] = 1;
		if(isSafe(x+1, y, n) && findPathUtil(n, x+1, y, mat, soln))
			return true;

		if(isSafe(x, y+1, n) && findPathUtil(n, x, y+1, mat, soln))
			return true;	
		soln[x][y] = 0;
	}
	return false;
}

void findPath(int n, int x, int y, int mat[][MAXM], int soln[][MAXM])
{
	if(!mat[0][0] || !mat[n-1][n-1])
		cout << "Path doesn't exist" << endl;

	if(findPathUtil(n, x, y, mat, soln))
	{
		cout << "Path Exist" << endl;
		printPath(n, soln);
	}
	else
		cout << "Path doesn't exist" << endl;
}

int main()
{
	int n, x, y;
	cin >> n;

	int mat[MAXM][MAXM], soln[MAXM][MAXM];
	// 0 -> Wall
	// 1 -> Path
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> mat[i][j];
			soln[i][j] = 0;
		}
	}
	x = 0; y = 0;
	findPath(n, x, y, mat, soln);
	return 0;
}