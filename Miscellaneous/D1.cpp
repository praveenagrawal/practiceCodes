#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int minCost(string a, string b)
{
	int n = a.size();
	int m = b.size();
	std::vector<vector <ll>> L(n+1, std::vector<ll> (m+1,0));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				L[i][j] = 0;
			else if(a[i-1]==b[j-1])
				L[i][j] = L[i-1][j-1] + 2*(a[i-1]-'0');
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	return L[n][m];
}

int main()
{
	int t;
	cin>>t;
	string garbage;
	getline(cin, garbage);
	while(t--)
	{
		string a,b;
		getline(cin, a);
		getline(cin, b);
		ll total = 0;
		for(int i=0;i<a.size();i++)
			total+= a[i]-'0';
		for(int i=0;i<b.size();i++)
			total+= b[i]-'0';

		cout<<total-minCost(a,b)<<endl;
	}
}