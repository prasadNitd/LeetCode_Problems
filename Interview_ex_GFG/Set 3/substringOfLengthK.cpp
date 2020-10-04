// Count of substrings of length K with exactly K distinct characters

// Given a string str of lowercase alphabets and an integer K, the task is to count all substrings of length K which have exactly K distinct characters.

/*
Example:
Input: str = “abcc”, K = 2
Output: 2
Explanation:
Possible substrings of length K = 2 are
ab : 2 distinct characters
bc : 2 distinct characters
cc : 1 distinct character
Only two valid substrings exist {“ab”, “bc”}.

Input: str = “aabab”, K = 3
Output: 0
Explanation:
Possible substrings of length K = 3 are
aab : 2 distinct characters
aba : 2 distinct characters
bab : 2 distinct characters
No substrings of length 3 exists with exactly 3 distinct characters
*/

#include<bits/stdc++.h>
using namespace std;

int countSubstrings(string str, int k)
{
	int n = str.length(), count = 0, distinctCount = 0, j = 0;
	int freq[26] = {0};

	for(int i=0;i<k;i++)
	{
		freq[str[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(freq[i])
			distinctCount++;
	}
	if(distinctCount==k)
		count++;
	for(int i=k;i<n;i++)
	{
		if(freq[str[j]-'a']==1)
			distinctCount--;
		freq[str[j]-'a']--;
		if(freq[str[i]-'a']==0)
			distinctCount++;
		freq[str[i]-'a']++;
		if(distinctCount==k)
			count++;
		j++;
	}
	return count;
}

int main()
{
	string str;
	cin >> str;
	int k;
	cin >> k;
	cout << countSubstrings(str, k) << endl;
	return 0;
}