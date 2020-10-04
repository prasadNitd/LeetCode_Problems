#include<bits/stdc++.h>
using namespace std;
bool uniqueCharacters(string str)
{
	int bit = 0;

	for(int i=0;i<str.length();i++)
	{
		int val = str[i] - 'a';
		if(bit & (1 << val))
			return false;
		bit |= (1 << val);
	}
	return true;
}
int main()
{
	string str;
	cin >> str;

	if(uniqueCharacters(str))
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}