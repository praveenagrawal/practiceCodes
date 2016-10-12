#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;


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
  bool operator()(const node l, const node r)
  {
      return (l.key > r.key);
  }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin>>n>>m;
    std::vector<node> graph(n);
    priority_queue<node,vector<node>, compare > Q;
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
	Q.push(graph[s]);
	unsigned long long total = 0;
	while(Q.size()!=0)
	{
		node u = Q.top();
		Q.pop();
		inMST[u.v] = 1;
		for(int i=0;i<u.adj.size();i++)
		{
			int v = u.adj[i];
			if(inMST[v]==0 && u.w[i]<graph[v].key)
			{
				graph[v].key = u.w[i];
				graph[v].parent = u.v;
				Q.push(graph[v]);
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
