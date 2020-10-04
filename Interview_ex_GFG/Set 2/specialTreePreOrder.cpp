#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int x)
    {
    	data = x;
    	left = NULL;
    	right = NULL;
    }
};
TreeNode* specialTree(int pre[], char preln[], int *i, int n)
{
	if(*i==n)
		return NULL;
	TreeNode* root = new TreeNode(pre[*i]);
	if(preln[*i]=='L')
		return root;
	*i += 1;
	root->left = specialTree(pre, preln, i, n);
	*i += 1;
	root->right = specialTree(pre, preln, i, n);
	return root;	
}
void preorder(vector<int>& arr, TreeNode* root)
{
    if(!root)
        return;
    arr.push_back(root->data);
    preorder(arr, root->left);
    preorder(arr, root->right);
}
int main()
{
    int n;
    cin >> n;
    int pre[n];
    char preln[n];
    for(int i=0;i<n;i++)
    	cin >> pre[i];
    for(int i=0;i<n;i++)
    	cin >> preln[i];
    int i = 0;
    TreeNode* root = specialTree(pre, preln, &i, n);
   vector<int> arr;

    preorder(arr, root);
    // cout << arr.size();
    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}