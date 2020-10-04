// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

// For example,

// Given [[0, 30],[5, 10],[15, 20]],
// return 2.

#include<bits/stdc++.h>
using namespace std;
struct meetings
{
	int start, end;
};

int main()
{
	int n;
	cin >> n;
	if(n<=0)
		return 0;
	meetings schedule[n];

	for(int i=0;i<n;i++)
	{
		cin >> schedule[i].start >> schedule[i].end;
	}

	
}