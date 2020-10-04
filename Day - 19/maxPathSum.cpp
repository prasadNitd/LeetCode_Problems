#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data, hd;
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
int maxSumPath(TreeNode* root, int *maxSum)
{
    if(!root)
        return 0;
    int leftSubTree = maxSumPath(root->left, maxSum);
    int rightSubTree = maxSumPath(root->right, maxSum);
    if(leftSubTree<0)
        leftSubTree = 0;
    if(rightSubTree<0)
        rightSubTree = 0;
    *maxSum = max(*maxSum, leftSubTree+rightSubTree+root->data);
    int maxm = max(leftSubTree, rightSubTree);
    return max(0, maxm+root->data);
}
int maxPathSum(TreeNode* root) 
{
    if(!root)
        return 0;
    int maxSum = INT_MIN;
    maxSumPath(root, &maxSum);
    return maxSum;
}
int main()
{
    int n;
    TreeNode* root = NULL;
    while(1)
    {
        cin >> n;
        if(n==0)
            break;
        root = insert(root, n);
    }
    cout << maxPathSum(root) << endl;
    return 0;
}