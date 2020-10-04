#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int data;
	TreeNode *left, *right;
};
TreeNode* insert(TreeNode* root, int val)
{
	TreeNode* temp = new TreeNode();
	temp->data = val;
	temp->left = temp->right = NULL;
	if(!root)
	{
		// temp->data = val;
		// temp->left = temp->right = NULL;
		// cout << "C ";
		return temp;
	}
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode* pr = q.front();
		q.pop();
		if(pr->left)
		{
			q.push(pr->left);
		}
		else
		{
			// cout << "L ";
			pr->left = temp;
			break;
		}
		if(pr->right)
		{
			q.push(pr->right);
		}
		else
		{
			// cout << "R ";
			pr->right = temp;
			break;
		}
	}
	return root;
}
void inorder(vector<int>& arr, TreeNode *root)
{
    if(root==NULL)
        return;
    inorder(arr, root->left);
    arr.push_back(root->data);
    inorder(arr, root->right);

}
int main()
{
	int n;
	TreeNode* root = NULL;
	while(1)
	{
		cin >> n;
		if(n<=0)
			break;
		root = insert(root, n);
	}
	vector<int> arr;
	inorder(arr, root);
	// cout << arr.size();
	for(int i=0;i<arr.size();i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}