
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
bool isSameTree(TreeNode* p, TreeNode* q) 
{
    if(!p && !q)
        return true;
    else if(!p || !q)
        return false;
    return (p->data==q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
int main()
{
    int n;
    TreeNode *root1 = NULL, *root2 = NULL;
    while(1)
    {
        cin >> n;
        if(n<=0)
            break;
        root1 = insert(root1, n);
    }
    while(1)
    {
        cin >> n;
        if(n<=0)
            break;
        root2 = insert(root2, n);
    }
    if(isSameTree(root1, root2))
    	cout << "Yes" << endl;
    else
    	cout << "No" << endl;
    return 0;
}