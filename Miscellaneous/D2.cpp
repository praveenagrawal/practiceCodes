#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <limits.h>

using namespace std;

typedef vector <int> vi;
typedef pair<int, int> pii;	//<node, key>
typedef vector <pii> vpii;

#define pb push_back
#define mp make_pair

struct node
{
	vpii adj;
	int key = INT_MAX;
	int parent = -1;
};

struct compare
{
  bool operator()(const pair<int, int> l, const pair<int, int> r)
  {
      return (l.second > r.second);
  }
};

int main()
{
	int n,m;
	cin>>n>>m;
	std::vector<node> graph(n);
	for(int i=0;i<m;i++)
	{
		int u,v,cost;
		cin>>u>>v>>cost;
		if(cost==1)
			cin>>cost;
		u--; v--;
		graph[u].adj.pb(mp(v,cost));
		graph[v].adj.pb(mp(u,cost));
	}
	priority_queue <pii, vpii, compare> Q;
	vi inMST(n, 0);
	int s = 0;
	graph[s].key = 0;
	Q.push(mp(s,graph[s].key));
	while(Q.size()!=0)
	{
		pii u = Q.top();
		Q.pop();
		inMST[u.first] = 1;
		for(int i=0;i<graph[u.first].adj.size();i++)
		{
			pii v = graph[u.first].adj[i];
			if(inMST[v.first]==0 && graph[v.first].key> v.second)
			{
				graph[v.first].key = v.second;
				graph[v.first].parent = u.first;
				Q.push(mp(v.first, graph[v.first].key));
			}

		}
	}
	int minCost = 0;
	for(int i=0;i<n;i++)
	{
		if(graph[i].parent!=-1)
			minCost+=graph[i].key;
	}
	cout<<minCost;
}