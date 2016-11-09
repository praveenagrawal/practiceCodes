#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vii;

int minNum(int a, int b, int c)
{
	int minX = a;
	if(b<minX) minX = b;
	if(c<minX) minX = c;
	return minX;
}

int minOperations(string &s1, string &s2, int p, int q)
{
	vii dp(p+1, vi(q+1,0));
	for(int i=0;i<=p;i++)
	{
		for(int j=0;j<=q;j++)
		{
			if(i==0)
				dp[i][j] = j;
			else if(j==0)
				dp[i][j] = i;
			else if(s1[i-1]==s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1+ minNum(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[p][q];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int p,q;
		cin>>p>>q;
		string s1, s2;
		cin>>s1>>s2;
		cout<<minOperations(s1,s2,p,q)<<endl;
	}
}