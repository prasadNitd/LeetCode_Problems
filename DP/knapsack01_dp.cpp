#include<bits/stdc++.h>
using namespace std;
int memo[105][1005];
int n, w,i,j;
int knap_sack(vector<int>& wt, vector<int>& val)
{
    for(;i<n+1;i++)
    {
        for(j=0;j<w+1;j++)
        {
            if(i==0 || j==0)
                memo[i][j] = 0;
            else
            {
                if(wt[i-1] <= j)
                    memo[i][j] = max(val[i-1] + memo[i-1][j-wt[i-1]], memo[i-1][j]);
                else
                    memo[i][j] = memo[i-1][j];
            }
        }
    }
    return memo[n][W];
}
int main()
{
    cout << "Enter total no of items and max capacity of the knapSack::" << endl;
    cin >> n >> w;
    vector<int> val(n), wt(n);
    cout << "Enter value and weight of each item::" << endl;
    for(int i=0;i<n;i++)
        cin >> val[i] >> wt[i];
    cout << "Max profit with given capacity:: ";
    cout << knap_sack(wt, val) << endl;
    return 0;
}
