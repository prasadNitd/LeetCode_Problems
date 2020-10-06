// TOP DOWN DP with Recusrion + Memoization

#include<bits/stdc++.h>
using namespace std;
wordBreak(String s, List<String> wordDict) {
         int[][] dp = new int[s.length()][s.length()];
        boolean[][] visited = new boolean[s.length()][s.length()];
        for (int i = 0;i < s.length(); i++)
             Arrays.fill(dp[i], -1);

        int val = isPossibleBreak(visited, dp, s, 0, s.length()-1, wordDict);
        if(val == 1)
            return true;
        return false;
        
    }
    
    private int isPossibleBreak(boolean[][] visited, int[][] dp , String str, int low, int high , List<String> wordDict){

        if(low > high)
            return 1;

        if(wordDict.contains(str.substring(low, high+1)))
            return 1;

        if(low == high)
            return 0;

        if(dp[low][high] != -1)
            return dp[low][high];

        if(visited[low][high]){
            if(wordDict.contains(str.substring(low, high+1)))
                return 1;
            return 0;
        }

        visited[low][high] = true;
        int val =0;
        for (int i =low; i <= high; i++){
            int p1 = isPossibleBreak(visited, dp, str, low, i, wordDict);
            int p2 = isPossibleBreak(visited, dp, str, i+1, high, wordDict);
            if(p1 == 1 && p2 == 1){
                val = 1;
                break;
            }
        }
        dp[low][high] = val;
        return dp[low][high];
    }
int main()
{
    string str = "ilikesamsung";
    vector<string> dict = {"mobile","samsung","sam","sung","man","mango", 
                           "icecream","and","go","i","like","ice","cream"};
    cout << (wordBreak(str, dict)?"Yes\n":"No\n");
}
