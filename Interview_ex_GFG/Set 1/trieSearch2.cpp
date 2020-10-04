#include<bits/stdc++.h>
using namespace std;
class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode
    {
        bool isEnd;
        TrieNode* child[26];
        TrieNode()
        {
            isEnd = false;
            memset(child, NULL, sizeof child);
        }
    };
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* ptr = root;
        
        for(int i=0;i<word.length();i++)
        {
            if(!ptr->child[word[i]-'a'])
                ptr->child[word[i]-'a'] = new TrieNode();
            ptr = ptr->child[word[i]-'a'];
        }
        ptr->isEnd = true;
    }
    
bool searchWord(TrieNode* ptr, string word)
{
    for(int i=0;i<word.length();i++)
    {
        if(word[i]!='.')
        {
            if(!ptr->child[word[i]-'a'])
                return false;
            ptr = ptr->child[word[i]-'a'];
        }
        else
        {
            for(int j=0;j<26;j++)
            {
                if(ptr->child[j] && searchWord(ptr->child[j], word.substr(i+1)))
                    return true;
            }
            return false;
        }
    }
    return ptr->isEnd;
}
bool search(string word) 
{
    return searchWord(root, word);
}
};
    int main()
{
    Trie* obj = new Trie();
    obj->insert("hello");
    obj->insert("helloji");
    bool p1 = obj->search("hello");
    bool p2 = obj->search("he..o");
    if(p1)
        cout << "Found1\n";
    if(p2)
        cout << "Found2\n";
    // if(p3)
    //     cout << "Found3\n";
}