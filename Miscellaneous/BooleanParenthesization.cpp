#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;
typedef std::vector<ll> vl;
typedef std::vector<vl> vll;

int trueCount(string symb, string op, int n)
{
	vll dpT(n, vl(n,0)), dpF(n, vl(n,0));
	for(int i=0;i<n;i++)
	{
		if(symb[i]=='T')
			dpT[i][i] = 1;
		else
			dpF[i][i] = 1;
	}
	for(int gap=1;gap<n;gap++)
	{
		for(int i=0, j=gap;j<n;i++, j++)
		{
			for(int g=0;g<gap;g++)
			{
				int k = i + g;
				ll tik = dpT[i][k] + dpF[i][k];
				ll tkj = dpT[k+1][j] + dpF[k+1][j];
				if(op[k]=='&')
				{
					dpT[i][j]+= dpT[i][k]*dpT[k+1][j];
					dpF[i][j]+= (tik*tkj) - (dpT[i][k]*dpT[k+1][j]);
				}
				else if(op[k]=='|')
				{
					dpT[i][j]+= (tik*tkj) - (dpF[i][k]*dpF[k+1][j]);
					dpF[i][j]+= dpF[i][k]*dpF[k+1][j];
				}
				else if(op[k]=='^')
				{
					dpT[i][j]+= dpF[i][k]*dpT[k+1][j] + dpT[i][k]*dpF[k+1][j];
					dpF[i][j]+= dpT[i][k]*dpT[k+1][j] + dpF[i][k]*dpF[k+1][j];
				}
			}
		}
	}
	return dpT[0][n-1]%1003;

}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n;
		cin>>s;
		string symb="";
		string op = "";
		int l = 0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='T' || s[i]=='F')
			{
				symb+=s[i];
				l++;
			}
			else op+=s[i];
		}
		cout<<trueCount(symb, op, l)<<endl;
	}
}