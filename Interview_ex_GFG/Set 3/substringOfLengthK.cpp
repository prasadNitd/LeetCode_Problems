

// Given a string str of lowercase alphabets and an integer K, the task is to count all substrings of length K which have exactly K distinct characters.

// Count of substrings of length K with exactly K distinct characters

/*
Example:
Input: str = “abcc”, K = 2
Output: 2
Explanation:
Possible substrings of length K = 2 are
ab : 2 distinct characters
bc : 2 distinct characters
cc : 1 distinct character
Only two valid substrings exist {“ab”, “bc”}.

Input: str = “aabab”, K = 3
Output: 0
Explanation:
Possible substrings of length K = 3 are
aab : 2 distinct characters
aba : 2 distinct characters
bab : 2 distinct characters
No substrings of length 3 exists with exactly 3 distinct characters
*/
// C++ program to find the 
// count of k length substrings 
// with k distinct characters 
// using sliding window 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the 
// required count of substrings 
int countSubstrings(string str, int K) 
{ 
    int N = str.size(); 
    // Store the count 
    int answer = 0; 

    // Store the count of 
    // distinct characters 
    // in every window 
    unordered_map<char, int> map; 

    // Store the frequency of 
    // the first K length substring 
    for (int i = 0; i < K; i++) { 

        // Increase frequency of 
        // i-th character 
        map[str[i]]++; 
    } 

    // If K distinct characters 
    // exist 
    if (map.size() == K) 
        answer++; 

    // Traverse the rest of the 
    // substring 
    for (int i = K; i < N; i++) { 

        // Increase the frequency 
        // of the last character 
        // of the current substring 
        map[str[i]]++; 
        // Decrease the frequency 
        // of the first character 
        // of the previous substring 
        map[str[i - K]]--; 

        // If the character is not present 
        // in the current substring 
        if (map[str[i - K]] == 0) { 
            map.erase(str[i - K]); 
        } 

        // If the count of distinct 
        // characters is 0 
        if (map.size() == K) { 
            answer++; 
        } 
    } 

    // Return the count 
    return answer; 
} 

// Driver code 
int main() 
{ 
    // string str 
    string str = "aabcdabbcdc"; 

    // integer K 
    int K = 3; 

    // Print the count of K length 
    // substrings with k distinct characters 
    cout << countSubstrings(str, K) << endl; 

    return 0; 
} 
