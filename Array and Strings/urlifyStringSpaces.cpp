#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
string create_urlify_string(char str[])
{
    int white_spaces=0, idx;
    for(idx=0;str[idx];idx++)
    {
        if(str[idx]==' ')
            white_spaces++;
    }
    while(str[idx-1]==' ')
    {
        white_spaces--;
        idx--;
    }
    int length = idx + white_spaces*2+1;

    if(length > MAX)
        return "";
    int index = length - 1;
    str[index--] = '\0';
    for(int j=idx-1;j>=0;j--)
    {
        if(str[j]==' ')
        {
            str[index] = '7';
            str[index-1] = '0';
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
    char str[MAX] = "This is my 2nd contribution at hactoberfest as ezaz039          ";
    //cin >> s;

    cout << create_urlify_string(str) << endl;
    return 0;
}
