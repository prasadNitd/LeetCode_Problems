#include<bits/stdc++.h>
#include <chrono> 
using namespace std;
using namespace std::chrono; 
int memo[105][1005];
bool subsetSum(vector<int>& arr, int sum, int n)
{
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		
{			if(i==0)
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
	int n, sum;
	cin >> n >> sum;
	vector<int> arr(n);

	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	auto start = high_resolution_clock::now(); 
    memset(memo, -1, sizeof(memo));
	cout << subsetSum(arr, sum, n) << endl;

	auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << duration.count() << " microseconds" << endl; 
	return 0;
}