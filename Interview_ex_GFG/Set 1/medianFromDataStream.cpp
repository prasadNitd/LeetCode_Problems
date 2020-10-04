// Find median from data stream

// Time Complexity: O(logN) // For each data
// Space Complexity: O(N)
#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int> maxHeap;// maxHeap
    priority_queue<int, vector<int>, greater<int>> minHeap; // minHeap
	int n;
	while(cin >> n)
	{
		if(n <= 0)
			break;

		// Adding number
		minHeap.push(n);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if(maxHeap.size() > minHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // Finding median
        if(minHeap.size() > maxHeap.size())
            cout << minHeap.top() << endl;
        else	
        	cout << (double)(minHeap.top()+maxHeap.top())/2 << endl;
	}
}