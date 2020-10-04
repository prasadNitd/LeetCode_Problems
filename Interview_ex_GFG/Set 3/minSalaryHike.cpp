/*
Minimum salary hike for each employee such that no employee feels unfair
There are N employees in a company, and each employee has some ratings. The employees are given a hike in their salary based on their ratings, i.e.,
employees with higher ratings will get a higher hike in their salary. An employee only knows the hike and rating of its neighbors i.e., on the left
and right side of the employee. Given an array arr[] of N positive integers which denotes the ratings of N employees, the task is to find the minimum
hike that should be raised for each employee, such that no employee feels unfair.
Input: arr[] = {1, 3, 5, 4}
Output: 1 2 3 1
Explanation:
The distribution of minimum hike for each employee must be:
1 + 2 + 3 + 1 = 7

Input: arr[] = {5, 3, 4, 2, 1, 6}
Output: 2 1 3 2 1 2
Explanation:
The distribution of minimum hike for each employee must be:
2 + 1 + 3 + 2 + 1 + 2 = 11

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> minSalaryHike(int a[], int n)
{
	int MIN = INT_MAX, index;
	vector<int> ans(n);
	for(int i=0;i<n;i++)
	{
		if(a[i] < MIN)
		{
			MIN = a[i];
			index = i;
		}
	}
	ans[index] = 1;
	int i = index-1;
	while(i >= 0)
	{
		if(a[i]==a[i+1])
			ans[i] = ans[i+1];
		else if(a[i] > a[i+1])
			ans[i] = ans[i+1] + 1;
		else
		{
			int j = i;
			while(a[j] < a[j+1])
				j--;
			int diff = i - j;
			while(diff)
			{
				ans[i] = diff;
				diff--;
			}
			i = j + 1;
		}
		i--;
	}
	i = index + 1;
	while(i < n)
	{
		if(a[i]==a[i-1])
			ans[i] = ans[i+1];
		else if(a[i] > a[i-1])
			ans[i] = ans[i-1] + 1;
		else
		{
			int j = i;
			while(a[j] < a[j-1])
				j++;
			int diff = j - i;
			while(diff)
			{
				ans[i] = diff;
				diff--;
			}
			i = j - 1;
		}
		i++;
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	vector<int> ans = minSalaryHike(a, n);
	for(int i=0;i<n;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}