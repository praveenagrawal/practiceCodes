#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
#define pb push_back

void checkSubsetSum(vi &A, int sumTotal)
{
	int n = A.size();
	std::vector<vb> dp(n+1, vb(sumTotal+1, 0));
	for(int i=0;i<=n;i++)
		dp[i][0] = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sumTotal;j++)
		{
			dp[i][j] = dp[i-1][j];	//exclude
			if(A[i-1]<=j)
				dp[i][j] = dp[i][j] | dp[i-1][j-A[i-1]];
		}
	}
	if(dp[n][sumTotal]==1)
		cout<<"YES\n";
	else
		cout<<"NO\n";
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
		int sumTotal = 0;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
			sumTotal+=A[i];
		}
		if(sumTotal%2==1)
			cout<<"NO\n";
		else
			checkSubsetSum(A, sumTotal/2);
	}
}