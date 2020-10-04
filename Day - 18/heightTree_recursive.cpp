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
int findHeight(TreeNode* root)
{
    if(!root)
        return 0;
    queue<TreeNode*> q;
    q.push(root);
    int height = 0;
    while(!q.empty())
    {
    	int sz = q.size();
    	while(sz--)
    	{
	    	TreeNode* temp = q.front();
	    	q.pop();
	    	if(temp->left)
	    		q.push(temp->left);
	    	if(temp->right)
	    		q.push(temp->right);
	    }
	    height++;
    }
    return height;
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
    cout << findHeight(root) << endl;;
    return 0;
}