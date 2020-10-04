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
void topview(vector<int>& arr, TreeNode* root, map<int, pair<int, int>>& mp, int hDist, int depth)
{
        if(!root)
            return;
        if(mp.count(hDist)==0 || mp[hDist].second>depth)
            mp[hDist] = {root->data, depth};
        topview(arr, root->left, mp, hDist-1, depth+1);
        topview(arr, root->right, mp, hDist+1, depth+1);
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
    map<int, pair<int, int>> mp;
    int curr = 0;
    topview(arr, root, mp, 0, 0);
    for(auto i: mp)
        arr.push_back(i.second.first);
    // cout << arr.size();
    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}