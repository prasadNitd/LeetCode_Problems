// Given a list of N meetings, determine the max. no. of meetings that can be held in a single room....
#include<bits/stdc++.h>
#define lli long long int
using namespace std;
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
int main()
{
      int n, e, s;
      cin >> n;
      vector<pair<int, int>> meeting, ans;
      if(n<=0)
        return 0;
      for(int i=0;i<n;i++)
      {
        cin >> s >> e;
        meeting.push_back({s, e});
      }
      sort(meeting.begin(), meeting.end(), sortbysec);
      int maxMeet = 1, j = 0;
      ans.push_back({meeting[0].first, meeting[0].second});
      for(int i=1;i<n;i++)
      {
        if(meeting[i].first>=meeting[j].second)
        {
            ans.push_back({meeting[i].first, meeting[i].second});
            maxMeet += 1;
            j = i;
        }
      }
      cout << maxMeet << endl;
      for(int i=0;i<ans.size();i++)
      {
        cout << ans[i].first << ' ' << ans[i].second << endl;
      }
      return 0;
}