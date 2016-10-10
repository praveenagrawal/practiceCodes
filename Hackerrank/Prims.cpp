#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

struct edge
{
	int u;
	int v;
	int w;
};

struct node
{
	std::vector<int> adj;
	std::vector<int> w;
	int key = INT_MAX;
	int popped = false;
};

struct compare
{
  bool operator()(const node *l, const node *r)
  {
      return (l->key > r->key);
  }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin>>n>>m;
    std::vector<node> graph(n);
    priority_queue<node*,vector<node*>, compare > Q;
    for(int i=0;i<m;i++)
	{
		int x,y,r;
		cin>>x>>y>>r;
		x--; y--;
		graph[x].adj.push_back(y);
		graph[y].adj.push_back(x);
		graph[x].w.push_back(r);
		graph[y].w.push_back(r);
	}
	int s;
	cin>>s;
	s--;
	graph[s].key = 0;
	for(int i=0;i<n;i++)
		Q.push(&graph[i]);
	unsigned long long total = 0;
	while(Q.size()!=0)
	{
		node *u = Q.top();
		Q.pop();
		u->popped = true;
		if(u->key!=INT_MAX)
			total+=u->key;
		for(int i=0;i<u->adj.size();i++)
		{
			int v = u->adj[i];	
			if(graph[v].popped==false && (u->w[i] < graph[v].key))
				graph[v].key = 	u->w[i];																																																																														
		}
	}
	cout<<total;


    return 0;
}
