
    //       1
    //      / \
    //     2   3
    //    / \     
    //   4   5 
    // Ans: 3


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
int height(TreeNode* root)
{
	if(!root)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}
int diameterOfBinaryTree(TreeNode* root)
{
    if(!root)
        return 0;
    int leftSubTree = height(root->left);
    int rightSubTree = height(root->right);
    int dmtr = leftSubTree+rightSubTree;
    return max(max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)), dmtr);
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
    cout << diameterOfBinaryTree(root) << endl;;
    return 0;
}