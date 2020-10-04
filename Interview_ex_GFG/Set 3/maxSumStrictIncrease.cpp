/*
Find Maximum Sum Strictly Increasing Subarray
Given an array of positive integers. Find the maximum sum of strictly increasing subarrays.

Examples:

Input  : arr[] = {1, 2, 3, 2, 5, 1, 7}
Output : 8
Explanation :  Some Strictly increasing subarrays are 
               {1, 2, 3} sum = 6, 
               {2, 5} sum = 7, 
               {1, 7} sum 8 
               Maximum Sum = 8 

Input : arr[] = {1, 2, 2, 4}
Output: 6
Explanation : Increasing subarray with maximum sum
              is 6.

Time complexity : O(n)
Auxiliary Space : O(1)
*/ 

#include<bits/stdc++.h>
using namespace std;

int maxSumStrictlyInc(int a[], int n)
{
	int curr = a[0], MAX = a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i] > a[i-1])
			curr += a[i];
		else
			curr = a[i];
		MAX = max(curr, MAX);
	}
	return MAX;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << maxSumStrictlyInc(a, n) << endl;
	return 0;
}