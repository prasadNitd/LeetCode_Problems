// Refer leetcode problem
#include<bits/stdc++.h>
using namespace std;
#define MAXM 1005
void printSoln(int n, int soln[][MAXM])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << soln[i][j] << ' ';
		cout << endl;
	}
}
bool isSafe(int soln[][MAXM], int i, int col, int n)
{
	for(int j=0;j<col;j++)
	{
		if(soln[i][j])
			return false;
	}

	for(int r=i, c=col;r>=0 && c>=0;r--, c--)
	{
		if(soln[r][c])
			return false;
	}

	for(int r=i, c=col;r<n && c>=0;r++, c--)
	{
		if(soln[r][c])
			return false;
	}

	return true;
}
bool NQueenUtil(int n, int soln[][MAXM], int col)
{
	if(col>=n)
		return true;

	for(int i=0;i<n;i++)
	{
		if(isSafe(soln, i, col, n))
		{
			soln[i][col] = 1;

			if(NQueenUtil(n, soln, col+1))
				return true;

			soln[i][col] = 0;
		}
	}
	return false;
}
void findNQueen(int n)
{
	int soln[MAXM][MAXM];
	memset(soln, 0, sizeof(soln));
	if(NQueenUtil(n, soln, 0))
	{
		cout << "One of the possible solution: " << endl;
		printSoln(n, soln);
	}
	else
		cout << "Solution doesn't exist\n";
}
int main()
{
	int n;
	cin >> n;
	findNQueen(n);
	return 0;
}