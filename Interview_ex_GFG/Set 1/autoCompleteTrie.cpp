#include<bits/stdc++.h>
using namespace std;
class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode
    {
        bool isEnd;
        TrieNode *child[26];
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
    bool isLastNode(TrieNode* root)
    {
        for(int i=0;i<26;i++)
        {
            if(root->child[i])
                return false;
        }
        return true;
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
    void autoCompleteRec(TrieNode* ptr, string query)
    {
        if(ptr->isEnd)
        {
            cout << query << endl;
        }
        if(isLastNode(ptr))
            return;

        for(int i=0;i<26;i++)
        {
            if(ptr->child[i])
            {
                query.push_back(97 + i);
                autoCompleteRec(ptr->child[i],query);
                query.pop_back();
            }
        }
    }
    void autoComplete(string prefix)
    {
        int n = prefix.length();
        TrieNode* ptr = root;
        for(int i=0;i<n;i++)
        {
            if(!ptr->child[prefix[i]-'a'])
                return;
            ptr = ptr->child[prefix[i]-'a'];
        }
        bool LastNode = isLastNode(ptr);
        bool isWord = ptr->isEnd;

        if(isWord && LastNode)
        {
            cout << prefix << endl;
            return;
        }
        if(!LastNode)
        {
            string query = prefix;
            autoCompleteRec(ptr, query);
        }
    }
};

int main()
{
    Trie* obj = new Trie();
    obj->insert("hello");
    obj->insert("dog");
    obj->insert("hell");
    obj->insert("cat");
    obj->insert("a");
    obj->insert("hel");
    obj->insert("help");
    obj->insert("helps");
    obj->insert("helping");
    // bool p1 = obj->search("helping");
    // bool p2 = obj->search("cat");
    // bool p3 = obj->startsWith("o");
    // if(p1)
    //     cout << "Found1\n";
    // if(p2)
    //     cout << "Found2\n";
    // if(p3)
    //     cout << "Found3\n";
    obj->autoComplete("hel");
    // bool p1 = obj->search("hello");
    // bool p2 = obj->search("hell");
    // bool p3 = obj->startsWith("h");
    // if(p1)
    //     cout << "Found1\n";
    // if(p2)
    //     cout << "Found2\n";
    // if(p3)
    //     cout << "Found3\n";
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */