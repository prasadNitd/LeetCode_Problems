#include<bits/stdc++.h>
#include <chrono> 
using namespace std;
using namespace std::chrono; 
int knapSack(vector<int>& wt, vector<int>& val, int W, int n)
{
	if(n==0 || W==0)
		return 0;
	if(wt[n-1] <= W)
		return max(val[n-1]+knapSack(wt, val, W-wt[n-1], n-1), knapSack(wt, val, W, n-1));
	return knapSack(wt, val, W, n-1);
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