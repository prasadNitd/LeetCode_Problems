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
void bottomview(TreeNode* root, map<int, int>& mp)
{
        if(!root)
            return;

       queue<TreeNode*> q;
       root->hd = 0;
       q.push(root);
       int hd = 0;
       while(!q.empty())
       {
       	TreeNode* temp = q.front();
       	q.pop();
       	hd = temp->hd;
       	mp[hd] = temp->data;

       	if(temp->left)
       	{
       		temp->left->hd = hd - 1;
       		q.push(temp->left);
       	}
       	if(temp->right)
       	{
       		temp->right->hd = hd + 1;
       		q.push(temp->right);
       	}
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
    map<int, int> mp;
    int maxDepth = 0;
    bottomview(root, mp);
    // cout << arr.size();
    for(auto i: mp)
    	arr.push_back(i.second);
    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}