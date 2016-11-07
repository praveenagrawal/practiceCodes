#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
#define pb push_back


int maxValue(vi &val, vi &wt, int n, int W, std::vector<vi> &dp)
{
	if(n==0 || W==0)
		return 0;
	if(dp[n][W]!=-1)
		return dp[n][W];
	dp[n][W] = maxValue(val, wt, n-1, W, dp);
	if(wt[n-1]<=W)
		dp[n][W] = max(dp[n][W], val[n-1] + maxValue(val, wt, n-1, W-wt[n-1], dp));
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
		std::vector<vi> dp(n+1, vi(W+1,-1));
		cout<<maxValue(val, wt, n, W, dp)<<endl;
	}
}