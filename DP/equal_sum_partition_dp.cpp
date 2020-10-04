#include<bits/stdc++.h>
using namespace std;
int memo[105][1005];
bool subsetSum(vector<int>& arr, int sum, int n)
{
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0)
				memo[i][j] = 0;
			if(j==0)
				memo[i][j] = 1;
			if(i==0 || j==0)
				continue;
			if(arr[i-1] <= j)
			{
				memo[i][j] = memo[i-1][j-arr[i-1]] | memo[i-1][j];
			}
			else
				memo[i][j] = memo[i-1][j];
		}
	}
	return memo[n][sum];
}
int main()
{
	int n, sum = 0;
	cin >> n;
	vector<int> arr(n);

	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

    memset(memo, -1, sizeof(memo));
	if(!(sum%2) && subsetSum(arr, sum/2, n))
		cout << "POSSIBLE " << sum/2 << endl;
	else
		cout << "NOT POSSIBLE" << endl;  
	return 0;
}