// We are given a sorted array, Find K closest elements to a given value
#include<bits/stdc++.h>
using namespace std;
int lowerBound(int arr[], int l, int r, int x)
{
     int mid;
    while(l<r)
    {
        mid = l + (r-l)/2;
        
        if(arr[mid]==x)
            return mid;
        if(arr[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return mid;
}
vector<int> kClosestElements(int arr[], int n, int k, int x)
{
    if(n<=1)
        return vector<int>{};
    int l, r, index;
    vector<int> ans;
    index = lowerBound(arr, 0, n-1, x);
    l = index-1;
    r = index;
    while(k--)
    {
        int leftElement = l>=0 ? arr[l] : 1e8;
        int rightElement = r<n ? arr[r] : 1e8;
        if(abs(leftElement-x) <= abs(rightElement - x))
            l--;
        else
            r++;
    }
    for(int i=l+1;i<r;i++)
        ans.push_back(arr[i]);
    return ans;
}
int main()
{
	int n, k, x;
	cin >> n >> k >> x;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	vector<int> ans = kClosestElements(a, n, k, x);
	// cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << ' ';
	cout << endl;
}