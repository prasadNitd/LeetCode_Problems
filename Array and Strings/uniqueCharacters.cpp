#include<bits/stdc++.h>
using namespace std;
bool uniqueCharacters(string str)
{
	unordered_map<char,int> ump;
	for(auto s:str)
	{
		if(ump.find(s)!=ump.end())
			return false;
		else
			ump.insert({s,1});
	}
	return true;
}
int main()
{
	string str;
	cin >> str;

	if(uniqueCharacters(str))
		cout << "The string contain all unique characteres:: " << endl;
	else
		cout << "The string doesn't contain all unique characteres:: " << endl;
	return 0;
}
