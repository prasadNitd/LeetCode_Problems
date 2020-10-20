#include<bits/stdc++.h>
using namespace std;
int n;
struct jobs
{
    int deadline, profit, id;
};

bool cmp(jobs a, jobs b)
{
    return a.profit > b.profit;
}

int max_profit(jobs arr[], int maxDeadline)
{
    int deadArr[maxDeadline+1] = {0}, j = -1, ans = 0,i;

    sort(arr, arr+n, cmp);

    for(i=0;i<n;i++)
    {
        j = arr[i].deadline;
        while(j)
        {
            if(!deadArr[j])
            {
                deadArr[j] = arr[i].id;
                ans += arr[i].profit;
                break;
            }
            else
                j--;
        }
    }
    for(i=1;i<=maxDeadline;i++)
    {
        if(deadArr[i])
        {
            cout << deadArr[i] << ' ';
        }
    }
    cout << endl;
    return ans;
}

int main()
{
    cout << "Enter total no of job::" << endl;
    cin >> n;

    jobs arr[n];
    int maxDeadline = -1,i;
    cout << "Enter deadline and profit of each job::" << endl;
    for(i=0;i<n;i++)
    {
        cin >> arr[i].deadline >> arr[i].profit;
        arr[i].id = i+1;
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }
    cout << max_profit(arr, maxDeadline);
}
