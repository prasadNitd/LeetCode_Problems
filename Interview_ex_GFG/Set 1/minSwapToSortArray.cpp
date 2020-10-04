// Minimum number of swaps required to sort an array

// Time Complexity: O(n) + O(n) + O(nlogn) + O(2n) ~= O(nlogn)
// Space Complexity: O(n) + O(n) ~= O(n)

#include<bits/stdc++.h>
using namespace std;
struct valuePair
{
	int val, index;
};
bool compare(valuePair a, valuePair b)
{
	return a.val < b.val;
}
int minSwapsToSortArray(int a[], int n)
{
	valuePair arr[n];
	bool vis[n] = {false};
	for(int i=0;i<n;i++) // 2
	{
		arr[i].val = a[i];
		arr[i].index = i;
	}

	sort(arr, arr+n, compare); // 3

	int cycleSize = 0, ans = 0;
	for(int i=0;i<n;i++) // 4
	{
		if(vis[i] || arr[i].index==i)
			continue;
		int j = i;
		cycleSize = 0;
		while(!vis[j])
		{
			vis[j] = 1;
			j = arr[j].index;
			cycleSize++;
		}
		ans += (cycleSize-1);
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) // 1
		cin >> a[i];
	cout << minSwapsToSortArray(a, n) << endl;
}