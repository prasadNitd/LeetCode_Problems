#include<bits/stdc++.h>
using namespace std;
bool checkstring(string s, vector<string>& dict)
{
	int m = dict.size();

	for(int i=0;i<m;i++)
	{
		if(dict[i]==s)
			return true;
	}
	return false;
}
bool wordBreak(string s, vector<string>& dict)
{
	int n = s.length();
	if(n==0)
		return true;

	bool DPtable[1005] = {false};

	for(int i=1;i<=n;i++)
	{
		if(!DPtable[i] && checkstring(s.substr(0, i), dict))
			DPtable[i] = true;

		if(DPtable[i])
		{
			if(i==n)
				return true;

			for(int j=i+1;j<=n;j++)
			{
				if(!DPtable[j] && checkstring(s.substr(i, j-i), dict))
					DPtable[j] = true;

				if(j==n && DPtable[j])
					return true;
			}
		}
	}
	return false;
}
int main()
{
	string str = "ilikesamsung";
	vector<string> dict = {"mobile","samsung","sam","sung","man","mango", 
                           "icecream","and","go","i","like","ice","cream"};
	cout << (wordBreak(str, dict)?"Yes\n":"No\n");
}