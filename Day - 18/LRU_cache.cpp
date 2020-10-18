#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    list<int> list1;
    unordered_map<int,int> ump;
    int n;
    LRUCache(int capacity) {
        this->n=capacity;
    }
    
    int get(int key) {
        
        if(ump.find(key)==ump.end())
            return -1;
        list1.remove(key);
        list1.push_back(key);
        return ump[key];
    }
    
    void put(int key, int value) {
        ump[key]=value;
        list1.remove(key);
        if(list1.size()==n)
        {
            ump.erase(list1.front());
            list1.pop_front();   
        }
        list1.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
	int n;
	cout << "Enter max capacity::" << endl;
	cin>>n;
	LRUCache l(n);
	while(1)
	{
		int key,type;
		cout << "Enter the key value and type of query(1 or 2)::" << endl;
		cin>>key>>type;
		if(type==1)
			cout << "Result of the query is:: " << l.get(key) << endl;
		else
		{
			int value;
			cout << "Enter the value that need to store at that key::" << endl;
			cin>>value;
			l.put(key,value);
		}
	}
}