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
void topview(vector<int>& arr, TreeNode* root, map<int, int>& mp, int curr)
{
        if(!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        int hd = 0;
        root->hd = hd;

        while(!q.empty())
        {
        	TreeNode* temp = q.front();
        	q.pop();
        	hd = temp->hd;

        	if(mp.find(hd)==mp.end())
        	{
        		mp[hd] = temp->data;
        	}
        	if(temp->left)
        	{
        		temp->left->hd = hd-1;
        		q.push(temp->left);
        	}
        	if(temp->right)
        	{
        		temp->right->hd = hd+1;
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
    int curr = 0;
    topview(arr, root, mp, curr);
    for(auto i: mp)
    	arr.push_back(i.second);
    // cout << arr.size();
    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}