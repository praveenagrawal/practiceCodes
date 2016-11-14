#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vi> vii;
typedef std::vector<vii> viii;

#define INF 9999999

void compareW(viii &graph, int i, int j, int k, int n)
{
	unsigned long long temp1 = 0, temp2 = 0, temp3 = 0;
	for(int it = 0;it<graph[i][j].size();it++)
		temp1+=pow(2,graph[i][j][it]);
	for(int it = 0;it<graph[i][k].size();it++)
		temp2+=pow(2,graph[i][k][it]);
	for(int it = 0;it<graph[k][j].size();it++)
		temp3+=pow(2,graph[k][j][it]);
	if(temp1>temp2+temp3 || graph[i][j][0]==INF)
	{
		graph[i][j].clear();
		for(int it = 0;it<graph[i][k].size();it++)
			graph[i][j].push_back(graph[i][k][it]);
		for(int it = 0;it<graph[k][j].size();it++)
			graph[i][j].push_back(graph[k][j][it]);
	}
}

void joinS(string &s, string &t)
{
	if(s.size()<t.size())
	{
		int temp = t.size()-s.size();
		for(int j=0;j<temp;j++)
			s='0' + s;
		s[0] = '1';
	}
	else
	{
		int i = t.size();
		int n = s.size();
		int k = n-i;
		int c = 1;
		for(int l=k;l>=0 && c==1;l--)
		{
			if(s[l]=='1')
			{
				if(c==1)
				{
					c = 1;
					s[l] = '0';
				}
				else
				{
					c = 0;
					s[l] = '1';
				}
			}
			else
			{
				if(c==1)
				{
					c = 0;
					s[l]='1';
				}
			}
		}
		if(c==1)
			s = "1"+s;
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin>>n>>m;
    vi temp;
    temp.push_back(INF);
    viii graph(n, vii(n, temp));
    /*temp.clear();
    temp.push_back(0);
    for(int i=0;i<n;i++)
	{
		graph[i][i] = temp;
	}*/
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--; b--; 
		if(graph[a][b][0]>c)
		{
			graph[a][b][0] = c;
			graph[b][a][0] = c;
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i!=j && graph[i][k][0]!=INF && graph[k][j][0]!=INF)
					compareW(graph, i, j, k, n);
			}
		}
	}
	vi result;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(j!=i)
			{
				for(int k=0;k<graph[i][j].size();k++)
					result.push_back(graph[i][j][k]);
			}
		}
	}
	string ans = "0";
	unsigned long long ans1 = 0;
	for(int i=0;i<result.size();i++)
	{
		string temp = "1";
		for(int j=0;j<result[i];j++)
			temp+= "0";
		//ans1+= pow(2, result[i]);
		joinS(ans, temp);
	}
	cout<<ans<<endl;
    return 0;
}
