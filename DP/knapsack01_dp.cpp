#include<bits/stdc++.h>
#include <chrono> 
using namespace std;
using namespace std::chrono; 
int memo[105][1005];
int knapSack(vector<int>& wt, vector<int>& val, int W, int n)
{
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<W+1;j++)
		{
			if(i==0 || j==0)
				memo[i][j] = 0;
			else
			{
				if(wt[i-1] <= j)
					memo[i][j] = max(val[i-1] + memo[i-1][j-wt[i-1]], memo[i-1][j]);
				else
					memo[i][j] = memo[i-1][j];
			}
		}
	}
	return memo[n][W];
}
int main()
{
	int n, w;
	cin >> n >> w;
	vector<int> val(n), wt(n);

	for(int i=0;i<n;i++)
	{
		cin >> val[i] >> wt[i];
	}
	auto start = high_resolution_clock::now(); 
    
	cout << knapSack(wt, val, w, n) << endl;

	auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << duration.count() << " microseconds" << endl; 
	return 0;
}