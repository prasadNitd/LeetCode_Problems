#include<bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
#define mod 1000000007
#define MAX 1000000000000000000
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
#define in insert
#define con continue
#define br break;
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppl pair<pair<ll,ll>,ll>
#define plp pair<ll,pair<ll,ll>>
#define mem(x,y) memset(x,y,sizeof(x))
#define lcm(a,b) (a*b)/__gcd(a,b)
#define inverse_cos(x) acos(x)
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define set_bit_count(x) __builtin_popcount(x)
#define leading_zero_count(x) __builtin_clz(x)
#define tailing_zero_count(x) __builtin_ctz(x)
#define str_rev(str) reverse(str.begin(),str.end())
#define loop(i,x,y) for(ll i=x;i<y;i++)
#define rloop(i,x,y) for(ll i=x-1;i>=y;i--)
int n;
struct TreeNode
{
    int data_value, hd;
    TreeNode *left_ptr, *right_ptr;
};
TreeNode* insert(TreeNode* root_node, int data_value)
{
    TreeNode* temp_node = new TreeNode();
    temp_node->data_value = data_value;
    temp_node->left_ptr = temp_node->right_ptr = NULL;
    if(!root_node)
        return temp_node;
    queue<TreeNode*> q;
    q.push(root_node);
    while(!q.empty())
    {
        TreeNode* ptr = q.front();
        q.pop();
        if(ptr->left_ptr)
            q.push(ptr->left_ptr);
        else
        {
            ptr->left_ptr = temp_node;
            break;
        }
        if(ptr->right_ptr)
            q.push(ptr->right_ptr);
        else
        {
            ptr->right_ptr = temp_node;
            break;
        }
    }
    return root_node;
}
bool symm(TreeNode* p, TreeNode* q)
{
    if(!p && !q)
        return true;
    if(!p || !q)
        return false;
    return (p->data_value==q->data_value) && symm(p->left_ptr, q->right_ptr) && symm(p->right_ptr, q->left_ptr);
}
bool check_is_symmetric(TreeNode* root_node) 
{
    if(!root_node)
        return true;
    return symm(root_node->left_ptr, root_node->right_ptr);
}
int main()
{
    TreeNode* root_node = NULL;
    while(1)
    {
        cin >> n;
        if(n==0)
            break;
        root_node = insert(root_node, n);
    }
    if(check_is_symmetric(root_node))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
