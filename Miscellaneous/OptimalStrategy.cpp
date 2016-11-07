#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
#define pb push_back

int maxMoney(vi &A, std::vector<vi> &dp, int i1, int i2)
{
	if(i1==i2)
		return A[i1];
	if(i1+1==i2)
		return max(A[i1], A[i2]);
	int n = A.size();
	if(dp[i1][i2]!= -1)
		return dp[i1][i2];
	int x=0, y=0, z=0;
	x = (i1+2<=i2)?(maxMoney(A,dp,i1+2,i2)):INT_MAX;
	y = (i1+1<=i2-1)?(maxMoney(A,dp, i1+1, i2-1)):INT_MAX;
	z = (i1<=i2-1)?(maxMoney(A,dp,i1,i2-2)):INT_MAX;
	dp[i1][i2] = max(A[i1] + min(x,y), A[i2] + min(y,z));
	return dp[i1][i2];
}

int main()
{
	int n;
	cin>>n;
	vi A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	std::vector<vi> dp(n, vi(n,-1));
	cout<<maxMoney(A, dp, 0, n-1)<<endl;
}