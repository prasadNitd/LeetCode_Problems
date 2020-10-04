#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
string urlifyString(char str[])
{
	int spaces =0, i;
	for(i=0;str[i];i++)
	{
		if(str[i]==' ')
			spaces++;
	}
	while(str[i-1]==' ')
	{
		spaces--;
		i--;
	}
	int new_length = i + spaces*2+1;

	if(new_length > MAX)
		return "";
	int index = new_length - 1;
	str[index--] = '\0';
	for(int j=i-1;j>=0;j--)
	{
		if(str[j]==' ')
		{
			str[index] = '0';
			str[index-1] = '2';
			str[index-2] = '%';
			index -= 3;
		}
		else
		{
			str[index--] = str[j];
		}
	}
	return str;
}
int main()
{
	char s[MAX] = "Myself avinitd          ";
	//cin >> s;

	cout << urlifyString(s) << endl;
	return 0;
}