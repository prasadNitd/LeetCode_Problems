#include<bits/stdc++.h>
using namespace std;
bool palindromePermutation(string str)
{
	int freq[26] = {0};

	for(int i=0;i<str.length();i++)
	{
		freq[str[i]-'a'] += 1;
	}
	bool oddFound = false;
	for(int i=0;i<26;i++)
	{
		if(freq[i]%2)
		{
			if(oddFound)
				return false;
			oddFound = true;
		}
	}
	return true;
}
int main()
{
	string s;
	cin >> s;

	if(palindromePermutation(s))
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}