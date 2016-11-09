#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

typedef long long ll;

typedef pair<int,ll> iPair;

struct node
{
	std::vector<iPair> adj;	//<node, weight>
	ll key = LLONG_MAX;
};

struct compare
{
	bool operator()(iPair l, iPair r)
	{
		return l.second > r.second;
	}
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		int n,m;
		cin>>n>>m;
		std::vector<node> graph(n);
		for(int i=0;i<m;i++)
		{
			int x,y,r;
			cin>>x>>y>>r;
			x--; y--;
			graph[x].adj.push_back(make_pair(y,r));
			graph[y].adj.push_back(make_pair(x,r));
		}
		int s;
		cin>>s;
		s--;
		priority_queue<iPair, std::vector<iPair> , compare> Q;
		std::vector<bool> S(n,0);
		graph[s].key = 0;
		Q.push(make_pair(s,graph[s].key));
		while(Q.size()!=0)
		{
			int u = Q.top().first;
			Q.pop();
			S[u] = 1;
			for(int i=0;i<graph[u].adj.size();i++)
			{
				int v = graph[u].adj[i].first;
				ll w = graph[u].adj[i].second;
				if(graph[v].key>graph[u].key + w && S[v]==0)
				{
					graph[v].key = graph[u].key+w;
					Q.push(make_pair(v, graph[v].key));
				}

			}
		}
		for(int i=0;i<n;i++)
		{
			if(graph[i].key==LLONG_MAX)
				graph[i].key = -1;
			if(i!=s)
				cout<<graph[i].key<<" ";
		}
		cout<<endl;
	}
    return 0;
}
