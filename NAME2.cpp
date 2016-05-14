#include <iostream>
#include <string>
using namespace std;	

bool marriageable(string M, string W)
{
	int k=0;
	for(int i=0;i<M.length();i++)
	{
		if(M[i]==W[k])
			k++;
		if(k==W.length())
			return true;
	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string M,W;
		cin>>M;
		cin>>W;
		int k=0;
		bool result;
		if(M.length()>W.length())
			result = marriageable(M,W);
		else
			result = marriageable(W,M);
		if(result)
			cout<<"YES\n";
		else
			cout<<"NO\n";		
	}
}