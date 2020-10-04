// Find zeroes to be flipped so that number of consecutive 1’s is maximized
// Given a binary array and an integer m, find the position of zeroes flipping which creates maximum number of consecutive 1’s in array.

// Examples :

// Input:   arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
//          m = 2
// Output:  5 7
// We are allowed to flip maximum 2 zeroes. If we flip
// arr[5] and arr[7], we get 8 consecutive 1's which is
// maximum possible under given constraints 

// Input:   arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
//          m = 1
// Output:  7
// We are allowed to flip maximum 1 zero. If we flip 
// arr[7], we get 5 consecutive 1's which is maximum 
// possible under given constraints.

// Input:   arr[] = {0, 0, 0, 1}
//          m = 4
// Output:  0 1 2
// Since m is more than number of zeroes, we can flip
// all zeroes.

#include<bits/stdc++.h>
using namespace std;

vector<int> zeroFlipping(int a[], int n, int m)
{
	int zeroCount = 0;
	vector<int> zeros;
	for(int i=0;i<n;i++)
	{
		if(!a[i])
			zeroCount++;
	}
	if(zeroCount <= m)
	{
		for(int i=0;i<n;i++)
		{
			if(!a[i])
				zeros.push_back(i);
		}
		return zeros;
	}
	zeroCount = 0;
	int start = 0, MAX = 0, l, r;
	for(int i=0;i<n;i++)
	{
		if(!a[i])
			zeroCount++;
		if(zeroCount > m)
		{
			while(a[start])
			{
				start++;
			}
			start++;
			zeroCount--;
		}
		if(i - start + 1 > MAX)
		{
			MAX = max(MAX, i - start + 1);
			l = start;
			r = i;
		}
	}
	for(int i=l;i<=r;i++)
	{
		if(!a[i])
			zeros.push_back(i);
	}
	return zeros;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	vector<int> zeros = zeroFlipping(a, n, m);
	for(int i=0;i<zeros.size();i++)
		cout << zeros[i] << ' ';
	cout << endl;
	return 0;
}