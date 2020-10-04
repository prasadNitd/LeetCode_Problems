// Movement in all directions allowed
// Print all possible path in lexicographical order

#include<bits/stdc++.h>
#define MAXM 1005
using namespace std;
void printPath(vector<string> possiblePaths)
{
	for(int i=0;i<possiblePaths.size();i++)
	{
		cout << possiblePaths[i] << endl;
	}
}
bool isSafe(int x, int y, int n, int mat[][MAXM], bool visited[][MAXM])
{
	if(x>=0 && x<n && y>=0 && y<n && mat[x][y] && !visited[x][y])
		return true;
	return false;
}
void findPathUtil(int x, int y, int n, int mat[][MAXM], vector<string> &possiblePaths, string& path, bool visited[][MAXM])
{
	if(!isSafe)
		return;

	if(x==n-1 && y==n-1)
	{
		possiblePaths.push_back(path);
		return;
	}

	visited[x][y] = true;

	if(isSafe(x+1, y, n, mat, visited))
	{
		path += 'D';
		findPathUtil(x+1, y, n, mat, possiblePaths, path, visited);
		path.pop_back();
	}

	if(isSafe(x, y-1, n, mat, visited))
	{
		path += 'L';
		findPathUtil(x, y-1, n, mat, possiblePaths, path, visited);
		path.pop_back();
	}

	if(isSafe(x, y+1, n, mat, visited))
	{
		path += 'R';
		findPathUtil(x, y+1, n, mat, possiblePaths, path, visited);
		path.pop_back();
	}

	if(isSafe(x-1, y, n, mat, visited))
	{
		path += 'U';
		findPathUtil(x-1, y, n, mat, possiblePaths, path, visited);
		path.pop_back();
	}

	visited[x][y] = false;
}
void findPath(int n, int mat[][MAXM])
{
	vector<string> possiblePaths;
	string path;
	bool visited[MAXM][MAXM];
	memset(visited, false, sizeof(visited));
	findPathUtil(0, 0, n, mat, possiblePaths, path, visited);
	if(possiblePaths.size())
	{
		cout << "Path Exist\n";
		printPath(possiblePaths);
	}
	else
		cout << "Path doesn't exist\n";
}
int main()
{
	int n;
	cin >> n;

	// 1 -> Path
	// 0 -> Wall
	int mat[MAXM][MAXM];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> mat[i][j];
		}
	}
	findPath(n, mat);
}