#include<bits/stdc++.h>
using namespace std;
bool palindromePermutation(string str)
{
	int bit = 0;

	for(int i=0;i<str.length();i++)
	{
		int mask = str[i]-'a';
		mask = 1 << mask;
		if((bit & mask)==0)
			bit |= mask;
		else
			bit &= ~mask;
	}
	return bit & (bit - 1);
}
int main()
{
	string s;
	cin >> s;

	if(!palindromePermutation(s))
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}