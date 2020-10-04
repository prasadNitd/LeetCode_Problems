// Minimum Swaps to sort array when only adjacent swappings are allowed
// This problem is same as counting inversions in an array

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int merge(int a[], int l, int r, int mid)
{
	int temp[r-l+1], inversions = 0;

	int i = l, j = mid+1, k = 0;

	while(i<=mid && j<=r)
	{
		if(a[i] <= a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			inversions += (mid - i + 1);
		}
	}

	while(i<=mid)
		temp[k++] = a[i++];

	while(j<=r)
		temp[k++] = a[j++];

	for(int i=l;i<=r;i++)
		a[i] = temp[i-l];

	return inversions;
}
int mergeSort(int a[], int l, int r)
{
	if(l >= r)
		return 0;

	int mid = l + (r-l)/2;

	int totalInversions = 0;

	totalInversions += mergeSort(a, l, mid);
	totalInversions += mergeSort(a, mid+1, r);

	return totalInversions + merge(a, l, r, mid);
}
int countInversions(int a[], int n)
{
	return mergeSort(a, 0, n-1);
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) // 1
		cin >> a[i];
	cout << countInversions(a, n) << endl;
}