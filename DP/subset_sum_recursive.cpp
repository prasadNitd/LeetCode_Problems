#include<bits/stdc++.h>
#include <chrono> 
using namespace std;
using namespace std::chrono; 
bool subsetSum(vector<int>& arr, int sum, int n)
{
	if(sum==0)
		return true;
	if(n==0)
		return false;
	if(arr[n-1] <= sum)
	{
		return subsetSum(arr, sum-arr[n-1], n-1) | subsetSum(arr, sum, n-1);
	}
	return subsetSum(arr, sum, n-1);
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
    
	cout << subsetSum(arr, sum, n) << endl;

	auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << duration.count() << " microseconds" << endl; 
	return 0;
}