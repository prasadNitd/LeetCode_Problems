/*
Maximum sum such that no two elements are adjacent
Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).Answer the question in most efficient way.

Examples :

Input : arr[] = {5, 5, 10, 100, 10, 5}
Output : 110

Input : arr[] = {1, 2, 3}
Output : 4

Input : arr[] = {1, 20, 3}
Output : 20
*/
#include<bits/stdc++.h>
using namespace std;

int maxSum(int a[], int n)
{
	vector<int> ans(n, 0);

	for(int i=0;i<n;i++)
	{
		if(i<2)
			ans[i] = a[i];
		else
		{
			ans[i] = max(ans[i-1], ans[i-2] + a[i]);
		}
	}
	return ans[n-1];
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << maxSum(a, n) << endl;
	return 0;
}