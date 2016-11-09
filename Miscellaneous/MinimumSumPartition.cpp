#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
#define pb push_back

int minDiff(vi &A)
{
	int n = A.size();
	int sumTotal = 0;
	for(int i=0;i<n;i++)
		sumTotal+=A[i];
	std::vector<vb> dp(n+1, vb(sumTotal+1,0));
	for(int i=0;i<=n;i++)
		dp[i][0] = 1;
	for(int i=1;i<=n;i++)
	{
		;
		for(int j=1;j<=sumTotal;j++)
		{
			//exclude
			dp[i][j] = dp[i-1][j];
			//include
			if(A[i-1]<=j)
				dp[i][j]= dp[i][j] | dp[i-1][j-A[i-1]];
		}
	}
	for(int i=sumTotal/2;i>=0;i--)
	{
		if(dp[n][i]==1)
			return abs(sumTotal-2*i);
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vi A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		cout<<minDiff(A)<<endl;
	}
}