#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>


struct node
{
	std::vector<pii> adj;
	int key = INT_MAX;
	int children = 0;
	int parent = -1;
};

string binary(unsigned long long n)
{
	string result = "";
	while(n!=0)
	{
		int d = n%2;
		char ch = '0';
		if(d==1) ch = '1';
		result = ch + result;
		n/=2;
	}
	return result;
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

int updateChildren(std::vector<node> &graph, int root)
{
	int n = graph[root].adj.size();
	std::vector<bool> visited(100000, 0);
	for(int i=0;i<n;i++)
	{
		int v = graph[root].adj[i].first;
		if(graph[v].parent==root && visited[v]==0)
		{
			graph[root].children+= updateChildren(graph, graph[root].adj[i].first)+1;
			visited[v] = 1;
		}
	}
	return graph[root].children;
}

struct compare
{
	bool operator()(pii l, pii r)
	{
		return l.second>r.second;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;
	std::vector<node> graph(n);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--; b--;
		graph[a].adj.pb(mp(b,c));
		graph[b].adj.pb(mp(a,c));
	}
	priority_queue <pii, std::vector<pii>, compare> Q;
	std::vector<int> inMST(n,0);
	Q.push(mp(0,0));
	graph[0].key = 0;
	while(Q.size()!=0)
	{
		pii u = Q.top();
		Q.pop();
		inMST[u.first]=1;
		for(int i=0;i<graph[u.first].adj.size();i++)
		{
			pii v = graph[u.first].adj[i];
			if(inMST[v.first]==0 && v.second<graph[v.first].key)
			{
				graph[v.first].key = v.second;
				graph[v.first].parent = u.first;
				Q.push(mp(v.first, graph[v.first].key));
			}
		}
	}
	updateChildren(graph, 0);
	std::vector<long long> cnt(200002, 0);
	int maxIndex = 0;
	for(int i=1;i<n;i++)
	{
		int c = graph[i].children+1;
		cnt[graph[i].key]+= (long long)c * (n - c);
		maxIndex = max(maxIndex, graph[i].key);
	}
	for(int i=0;i<=maxIndex;i++)
	{
		cnt[i+1]+= cnt[i]/2;
		cnt[i] = cnt[i]%2;
	}
	string newAns = "";
	for(int i=0;i<=maxIndex;i++)
	{
		if(cnt[i]==0)
			newAns = "0"+newAns;
		else
			newAns = "1"+newAns;
	}
	long long temp = cnt[maxIndex+1];
	while(temp!=0)
	{
		int t = temp%2;
		if(t==1)
			newAns = "1"+newAns;
		else
			newAns = "0"+newAns;
		temp/=2;
	}
	cout<<newAns<<endl;
}