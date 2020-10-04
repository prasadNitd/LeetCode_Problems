#include<bits/stdc++.h>
using namespace std;
bool isPermutation(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();

	if(len1 != len2)
		return false; // if length of both the strings are not equal, simply returning false.

	unordered_map<int, int> freq;

	for(int i=0;i<len1;i++)
	{
		freq[str1[i]] += 1; // storing frequency of each element in str1.
	}

	for(int i=0;i<len2;i++)
	{
		if(freq.find(str2[i])==freq.end() || freq[str2[i]]==0) // checking if frequency of each character in str2 is same as str1.
			return false;
		freq[str2[i]] -= 1;
	}
	return true; // if everything works fine till this point, returning true.
}
int main()
{
	string str1, str2; // input Strings.
	cin >> str1 >> str2; // Taking 2 inputs as strings.

	if(isPermutation(s1, s2)) // Calling check permutation function and checking if they are permutation of each other.
		cout << "Yes" << endl; // If they are permutation of each other, printing "Yes".
	else
		cout << "No" << endl; // Otherwise printing "No".
	return 0;
}
