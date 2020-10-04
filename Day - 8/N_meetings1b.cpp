// Given a list of N meetings, determine the max. no. of meetings that can be held in a single room....
#include<bits/stdc++.h>
#define lli long long int
using namespace std;
struct meeting
{
	int start, end;
};
bool compareSchedule(meeting a, 
              meeting b) 
{ 
    return (a.end < b.end); 
} 
int maxMeeetings(meeting schedule[], int n)
{
  sort(schedule, schedule+n, compareSchedule);
      int maxMeet = 1, j = 0;
      // ans.push_back({schedule[0].start, schedule[0].end});
      for(int i=1;i<n;i++)
      {
        if(schedule[i].start>schedule[j].end)
        {
            // ans.push_back({schedule[i].start, schedule[i].end});
            maxMeet += 1;
            j = i;
        }
      }
      return maxMeet;
}
int main()
{
      int n, e, s;
      cin >> n;
      // vector<pair<int, int>> ans;
      meeting schedule[n];
      if(n<=0)
        return 0;
      for(int i=0;i<n;i++)
      {
        cin >> schedule[i].start >> schedule[i].end;
        // meeting.push_back({s, e});
      }
      cout << maxMeeetings(schedule, n) << endl;
      // ort(meeting.begin(), meeting.end(), sortbysec);
      // sort(schedule, schedule+n, compareSchedule);
      // int maxMeet = 1, j = 0;
      // ans.push_back({schedule[0].start, schedule[0].end});
      // for(int i=1;i<n;i++)
      // {
      //   if(schedule[i].start>schedule[j].end)
      //   {
      //       ans.push_back({schedule[i].start, schedule[i].end});
      //       maxMeet += 1;
      //       j = i;
      //   }
      // }
      // cout << maxMeet << endl;
      // for(int i=0;i<ans.size();i++)
      // {
      //   cout << ans[i].first << ' ' << ans[i].second << endl;
      // }
      return 0;
}