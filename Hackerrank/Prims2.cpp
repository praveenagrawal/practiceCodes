#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> ipair;

struct node
{
	int v;
	std::vector<int> adj;
	std::vector<int> w;
	int key = INT_MAX;
	int parent=-1;
};

struct compare
{
  bool operator()(const pair<int, int> l, const pair<int, int> r)
  {
      return (l.second > r.second);
  }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin>>n>>m;
    std::vector<node> graph(n);
    priority_queue<ipair,vector<ipair>, compare > Q;
    std::vector<bool> inMST(n, 0);
    for(int i=0;i<m;i++)
	{
		int x,y,r;
		cin>>x>>y>>r;
		x--; y--;
		graph[x].adj.push_back(y);
		graph[y].adj.push_back(x);
		graph[x].w.push_back(r);
		graph[y].w.push_back(r);
		graph[x].v = x;
		graph[y].v = y;
	}
	int s;
	cin>>s;
	s--;
	graph[s].key = 0;
	Q.push(make_pair(s, graph[s].key));
	unsigned long long total = 0;
	while(Q.size()!=0)
	{
		int u = Q.top().first;
		Q.pop();
		inMST[u] = 1;
		for(int i=0;i<graph[u].adj.size();i++)
		{
			int v = graph[u].adj[i];
			if(inMST[v]==0 && graph[u].w[i]<graph[v].key)
			{
				graph[v].key = graph[u].w[i];
				graph[v].parent = graph[u].v;
				Q.push(make_pair(v, graph[v].key));
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(graph[i].parent!=-1)
			total+=graph[i].key;
	}
	cout<<total;


    return 0;
}
