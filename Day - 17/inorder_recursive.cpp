#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int data;
	TreeNode *left, *right;
};
TreeNode* Tree_insert(TreeNode* root, int value)
{
	TreeNode* temp = new TreeNode();
	temp->data = value;
	temp->left = temp->right = NULL;
	if(!root)
	{
		// temp->data = value;
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
void inorder_traversal(vector<int>& arr, TreeNode *root)
{
    if(root==NULL)
        return;
    inorder_traversal(arr, root->left);
    arr.push_back(root->data);
    inorder_traversal(arr, root->right);

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
		root = Tree_insert(root, n);
	}
	vector<int> arr;
	inorder_traversal(arr, root);
	// cout << arr.size();
	for(int i=0;i<arr.size();i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}
