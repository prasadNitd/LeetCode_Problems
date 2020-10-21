#include<bits/stdc++.h>
using namespace std;
bool compareItems(tuple<int,int> a, tuple<int,int> b)
{
	double r1 = (double)get<0>(a)/get<1>(a);
	double r2 = (double)get<0>(b)/get<1>(b);

	return r1 > r2;
}
int fractionalKnapsack(vector<tuple<int,int>> product, tuple<int,int> cnt)
{
	sort(product.begin(),product.end(),compareItems);
	tuple<int,int,int> ans;
	for(get<1>(ans)=0;get<1>(ans)<get<0>(cnt);get<1>(ans)++)
	{
		if(get<1>(product[get<1>(ans)])<=get<0>(cnt))
		{
			get<0>(ans) += get<0>(product[get<1>(ans)]);
			get<0>(cnt) -= get<1>(product[get<1>(ans)]);
		}
		else
		{
			get<2>(ans) = get<1>(cnt)*get<0>(product[get<1>(ans)]);
			get<0>(ans) += (get<0>(ans)/get<1>(product[get<1>(ans)]));
			break;
		}
	}
	return get<0>(ans);
}

int main()
{
	tuple<int,int> cnt;
	cin >> get<0>(cnt) >> get<1>(cnt);
	vector<tuple<int,int>> product;
	for(int i=0;i<get<0>(cnt);i++)
	{
		tuple<int,int> v;
		cin>>get<0>(v)>>get<1>(v);
		product.push_back({get<0>(v),get<1>(v)});
	}

	cout << fractionalKnapsack(product,cnt) << endl;
}
