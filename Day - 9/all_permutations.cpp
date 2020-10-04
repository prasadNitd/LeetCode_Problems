#include<bits/stdc++.h>
using namespace std;
void printPer(string str, int l, int r)
{
	if(l==r)
		cout << str << endl;
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(str[i], str[l]);

			printPer(str, l+1, r);

			swap(str[i], str[l]);
		}
	}
}
int main()
{
	string str;
	cin >> str;
	int n = str.length();
	printPer(str, 0, n-1);
	return 0;
}