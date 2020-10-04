// Minimum swap required to convert binary tree to binary search tree
// Given the array representation of Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child.
// The task is to find the minimum number of swap required to convert it into Binary Search Tree.

// Examples:

// Input : arr[] = { 5, 6, 7, 8, 9, 10, 11 }
// Output : 3
// Swap 1: Swap node 8 with node 5.
// Swap 2: Swap node 9 with node 10.
// Swap 3: Swap node 10 with node 7.
// So, minimum 3 swaps are required.


// Input : arr[] = { 1, 2, 3 }
// Output : 1
// After swapping node 1 with node 2.
// So, only 1 swap required.
// The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing order of their value.
// So, find the inorder traversal of the Binary Tree and store it in the array and try to sort the array. The minimum number of swap required to get the array sorted will be the answer.

// Time Complexity: O(n log n).
#include<bits/stdc++.h>
using namespace std;
struct valuePair
{
	int val, index;
};
bool compare(valuePair a, valuePair b)
{
	return a.val < b.val;
}
int minSwapsBTtoBST(int a[], int n)
{
	vector<valuePair> arr(n);
	for(int i=0;i<n;i++)
	{
		arr[i].val = a[i];
		arr[i].index = i;
	}

	sort(arr.begin(), arr.end(), compare);

	int ans = 0;
	for(int i=0;i<n;i++) 
	{
		if(i==arr[i].index)
			continue;

		swap(arr[i].val, arr[arr[i].index].val);
		swap(arr[i].index, arr[arr[i].index].index);

		if(i!=arr[i].index)
			i--;
		ans++;
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) // 1
		cin >> a[i];
	cout << minSwapsBTtoBST(a, n) << endl;
}