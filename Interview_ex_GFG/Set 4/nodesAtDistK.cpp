#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
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
void printNodesKDown(TreeNode* root, int k)
{
    if(!root || k<0)
        return;
    if(k==0)
        ans.push_back(root->data);
    printNodesKDown(root->left, k-1);
    printNodesKDown(root->right, k-1);
}
int printNodesAtDistK(TreeNode* root, TreeNode* target, int k)
{
    if(!root)
        return -1;
    if(root==target)
    {
        printNodesKDown(root, k);
        return 0;
    }
    int left = printNodesAtDistK(root->left, target, k);
    if(left!=-1)
    {
        if(left+1==k)
            ans.push_back(root->data);
        else
            printNodesKDown(root->right, k-left-2);
        return left+1;
    }
    int right = printNodesAtDistK(root->right, target, k);
    if(right!=-1)
    {
        if(right+1==k)
            ans.push_back(root->data);
        else
            printNodesKDown(root->left, k-right-2);
        return right+1;
    }
    return -1;
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
{
    if(!root)
        return vector<int>{};
    printNodesAtDistK(root, target, K);
    return ans;
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
    int K;
    cin >> K;
    vector<int> ans = distanceK(root, root, K);
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}