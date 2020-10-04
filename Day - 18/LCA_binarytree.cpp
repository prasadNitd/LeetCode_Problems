
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
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) 
{
    if(!root)
        return NULL;
    
    if(p==root->data || q==root->data)
        return root;
    
    TreeNode* node1 = lowestCommonAncestor(root->left, p, q);
    TreeNode* node2 = lowestCommonAncestor(root->right, p, q);
    
    if(node1 && node2)
        return root;
    
    return (node1)?node1:node2;
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
    int p, q;
    cin >> p >> q;
    TreeNode *ans =  lowestCommonAncestor(root, p, q);
    if(!ans)
    	cout << "No LCA Found\n";
    else
    	cout << ans->data << endl;
    return 0;
}