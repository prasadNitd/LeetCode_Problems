#include<bits/stdc++.h>
using namespace std;

struct jobs
{
	int deadline, profit, id;
};

bool compareJobs(jobs a, jobs b)
{
	return a.profit > b.profit;
}

int maxProfit(jobs arr[], int n, int maxDeadline)
{
	int deadArr[maxDeadline+1] = {0}, j = -1, ans = 0;

	sort(arr, arr+n, compareJobs);

	for(int i=0;i<n;i++)
	{
		j = arr[i].deadline;
		while(j)
		{
			if(!deadArr[j])
			{
				deadArr[j] = arr[i].id;
				ans += arr[i].profit;
				break;
			}
			else
				j--;
		}
	}
	for(int i=1;i<=maxDeadline;i++)
	{
		if(deadArr[i])
		{
			cout << deadArr[i] << ' ';
		}
	}
	cout << endl;
	return ans;
}

int main()
{
	int n;
	cin >> n;

	jobs arr[n];
	int maxDeadline = -1;

	for(int i=0;i<n;i++)
	{
		cin >> arr[i].deadline >> arr[i].profit;
		arr[i].id = i+1;
		maxDeadline = max(maxDeadline, arr[i].deadline);
	}
	cout << maxProfit(arr, n, maxDeadline);
}