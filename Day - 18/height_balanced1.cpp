
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
bool balancedOrNot(TreeNode* root, int *height)
{
    int lh = 0, rh = 0;
    bool lTree = false, rTree = false;
    
    if(!root)
    {
        *height = 0;
        return true;
    }
    
    lTree = balancedOrNot(root->left, &lh);
    rTree = balancedOrNot(root->right, &rh);
    
    *height = max(lh, rh) + 1;
    
    if(abs(lh-rh)>=2)
        return false;
    else
        return lTree & rTree;
}
bool isBalanced(TreeNode* root) 
{
    if(!root)
        return true;
    int height = 0;
    return balancedOrNot(root, &height);
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
    if(isBalanced(root))
    	cout << "Yes" << endl;
    else
    	cout << "No" << endl;
    return 0;
}