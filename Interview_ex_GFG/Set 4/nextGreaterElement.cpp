#include<bits/stdc++.h>
using namespace std;

void nextGreaterElement(int a[], int n)
{
	stack<int> st;
	for(int i=0;i<n;i++)
	{
		while(!st.empty() && a[st.top()] < a[i])
		{
			int x = st.top();
			st.pop();
			a[x] = a[i];
		}
	// 15 13 12 11 16 21 3
		st.push(i);
	}
	while(!st.empty())
	{
		int x = st.top();
		st.pop();
		a[x] = -1;
	}
}

int main()
{
	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];

	nextGreaterElement(a, n);

	for(int i=0;i<n;i++)
		cout << a[i] << ' ';
	cout << endl;

	return 0;
}