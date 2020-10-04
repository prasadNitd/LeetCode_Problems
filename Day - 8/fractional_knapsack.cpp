#include<bits/stdc++.h>
using namespace std;
struct product
{
	int value, weight;

	// Constructor
	//product(int value, int weight): value(value), weight(weight){}
};

bool compareItems(product a, product b)
{
	double r1 = (double)a.value/a.weight;
	double r2 = (double)b.value/b.weight;

	return r1 > r2;
}

int fractionalKnapsack(product arr[], int n, int capacity)
{
	sort(arr, arr+n, compareItems);
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i].weight<=capacity)
		{
			ans += arr[i].value;
			capacity -= arr[i].weight;
		}
		else
		{
			int temp = capacity*arr[i].value;
			ans += (temp/arr[i].weight);
			break;
		}
	}
	return ans;
}

int main()
{
	int capacity, n;
	cin >> capacity >> n;
	product arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i].value >> arr[i].weight;
	}

	cout << fractionalKnapsack(arr, n, capacity) << endl;
}