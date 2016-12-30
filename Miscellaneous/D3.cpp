#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <limits.h>

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> pii;	//<node, key>
typedef pair<ull, ull> pll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;


struct cellA
{
	int c;
	int p;
};

ull minCost(vector <std::vector<cellA> > &gridA, std::vector<vpll> &dp, int n, int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0 && j==0)
				continue;
			if(i==0)
			{
				dp[i][j].first = dp[i][j-1].second + gridA[i][j].c + gridA[i][j].p;	//cost facing down
				dp[i][j].second = dp[i][j-1].second + gridA[i][j].c;	//cost facing right
			}
			else if(j==0)
			{
				dp[i][j].first = dp[i-1][j].first + gridA[i][j].c;
				dp[i][j].second = dp[i-1][j].first + gridA[i][j].c + gridA[i][j].p;
			}
			else
			{
				ull val1, val2, val3, val4;
				ull minVal;

				val1 = dp[i][j-1].first + gridA[i][j-1].p + gridA[i][j].c + gridA[i][j].p;
				minVal = val1;
				val2 = dp[i][j-1].second + gridA[i][j].c + gridA[i][j].p;
				if(val2<minVal) minVal = val2;
				val3 = dp[i-1][j].first + gridA[i][j].c;
				if(val3<minVal) minVal = val3;
				val4 = dp[i-1][j].second + gridA[i-1][j].p + gridA[i][j].c;
				if(val4<minVal) minVal = val4;

				dp[i][j].first = minVal;	//cost facing down

				val1 = dp[i][j-1].first + gridA[i][j-1].p + gridA[i][j].c;
				minVal = val1;
				val2 = dp[i][j-1].second + gridA[i][j].c;
				if(val2<minVal) minVal = val2;
				val3 = dp[i-1][j].first + gridA[i][j].c + gridA[i][j].p;
				if(val3<minVal) minVal = val3;
				val4 = dp[i-1][j].second + gridA[i-1][j].p + gridA[i][j].c + gridA[i][j].p;
				if(val4<minVal) minVal = val4;

				dp[i][j].second = minVal;	//cost facing right
			}
		}
	}
	return min(dp[n-1][m-1].first, dp[n-1][m-1].second);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector <std::vector<cellA> > gridA(n, vector <cellA> (m));
		std::vector<vpll> dp(n, vpll(m));	//<cost down, cost right>
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>gridA[i][j].c;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>gridA[i][j].p;
		}
		dp[0][0].first = gridA[0][0].c;
		dp[0][0].second = gridA[0][0].c;
		cout<<minCost(gridA,dp, n, m)<<endl;
	}
}