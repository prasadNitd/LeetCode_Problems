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
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode* ptr = root;
        
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            if(ptr->child[ch-'a'])
                ptr = ptr->child[ch-'a'];
            else
                return false;
        }
        return ptr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        TrieNode* ptr = root;
        
        for(int i=0;i<prefix.length();i++)
        {
            char ch = prefix[i];
            if(ptr->child[ch-'a'])
                ptr = ptr->child[ch-'a'];
            else
                return false;
        }
        return true;
    }
};

int main()
{
    Trie* obj = new Trie();
    obj->insert("hello");
    obj->insert("helloji");
    bool p1 = obj->search("hello");
    bool p2 = obj->search("hell");
    bool p3 = obj->startsWith("h");
    if(p1)
        cout << "Found1\n";
    if(p2)
        cout << "Found2\n";
    if(p3)
        cout << "Found3\n";
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */