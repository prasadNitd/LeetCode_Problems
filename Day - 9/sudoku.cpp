// Refer Leetcode Problem
#include<bits/stdc++.h>
using namespace std;
#define n 9
#define UNASSIGNED 0
void printSoduku(int grid[][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << grid[i][j] << ' ';
		}
		cout << endl;
	}	
}
bool isSafe(int grid[][n])
{
	unordered_map<int, int> row[n], col[n], box[n];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int num = grid[i][j];
			row[i][num]++;
			col[j][num]++;
			box[(i/3)*3 + (j/3)][num]++;

			if(row[i][num]>1 || col[j][num]>1 || box[(i/3)*3 + (j/3)][num]>1)
				return false;
		}
	}
	return true;
}
bool solveSoduku(int grid[][n], int x, int y)
{
	if(x==n-1 && y==n)
	{
		if(isSafe(grid))
			return true;
		return false;
	}

	if(y==n)
	{
		x++;
		y = 0;
	}

	if(grid[x][y]!=UNASSIGNED)
		return solveSoduku(grid, x, y+1);

	for(int num=1;num<=9;num++)
	{
		grid[x][y] = num;

		if(solveSoduku(grid, x, y+1))
			return true;
		grid[x][y] = UNASSIGNED;
	}

	return false;
}
int main()
{
	int grid[n][n];

	if(!solveSoduku(grid, 0, 0))
		cout << "No solution exist\n";
	else
	{
		cout << "The solution is:\n";
		printSoduku(grid);
	}
}