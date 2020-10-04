#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(int a[], int n)
{
	vector<int> ans(n);
	stack<int> st;
	for(int i=n-1;i>=0;i--)
	{
		while(!st.empty() && st.top() <= a[i])
			st.pop();

		if(st.empty())
			ans[i] = -1;
		else
			ans[i] = st.top();
	// 15 13 12 11 16 21 3
		st.push(a[i]);
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

	vector<int> ans = nextGreaterElement(a, n);

	for(int i=0;i<n;i++)
		cout << ans[i] << ' ';
	cout << endl;

	return 0;
}