/*
Find the K closest points to origin using Priority Queue
Given a list of n points on 2D plane, the task is to find the K (k < n) closest points to the origin O(0, 0).

Note: The distance between a point P(x, y) and O(0, 0) using the standard Euclidean Distance.

Examples:

Input: [(1, 0), (2, 1), (3, 6), (-5, 2), (1, -4)], K = 3
Output: [(1, 0), (2, 1), (1, -4)]
Explanation:
Square of Distances of points from origin are
(1, 0) : 1
(2, 1) : 5
(3, 6) : 45
(-5, 2) : 29
(1, -4) : 17
Hence for K = 3, the closest 3 points are (1, 0), (2, 1) & (1, -4).

Input: [(1, 3), (-2, 2)], K = 1
Output: [(-2, 2)]
Explanation:
Square of Distances of points from origin are
(1, 3) : 10
(-2, 2) : 8
Hence for K = 1, the closest point is (-2, 2).

Time Complexity: O(N + N * log(K))
Auxillary Space: O(N)
*/

#include<bits/stdc++.h>
using namespace std;
struct pairup
{
	int x, y;
};
struct compare
{
	bool operator()(pairup const& a, pairup const& b)
	{
		return a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y;
	}
};
vector<pairup> kClosestPoints(pairup points[], int n, int k)
{
	priority_queue<pairup, vector<pairup>, compare> pq;
	vector<pairup> ans;
	for(int i=0;i<n;i++)
	{
		pq.push(points[i]);

		if(pq.size() > k)
		{
			pq.pop();
		}
	}
	while(!pq.empty())
	{
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}
int main()
{
	int n, k;
	cin >> n >> k;
	pairup points[n];
	for(int i=0;i<n;i++)
		cin >> points[i].x >> points[i].y;
	vector<pairup> ans = kClosestPoints(points, n, k);
	for(int i=0;i<ans.size();i++)
		cout << ans[i].x << ' ' << ans[i].y << endl;
	return 0;
}