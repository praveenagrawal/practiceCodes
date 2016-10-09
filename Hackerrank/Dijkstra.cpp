#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

struct node
{
	std::vector<int> adj;
	std::vector<int> w;
	unsigned long long d = ULLONG_MAX;
};

void MinHeapify(std::vector<int> Q, int i, std::vector<node> &graph)
{
	int l = 2*i + 1;
	int r = 3*i;
	int min = i;
	int n = Q.size();
	if(l<n && graph[Q[l]].d < graph[Q[i]].d)
		min = l;
	if(r<n && graph[Q[r]].d < graph[Q[min]].d)
		min = r;
	if(min!=i)
	{
		int temp = Q[i];
		Q[i] = Q[min];
		Q[min] = temp;
		MinHeapify(Q, min, graph);
	}
}

int ExtractMin(std::vector<int> &Q, std::vector<node> &graph)
{
	int n = Q.size();
	if(n==0)
		return -1;
	int min = Q[0];
	Q[0] = Q[n-1];
	Q.erase(Q.end()-1);
	MinHeapify(Q, 0, graph);
	return min;
}

void Relax(int u, int v, std::vector<node> &graph, int w, std::vector<int> &Q)
{
	if(graph[v].d>graph[u].d + w)
	{
		graph[v].d = graph[u].d + w;
		while(v>=0 && graph[Q[v/2]].d > graph[Q[v]].d)
		{
			int temp = Q[v/2];
			Q[v/2] = Q[v];
			Q[v] = temp;
			v = v/2;
		}
	}
}

int main() 
{
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
			graph[x].adj.push_back(y);
			graph[x].w.push_back(r);
			graph[y].adj.push_back(x);
			graph[y].w.push_back(r);
		}
		int s;
		cin>>s;
		s--;
		graph[s].d = 0;
		std::vector<int> Q;
		Q.push_back(s);
		for(int i=0;i<n;i++)
		{
			if(i!=s)
				Q.push_back(i);
		}
		std::vector<int> S;
		while(Q.size()!=0)
		{
			int u = ExtractMin(Q, graph);
			S.push_back(u);
			for(int i=0;i<graph[u].adj.size();i++)
			{
				int v = graph[u].adj[i];
				Relax(u,v,graph, graph[u].w[i], Q);
			}
		}
		for(int i=0; i<n;i++)
		{
			if(graph[i].d==ULLONG_MAX)
				graph[i].d = -1;
			if(i!=s)
				cout<<graph[i].d<<" ";
		}
		cout<<endl;
	}
    return 0;
}
