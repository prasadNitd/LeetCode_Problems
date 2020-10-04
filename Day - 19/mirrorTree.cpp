#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data, hd;
    TreeNode *left, *right;
};
TreeNode* insert(TreeNode* root, int data)
{
    TreeNode* temp = new TreeNode();
    temp->data = data;
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
bool symm(TreeNode* p, TreeNode* q)
{
    if(!p && !q)
        return true;
    if(!p || !q)
        return false;
    return (p->data==q->data) && symm(p->left, q->right) && symm(p->right, q->left);
}
bool isSymmetric(TreeNode* root) 
{
    if(!root)
        return true;
    return symm(root->left, root->right);
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
    cout << (isSymmetric(root)? "Yes":"No") << endl;
    return 0;
}