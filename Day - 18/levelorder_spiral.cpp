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
void levelorder(vector<int>& arr, TreeNode* root)
{
    if(!root)
        return;
    deque<TreeNode*> q;
    q.push_back(root);
    bool flag = true;
    TreeNode* temp;
    while(!q.empty())
    {
        int sz = q.size();
        while(sz--)
        {
        	if(flag)
        	{
                temp = q.back();
                q.pop_back();
                if(temp->right)
                    q.push_front(temp->right);
                if(temp->left)
                    q.push_front(temp->left);
            }
            else
            {
            	temp = q.front();
                q.pop_front();
                if(temp->left)
                    q.push_back(temp->left);
                if(temp->right)
                    q.push_back(temp->right);
            }
            arr.push_back(temp->data);
        }
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
    vector<int> arr;
    levelorder(arr, root);
    // cout << arr.size();
    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}