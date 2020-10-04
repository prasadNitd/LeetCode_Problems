#include<bits/stdc++.h>
using namespace std;
bool oneAwayString(string str1, string str2)
{
	int i = 0, j = 0;
	int n = str1.length();
	int m = str2.length();
	bool foundDiff = false;
	while(i < n && j < m)
	{
		if(str1[i] != str2[j])
		{
			if(foundDiff)
				return false;
			foundDiff = true;
			if(n==m)
				i++;
		}
		else
			i++;
		j++;
	}
	return true;
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	if(oneAwayString(s1, s2))
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}