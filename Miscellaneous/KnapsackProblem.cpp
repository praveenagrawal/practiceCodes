#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
#define pb push_back

int maxValue(vi &val, vi &wt, int W)
{
	int n = val.size();
	std::vector<vi> dp(n+1, vi(W+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			dp[i][j] = dp[i-1][j];
			if(wt[i-1]<=j)
				dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
		}
	}
	return dp[n][W];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,W;
		cin>>n>>W;
		vi val(n), wt(n);
		for(int i=0;i<n;i++)
			cin>>val[i];
		for(int i=0;i<n;i++)
			cin>>wt[i];
		cout<<maxValue(val, wt, W)<<endl;
	}
}