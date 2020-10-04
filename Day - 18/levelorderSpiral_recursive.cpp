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
void printEachLevel(TreeNode* root, int level, bool flag)
{
    if(!root)
        return;
    if(level==1)
        cout << root->data << ' ';
    else if(flag)
    {
        printEachLevel(root->left, level-1, flag);
        printEachLevel(root->right, level-1, flag);
    }
    else
    {
    	printEachLevel(root->right, level-1, flag);
        printEachLevel(root->left, level-1, flag);
    }
}
int findHeight(TreeNode* root)
{
    if(!root)
        return 0;
    return 1 + max(findHeight(root->left), findHeight(root->right));
}
void printLevelOrder(TreeNode* root)
{
    if(!root)
        return;
    bool flag = false;
    int height = findHeight(root);
    for(int i=1;i<=height;i++)
    {
        printEachLevel(root, i, flag);
        flag = !flag;
    }
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
    printLevelOrder(root);
    // cout << arr.size();
    cout << endl;
    return 0;
}