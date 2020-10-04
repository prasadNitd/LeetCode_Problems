#include<bits/stdc++.h>
using namespace std;
bool isPermutation(string str1, string str2)
{
	int n1 = str1.length();
	int n2 = str2.length();

	if(n1 != n2)
		return false;

	unordered_map<int, int> freq;

	for(int i=0;i<n1;i++)
	{
		freq[str1[i]] += 1;
	}

	for(int i=0;i<n2;i++)
	{
		if(freq.find(str2[i])==freq.end() || freq[str2[i]]==0)
			return false;
		freq[str2[i]] -= 1;
	}
	return true;
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	if(isPermutation(s1, s2))
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}