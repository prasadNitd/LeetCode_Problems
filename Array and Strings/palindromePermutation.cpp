#include<bits/stdc++.h>
using namespace std;
bool check_palindrome_permutation(string str)
{
    unordered_map<char,int> ump;
    for(auto s:str)
        ump[s]++;
    bool flag = false;
    for(auto x:ump)
    {
        if(x.second%2)
        {
            if(flag)
                return false;
            flag = true;
        }
    }
    return true;
}
int main()
{
    string str;
    cin >> str;

    if(check_palindrome_permutation(str))
        cout << "There is a palindrome permutation exist:: " << endl;
    else
        cout << "There is no palindrome permutation exist:: " << endl;
    return 0;
}
